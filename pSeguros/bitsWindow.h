//---------------------------------------------------------------------------

#ifndef bitsWindowH
#define bitsWindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <bitset>
#include <string.h>
//---------------------------------------------------------------------------
class TbitsF5 : public TForm
{
__published:	// IDE-managed Components
	TLabel *L1;
	TLabel *L0;
	TLabeledEdit *LE1;
	TLabeledEdit *LE2;
	TButton *B1;
	TButton *B2;
	TLabeledEdit *LE3;
	TLabel *L2;
	TEdit *E1;
	TButton *B3;
	TLabel *L3;
	TLabel *L7;
	TLabel *L5;
	TLabel *L6;
	TLabel *L12;
	TEdit *L8;
	TEdit *L9;
	TEdit *L10;
	TEdit *L11;
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall B3Click(TObject *Sender);
private:	// User declarations
public:
	int cont;		// User declarations
	__fastcall TbitsF5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TbitsF5 *bitsF5;
//---------------------------------------------------------------------------
#endif
