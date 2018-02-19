//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF4 : public TForm
{
__published:	// IDE-managed Components
	TLabel *L1;
	TButton *B1;
	TButton *B2;
	TLabeledEdit *LE1;
	TLabeledEdit *LE2;
	TLabeledEdit *LE3;
	TLabeledEdit *LE4;
	TLabeledEdit *LE5;
	TLabeledEdit *LE6;
	TLabeledEdit *LE9;
	TLabeledEdit *LE7;
	TLabeledEdit *LE8;
	TLabeledEdit *LabeledEdit1;
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall LE1KeyPress(TObject *Sender, char &Key);
	void __fastcall LE7KeyPress(TObject *Sender, char &Key);
	void __fastcall LE9KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TF4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF4 *F4;
//---------------------------------------------------------------------------
#endif
