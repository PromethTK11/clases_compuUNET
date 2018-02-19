//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF2 *F2;
//---------------------------------------------------------------------------
__fastcall TF2::TF2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF2::B2Click(TObject *Sender)
{
	F2->Close();
    F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de cliente No." + AnsiString(F1->cPer+1)+" abortada"));
}
//---------------------------------------------------------------------------
void __fastcall TF2::E2KeyPress(TObject *Sender, char &Key)
{
	if((Key<'A'||Key>'Z'&&Key<'a'||Key>'z')&&Key!=8&&Key!=' ') Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::E3KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8&&Key!='/') Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::E1KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8) Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::B1Click(TObject *Sender)
{
	if (E1->Text.IsEmpty()||E2->Text.IsEmpty()||E4->Text.IsEmpty())
    	MessageDlg("Campos vacios, ingrese valores validos", mtError, TMsgDlgButtons() << mbOK, 0);

		else
		{
            F2->Close();
            F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de cliente No." + AnsiString(F1->cPer+1)+" exitosa"));
            F1->cPer++;
            F1->E1->Text=AnsiString(F1->cPer);
		}
}
//---------------------------------------------------------------------------

void __fastcall TF2::CB1KeyPress(TObject *Sender, char &Key)
{
	Key=0;	
}
//---------------------------------------------------------------------------
