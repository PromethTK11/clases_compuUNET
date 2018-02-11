//---------------------------------------------------------------------------

#ifndef Formulario1H
#define Formulario1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *L1;
    TLabel *L3;
    TLabel *L2;
    TEdit *E1;
    TEdit *E2;
    TButton *B1;
	TLabel *L4;
	TButton *B2;
    void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B1Click(TObject *Sender);
	void __fastcall E1Click(TObject *Sender);
private:	// User declarations
public:	// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
