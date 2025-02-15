//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
float first_num=0.0;   //first number
float second_num=0.0;  //second number
char user_action=' ';   //mathematical action
float res=0.0; //result
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
	if (Label1->Caption=="0") {
		Label1->Caption=button->Caption;
	}
	else {
        Label1->Caption+=button->Caption;
	}
	full += button->Caption;
	Label1->Caption = full;
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
{   if (user_action != ' ') {
		full = full.SubString(1, full.Length() - 1);
	}
	first_num = StrToFloat(Label1->Caption);
	user_action = action;
	full += action;
	Label1->Caption = full;
}

void __fastcall TForm1::btn_equalClick(TObject *Sender)
{
//ravno
	if (user_action==' ') {
		return;
	}
    int last_operator_pos = full.LastDelimiter("+-*/");
    if (last_operator_pos == 0) {
        ShowMessage("������: ������������ ���������.");
        return;
    }

 	UnicodeString second_num_str = full.SubString(last_operator_pos + 1, full.Length() - last_operator_pos);
	second_num = StrToFloat(second_num_str);
	switch (user_action) {
		case ('+'): res=first_num + second_num;
			break;
		case ('-'): res=first_num - second_num;
			break;
		case ('*'): res=first_num * second_num;
			break;
		case ('/'):
			if (second_num!=0.0){
			res=first_num / second_num;
			}
			else {
				ShowMessage("�� 0 ������ ������!");
                return;
			}
			break;
	}
	full += "=" + FloatToStr(res);
	Label1->Caption=full;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_delete_allClick(TObject *Sender)
{
//delete all
	Label1->Caption="0";
	first_num=0.0;
	second_num=0.0;
	user_action=' ';
	res=0.0;
    full = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_dotsClick(TObject *Sender)
{
//dots
	UnicodeString text = Label1->Caption;
	if (Pos(",", text) == 0) {
		Label1->Caption = text + ",";
        full += ",";
	}
}
//---------------------------------------------------------------------------

