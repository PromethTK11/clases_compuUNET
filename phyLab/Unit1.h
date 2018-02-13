//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
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
	TEdit *E1;
	TButton *B1;
	TButton *B2;
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
private:	// User declarations
public:
   int pointHunt();		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
