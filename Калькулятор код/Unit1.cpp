//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <stack>
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
{
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
{ // ��������� �������� ������ ���� ��������� �� �������� ���� ��������
    if (!full.IsEmpty() && (full[full.Length()] != '+' && full[full.Length()] != '-' && full[full.Length()] != '*' && full[full.Length()] != '/')) {
        full += action; // ��������� ��������
    } else if (full.IsEmpty()) {
        full = Label1->Caption; // ��������� ������ �����
        full += action; // ��������� ��������
    }
    Label1->Caption = full; // ��������� �����������
}

void __fastcall TForm1::btn_equalClick(TObject *Sender)
{
   if (full.IsEmpty()) {
        return;
    }


    float result = evaluateExpression(full);
    full += "=" + FloatToStr(result);
    Label1->Caption = full;

	full = "";
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
	AnsiString ansiExpression = AnsiString(expression);
	stringstream ss(ansiExpression.c_str());
	float num;
	char op;

	while (ss >> num) {
		values.push(num);
		if (ss >> op) {
            while (!ops.empty() && getPriority(ops.top()) >= getPriority(op)) {
                float val2 = values.top(); values.pop();
                float val1 = values.top(); values.pop();
				char opTop = ops.top(); ops.pop();
                values.push(applyOp(val1, val2, opTop));
            }
            ops.push(op);
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

void __fastcall TForm1::btn_dotsClick(TObject *Sender)
{
   UnicodeString text = Label1->Caption;
    if (Pos(",", text) == 0) {
        Label1->Caption = text + ",";
		full += ",";
	}

}
//---------------------------------------------------------------------------

