//---------------------------------------------------------------------------

#ifndef Unidad1H
#define Unidad1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *L1;
	TEdit *E1;
	TEdit *E2;
	TEdit *E3;
	TButton *B1;
	TButton *B2;
	TImage *I2;
	TLabel *L2;
	TLabel *L3;
	TLabel *L4;
	TImage *I1;
	TLabel *L5;
	TEdit *E4;
	TLabel *L6;
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall E4KeyPress(TObject *Sender, char &Key);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall B1Click(TObject *Sender);
private:	// User declarations
public:
	int n,medad;		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
//Clase para personas
class PERSON{
    public:
    	AnsiString nombre;
        int edad;
        int estatura;
        double peso;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
