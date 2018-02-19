//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF3 : public TForm
{
__published:	// IDE-managed Components
	TButton *B2;
	TButton *B1;
	TLabel *L1;
	TLabel *L3;
	TComboBox *CB1;
	TComboBox *CB3;
	TLabel *L5;
	TLabel *L6;
	TLabel *L4;
	TComboBox *CB2;
	TLabel *L2;
	TEdit *E2;
	TEdit *E1;
	TLabeledEdit *LE1;
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall B1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TF3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF3 *F3;
//---------------------------------------------------------------------------
#endif
