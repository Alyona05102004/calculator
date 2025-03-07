//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <string.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;
TForm1 *Form1;
String full = ""; //full expression
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::number_click(TObject *Sender)
{	TButton *button = dynamic_cast<TButton*>(Sender);
	full += button->Caption;
	Label1->Caption = full;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btn_equalClick(TObject *Sender)
{
    // ���������, ���� �� ������� ������� MIN � �� ������� �� ���
    AnsiString str = Label1->Caption;
    if (str.Pos("MIN(") > 0 && str[str.Length()] != ')') {
		full += ")";
		Label1->Caption = full;
    }

    full += "=";
	Label1->Caption = full;

    float val = 0.0, val_tmp = 0.0;
    int step = 0;
    float S = 0, P = 1;
    int point_count = 0;
    int sn_count = 0;
    bool pl_min = true; // +;
    bool mul_div = true; // *;
	bool in_min_function = false; // ���� ��� MIN �������
	bool flag=false; //������ ����� ��� MIN �������
	float min_value = INT_MAX;  //����������� ��������  ��� ������� min

	for (size_t i = 1; i <= full.Length(); i++) {
        switch (full[i]) {
			case '0': { val = val * 10 + 0; step++; sn_count = 0; break; }
			case '1': { val = val * 10 + 1; step++; sn_count = 0; break; }
            case '2': { val = val * 10 + 2; step++; sn_count = 0; break; }
            case '3': { val = val * 10 + 3; step++; sn_count = 0; break; }
            case '4': { val = val * 10 + 4; step++; sn_count = 0; break; }
            case '5': { val = val * 10 + 5; step++; sn_count = 0; break; }
            case '6': { val = val * 10 + 6; step++; sn_count = 0; break; }
            case '7': { val = val * 10 + 7; step++; sn_count = 0; break; }
            case '8': { val = val * 10 + 8; step++; sn_count = 0; break; }
            case '9': { val = val * 10 + 9; step++; sn_count = 0; break; }
            case ',': {
                val_tmp = val;
                val = 0;
                step = 0;
                point_count++;
                sn_count = 0;
                if (point_count > 1) {
                    ShowMessage("2 �����");
					i = full.Length();
                    break;
                }
                break;
            }

			case '+': {
				sn_count++;
				if (sn_count > 1) {
					ShowMessage("2 �����");
					full = full.SubString(1, full.Length() - 1);
					Label1->Caption = full;
					break;
					}
				if (point_count > 0) {
					val = val_tmp + val * pow(10, -step);
				}
				step = 0;
				point_count = 0;
				val_tmp = 0;
				if (mul_div == true) {
					P = P * val;
				}
				else {
					if (abs(val) < 0.00) {
						ShowMessage("������� �� 0");
                        full = full.SubString(1, full.Length() - 1);
						Label1->Caption = full;
						break;
					}else {
						P = P / val;
					}
				}
				val = 0;
				if (pl_min == true) {
				S = S + P;
				}
				else {
				S = S - P;
				}
				pl_min = true;
				mul_div = true;
				P = 1;
				break;
			}

            case '-': {
                sn_count++;
				if (sn_count > 1) {
					ShowMessage("2 �����");
					full = full.SubString(1, full.Length() - 1);
					Label1->Caption = full;
					break;
				}
				if (point_count > 0) {
					val = val_tmp + val * pow(10, -step);
				}
				step = 0;
				point_count = 0;
				val_tmp = 0;
				if (mul_div == true) {
					P = P * val;
				}
                else {
                    if (abs(val) < 0.00) {
                        ShowMessage("������� �� 0");
                        full = full.SubString(1, full.Length() - 1);
						Label1->Caption = full;
                        break;
                    } else {
                        P = P / val;
                    }
                }
                val = 0;
				if (pl_min == true) {
					S = S + P;
					}
				else {
					S = S - P;
				}
				pl_min = false;
				mul_div = true;
				P = 1;
                break;
            }

            case '*': {
                sn_count++;
				if (sn_count > 1) {
					ShowMessage("2 �����");
					full = full.SubString(1, full.Length() - 1);
					Label1->Caption = full;
					break;
				}
				if (point_count > 0) {
					val = val_tmp + val * pow(10, -step);
				}
				step = 0;
				point_count = 0;
				val_tmp = 0;
				if (mul_div == true) {
					P = P * val;
				}
                else {
                    if (abs(val) < 0.00) {
                        ShowMessage("������� �� 0");
                        full = full.SubString(1, full.Length() - 1);
						Label1->Caption = full;
                        break;
                    } else {
                        P = P / val;
                    }
                }
                val = 0;
                mul_div = true;
                break;
            }

            case '/': {
                sn_count++;
				if (sn_count > 1) {
					ShowMessage("2 �����");
					full = full.SubString(1, full.Length() - 1);
					Label1->Caption = full;
					break;
				}
				if (point_count > 0) {
					val = val_tmp + val * pow(10, -step);
				}
				step = 0;
				point_count = 0;
				val_tmp = 0;
				if (mul_div == true) {
					P = P * val;
				}
                else {
                    if (abs(val) < 0.00) {
                        ShowMessage("������� �� 0");
                        full = full.SubString(1, full.Length() - 1);
						Label1->Caption = full;
                        break;
                    } else {
                        P = P / val;
                    }
                }
                val = 0;
                mul_div = false;
                break;
            }

            case 'M': {
                if (full.SubString(i, 3) == "MIN") {
					in_min_function = true;
					flag=true;
					i += 2; // ���������� 'I' � 'N'
                    continue;
                }
                break;
            }

            case ';': {
                if (in_min_function) {
                    if (point_count > 0) {
						val = val_tmp + val * pow(10, -step);
						step = 0;
						point_count = 0;
						val_tmp = 0;
					}
					if (flag) {
						min_value = val;
						flag = false;
					} else {
						if (val < min_value) {
							min_value = val;
						}
					}
					val = 0;
					step = 0;
                    point_count = 0;
                }
                break;
            }
			case ')': {
				if (in_min_function) {
					if (point_count > 0) {
						val = val_tmp + val * pow(10, -step);
						step = 0;
						point_count = 0;
						val_tmp = 0;
					}
					if (flag) {
						min_value = val;
						flag = false;
					} else {
						if (val < min_value) {
							min_value = val;
						}
					}
					val = 0;
					step = 0;
					point_count = 0;
					in_min_function = false;

					S = min_value;
					min_value = INT_MAX;
				}
				break;
			}

            case '=': {
                if (in_min_function) {
                    if (val < min_value) {
						min_value = val;
                    }
					full += FloatToStrF(min_value, ffGeneral, 5, 2);
					Label1->Caption = full;
					return;
                }

				if (point_count > 0) {
					val = val_tmp + val * pow(10, -step);
					step = 0;
					point_count = 0;
					val_tmp = 0;
				}
				if (mul_div == true) { P = P * val; }
                else {
                    if (abs(val) < 0.0) {
                        ShowMessage("������� �� 0");
                        full = full.SubString(1, full.Length() - 1);
						Label1->Caption = full;
                        break;
                    } else {
                        P = P / val;
                    }
                }
                val = 0;
				if (pl_min == true) {
				S = S + P;
				}
				else {
				S = S - P;
				}
				pl_min = true;
				mul_div = true;
				P = 1;
				i = full.Length();
				break;
			}
        }
    }

    if (full[full.Length()] == '*' || full[full.Length()] == '/') {
        if (pl_min == true) { S = S + P; }
        else { S = S - P; }
    }

    full += FloatToStrF(S, ffGeneral, 5, 2);
    Label1->Caption = full;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::btn_delete_allClick(TObject *Sender)
{
	//delete all
	Label1->Caption="0";
    full = "";
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_backspaceClick(TObject *Sender)
{
   if (full.Length() > 0) {
	full = full.SubString(1, full.Length() - 1);
    Label1->Caption = full;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_minClick(TObject *Sender)
{
	if (Label1->Caption != "0") {
        full = "MIN(" + Label1->Caption + ";";
        Label1->Caption = full;
    }
}
//---------------------------------------------------------------------------

