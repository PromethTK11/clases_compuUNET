//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF3 *F3;
//---------------------------------------------------------------------------
__fastcall TF3::TF3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF3::E1KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8) Key=0;	
}
//---------------------------------------------------------------------------

void __fastcall TF3::B2Click(TObject *Sender)
{
	F3->Close();
    F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de tallas abortada"));
}
//---------------------------------------------------------------------------

void __fastcall TF3::B1Click(TObject *Sender)
{
	if (E1->Text.IsEmpty()||E2->Text.IsEmpty())
    	MessageDlg("Campos vacios, ingrese valores validos", mtError, TMsgDlgButtons() << mbOK, 0);

    	else
        {
            F3->Close();
			F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de tallas exitosa"));
        }
}
//---------------------------------------------------------------------------

