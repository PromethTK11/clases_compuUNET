//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

PERSON persona[12];		//<--- OJO declaracion de persona
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    n=0;
    mHoras=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
	if((Key<'A'||Key>'Z'&&Key<'a'||Key>'z')&&Key!=8&&Key!=32) Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B2Click(TObject *Sender)
{
	E1->Clear();
    E2->Clear();
    E3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E2KeyPress(TObject *Sender, char &Key)
{
	if((Key<'0'||Key>'9')&&Key!=8&&Key!='.') Key=0;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B1Click(TObject *Sender)
{
	if(n<10){
    	lista[n].nombre=E1->Text;
    	lista[n].horas=E2->Text.ToDouble();
    	lista[n].departamento=E3->Text;
		if(lista[n].horas>mHoras)
    		mHoras=lista[n].horas;
		n++;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B3Click(TObject *Sender)
{
    L6->Caption="";
    L7->Caption="";
    L8->Caption="";
    L9->Caption="";
	for (int p=0;p<n;p++)
    {
		L6->Caption=L6->Caption+(p+1)+"\n";
        L7->Caption=L7->Caption+lista[p].nombre+"\n";
        L8->Caption=L8->Caption+AnsiString(lista[p].horas)+"\n";
        L9->Caption=L9->Caption+lista[p].departamento+"\n";

	}
    ShowMessage("Empleados que trabajaron mas horas");
    for (int p=0;p<n;p++)
    {
    	if (mHoras==lista[p].horas)ShowMessage(lista[p].nombre);
    }
}
//---------------------------------------------------------------------------

