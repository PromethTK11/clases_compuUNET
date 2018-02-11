//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CB1Click(TObject *Sender)
{
	AnsiString ruta;
    if (CB1->ItemIndex==-1) L1->Caption="Sin seleccion de imagen";
    ruta = "images\\" + AnsiString(CB1->ItemIndex) + ".bmp";
    if (FileExists(ruta))
    {
    	I1->Picture->LoadFromFile(ruta);
    }
    else
    	ShowMessage("Imagen no existe");
    L1->Caption=CB1->Text;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	if (CB1->ItemIndex==-1) L1->Caption="Sin seleccion de imagen";
}
//---------------------------------------------------------------------------
