//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
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


// ������� ��� ���������� ���������
float TForm1::evaluateExpression(const UnicodeString& expression) {
vector<float> numbers;
    vector<char> operations;
    AnsiString ansiExpression = AnsiString(expression);
    stringstream ss(ansiExpression.c_str());
    float number;
    char operation;

    // ������ ����� � ��������
    while (ss >> number) {
        numbers.push_back(number);
        if (ss >> operation) {
            operations.push_back(operation);
        }
    }

    // ���������� ��������
    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == '+') {
            numbers[i + 1] = numbers[i] + numbers[i + 1];
        } else if (operations[i] == '-') {
            numbers[i + 1] = numbers[i] - numbers[i + 1];
        } else if (operations[i] == '*') {
            numbers[i + 1] = numbers[i] * numbers[i + 1];
        } else if (operations[i] == '/') {
            if (numbers[i + 1] != 0) {
                numbers[i + 1] = numbers[i] / numbers[i + 1];
            } else {
                ShowMessage("�� 0 ������ ������!");
                return 0;
            }
        }
    }

    return numbers.back(); // ���������� ��������� ���������
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

