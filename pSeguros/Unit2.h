//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TF2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *L1;
	TComboBox *CB1;
	TLabel *L2;
	TEdit *E1;
	TLabel *L3;
	TLabel *L4;
	TEdit *E2;
	TLabel *L5;
	TComboBox *CB2;
	TEdit *E3;
	TLabel *L6;
	TLabel *L9;
	TEdit *E4;
	TComboBox *CB3;
	TComboBox *CB4;
	TLabel *L8;
	TLabel *L7;
	TButton *B1;
	TButton *B2;
	void __fastcall B2Click(TObject *Sender);
	void __fastcall E2KeyPress(TObject *Sender, char &Key);
	void __fastcall E3KeyPress(TObject *Sender, char &Key);
	void __fastcall E3Click(TObject *Sender);
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B1Click(TObject *Sender);
private:	// User declarations
public:
	bool fl1;		// User declarations
	__fastcall TF2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF2 *F2;
//---------------------------------------------------------------------------
#endif
