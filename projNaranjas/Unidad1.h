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
    TLabel *L2;
    TLabel *L1;
    TLabel *L3;
    TEdit *E1;
    TEdit *E2;
    TButton *B1;
    TButton *B2;
    TButton *B3;
    TLabel *L4;
    TButton *B4;
    TImage *I1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall B1Click(TObject *Sender);
    void __fastcall E1KeyPress(TObject *Sender, char &Key);
    void __fastcall B2Click(TObject *Sender);
    void __fastcall B3Click(TObject *Sender);
    void __fastcall B4Click(TObject *Sender);
private:	// User declarations
public:
    int cPre,cEx,cNa,cRech,cTot;		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
