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
    TEdit *E1;
        TButton *Beq;
        TButton *BC;
        TButton *BCE;
        TButton *BBack;
        TButton *Bp;
        TButton *Bpoi;
        TButton *Bpm;
        TButton *B0;
        TButton *BMp;
        TButton *Breci;
        TButton *Bpor;
        TButton *Bsq;
        TButton *Bmin;
        TButton *B3;
        TButton *B2;
        TButton *B1;
        TButton *Bmult;
        TButton *Bdiv;
        TButton *B6;
        TButton *B5;
        TButton *B9;
        TButton *B8;
        TButton *B4;
        TButton *B7;
        TButton *BMS;
        TButton *BMR;
        TButton *BMC;
	TLabel *L1;
	TButton *Bmm;
        void __fastcall BeqClick(TObject *Sender);
        void __fastcall E1KeyPress(TObject *Sender, char &Key);
	void __fastcall BCEClick(TObject *Sender);
	void __fastcall BCClick(TObject *Sender);
	void __fastcall BpClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall BminClick(TObject *Sender);
	void __fastcall BmultClick(TObject *Sender);
	void __fastcall BdivClick(TObject *Sender);
	void __fastcall B1Click(TObject *Sender);
	void __fastcall B2Click(TObject *Sender);
	void __fastcall B3Click(TObject *Sender);
	void __fastcall B4Click(TObject *Sender);
	void __fastcall B5Click(TObject *Sender);
	void __fastcall B6Click(TObject *Sender);
	void __fastcall B7Click(TObject *Sender);
	void __fastcall B8Click(TObject *Sender);
	void __fastcall B9Click(TObject *Sender);
	void __fastcall B0Click(TObject *Sender);
	void __fastcall BsqClick(TObject *Sender);
	void __fastcall BreciClick(TObject *Sender);
	void __fastcall BBackClick(TObject *Sender);
	void __fastcall BpmClick(TObject *Sender);
	void __fastcall BMSClick(TObject *Sender);
	void __fastcall BMRClick(TObject *Sender);
	void __fastcall BMCClick(TObject *Sender);
	void __fastcall BMpClick(TObject *Sender);
	void __fastcall BpoiClick(TObject *Sender);
	void __fastcall BporClick(TObject *Sender);
	void __fastcall BmmClick(TObject *Sender);
private:	// User declarations
public:
    void e1Clean();
    int pointHunt();
    void calc();
	double n1,m;
    char op;	// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
