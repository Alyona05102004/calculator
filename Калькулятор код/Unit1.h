//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *btn_1;
	TButton *btn_2;
	TButton *btn_3;
	TButton *btn_4;
	TButton *btn_5;
	TButton *btn_9;
	TButton *btn_7;
	TButton *btn_6;
	TButton *btn_8;
	TButton *btn_0;
	TButton *btn_dots;
	TButton *btn_equal;
	TButton *btn_sum;
	TButton *btn_sub;
	TButton *btn_umnoj;
	TButton *btn_del;
	TButton *btn_backspace;
	TButton *btn_min;
	TButton *btn_delete_all;
	void __fastcall number_click(TObject *Sender);
	void __fastcall btn_equalClick(TObject *Sender);
	void __fastcall btn_delete_allClick(TObject *Sender);
	void __fastcall btn_backspaceClick(TObject *Sender);
	void __fastcall btn_minClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
