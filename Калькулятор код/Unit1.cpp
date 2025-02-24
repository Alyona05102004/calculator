//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <stack>
#include <iomanip>
#include <queue>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;

TForm1 *Form1;
UnicodeString full = ""; //full expression

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::number_click(TObject *Sender)
{ TButton *button = dynamic_cast<TButton*>(Sender);
        UnicodeString number = button->Caption;

        if (Label1->Caption == "0" && number != ",") {
            Label1->Caption = number;
        } else {
            if (number == ",") {
                // ���������, ���� �� ��� ������� � ������� �����
                if (Pos(",", Label1->Caption) == 0) {
                    Label1->Caption += number;
                }
            } else {
                Label1->Caption += number;
            }
		}

 /*
//create method for edding numbers
	 TButton *button = dynamic_cast<TButton*>(Sender);

    // ���� ������� �������� ����� "0", �������� ��� �� ����� �����
    if (Label1->Caption == "0") {
        Label1->Caption = button->Caption;
    } else {
        Label1->Caption += button->Caption; // ��������� � �������� �����
    }

    // ��������� ����� � ������ ��������� ������ ���� ��� �� ��������
    if (full.IsEmpty() || full[full.Length()] == '+' || full[full.Length()] == '-' || full[full.Length()] == '*' || full[full.Length()] == '/') {
        full += button->Caption; // ��������� ����� � ������ ���������
    }
	   */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_delClick(TObject *Sender)
{
//delenie
	math_action('/');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_umnojClick(TObject *Sender)
{
//umnojenie
	math_action('*');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_subClick(TObject *Sender)
{
//minus
	math_action('-');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_sumClick(TObject *Sender)
{
//plus
    math_action('+');
}
//---------------------------------------------------------------------------
void __fastcall TForm1::math_action(char action)
{ /*// ��������� �������� ������ ���� ��������� �� �������� ���� ��������
    if (!full.IsEmpty() && (full[full.Length()] != '+' && full[full.Length()] != '-' && full[full.Length()] != '*' && full[full.Length()] != '/')) {
        full += action; // ��������� ��������
    } else if (full.IsEmpty()) {
        full = Label1->Caption; // ��������� ������ �����
        full += action; // ��������� ��������
    }
	Label1->Caption = full; // ��������� ����������� */
    UnicodeString currentText = Label1->Caption;
    if (currentText.Length() > 0 &&
        currentText[currentText.Length() - 1] != '+' &&
        currentText[currentText.Length() - 1] != '-' &&
        currentText[currentText.Length() - 1] != '*' &&
        currentText[currentText.Length() - 1] != '/') {
        Label1->Caption += action;
    }
}

void __fastcall TForm1::btn_equalClick(TObject *Sender)
{ /*
   if (full.IsEmpty()) {
        return;
    }


    float result = evaluateExpression(full);
    full += "=" + FloatToStr(result);
    Label1->Caption = full;

	full = "";   */
	UnicodeString expressionUnicode = Label1->Caption;
    AnsiString ansiExpression = AnsiString(expressionUnicode);
    std::string expression = ansiExpression.c_str();

    try {
        float result = evaluateExpression(expressionUnicode);

        // ����������� ��������� � ������
        std::ostringstream out;
        out << std::fixed << result; // ���������� fixed ��� ����������� ����� � ��������� �������

        std::string resultStr = out.str();

        // ������� ������ ����
        if (resultStr.find('.') != std::string::npos) {
            resultStr.erase(resultStr.find_last_not_of('0') + 1, std::string::npos); // ������� ������ ����
            if (resultStr.back() == '.') {
                resultStr.pop_back(); // ������� �����, ���� ��� ��������
            }
        }

        Label1->Caption = expressionUnicode + "=" + resultStr.c_str();
    } catch (const runtime_error& error) {
        Label1->Caption = error.what();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_delete_allClick(TObject *Sender)
{
	Label1->Caption="0";
    full = "";
}
//---------------------------------------------------------------------------
//������� ��� ����������� ���������� ���������� ��������
int TForm1::getPriority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
//������� ��� ���������� ���������� ��������
float TForm1::applyOp(float a, float b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
		if (b == 0) throw runtime_error("Division by zero");
        return a / b;
    default: return 0; // ��������� ����������� ��������
    }
}

// ������� ��� ���������� ���������
float TForm1::evaluateExpression(const UnicodeString& expression) {
    stack<float> values;
    stack<char> ops;

    // ����������� UnicodeString � std::string
    AnsiString ansiExpression = AnsiString(expression);
    string cleanedExpression = ansiExpression.c_str();

    // ������� ������� �� ���������
    cleanedExpression.erase(remove_if(cleanedExpression.begin(), cleanedExpression.end(), ::isspace), cleanedExpression.end());

    size_t pos = 0;
    while (pos < cleanedExpression.length()) {
        if (isdigit(cleanedExpression[pos]) || cleanedExpression[pos] == ',' ||
            (cleanedExpression[pos] == '-' && pos + 1 < cleanedExpression.length() &&
             (isdigit(cleanedExpression[pos + 1]) || cleanedExpression[pos + 1] == ','))) {
            // ��� ������ �����
            size_t end = pos + 1;
            while (end < cleanedExpression.length() &&
                   (isdigit(cleanedExpression[end]) || cleanedExpression[end] == ',' || cleanedExpression[end] == '.')) {
                end++;
            }
            string numStr = cleanedExpression.substr(pos, end - pos);
            replace(numStr.begin(), numStr.end(), ',', '.'); // �������� ������� �� �����
            try {
                values.push(stof(numStr));
            } catch (const invalid_argument& e) {
                throw runtime_error("Invalid number: " + numStr);
            }
            pos = end;
        } else if (cleanedExpression[pos] == '+' || cleanedExpression[pos] == '-' ||
                   cleanedExpression[pos] == '*' || cleanedExpression[pos] == '/') {
            // ��� ��������
            char op = cleanedExpression[pos];
            while (!ops.empty() && getPriority(ops.top()) >= getPriority(op)) {
                float val2 = values.top(); values.pop();
                float val1 = values.top(); values.pop();
                char opTop = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, opTop));
            }
            ops.push(op);
            pos++;
        } else {
            throw runtime_error("Invalid character: " + string(1, cleanedExpression[pos]));
        }
    }

    while (!ops.empty()) {
        float val2 = values.top(); values.pop();
        float val1 = values.top(); values.pop();
        char opTop = ops.top(); ops.pop();
        values.push(applyOp(val1, val2, opTop));
    }

    return values.top();
}
