//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
//Clase para personas
class PERSON{
    public:
    	AnsiString nombre,departamento;
        double horas;
        int n;
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *L1;
	TEdit *E1;
	TEdit *E3;
	TButton *B1;
	TButton *B2;
	TLabel *L3;
	TLabel *L4;
	TLabel *L2;
	TEdit *E2;
	TLabel *L6;
	TLabel *L5;
	TLabel *L7;
	TLabel *L8;
	TLabel *L9;
	TButton *B3;
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall E2KeyPress(TObject *Sender, char &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B3Click(TObject *Sender);
private:	// User declarations
public:
	int n;
    double mHoras;
    PERSON lista[10];	// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
