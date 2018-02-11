//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Formulario1.h"
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


void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
	if((Key<'0'||Key>'9')&&Key!=8) Key=0;	//Validar entrada de numeros
}
//---------------------------------------------------------------------------


void __fastcall TForm1::B1Click(TObject *Sender)
{
	int n1,n2;
    float div;
	if(E1->Text.Length()==0 || E2->Text.Length()==0)
    	ShowMessage("Datos Incomlpetos");
    else {
    	n1 = E1->Text.ToInt();
        n2 = E2->Text.ToInt();
        if (n2 == 0)
        	ShowMessage("Numero 2 tiene que ser diferente de (0)");
        else {
        	L4->Visible=true;
        	div = (float)n1/n2;
        	L4->Caption= "Sumado  =  " + AnsiString(n1+n2) + "\n" + "Restado =  " + AnsiString(n1-n2) + "\n" + "Multipli=  " + AnsiString(n1*n2) + "\n"	+ "Dividido=  " + AnsiString(div);
        }
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::E1Click(TObject *Sender)
{
	E1->Clear();
    E2->Clear();
    E1->SetFocus();
	L4->Visible=false;
}
//---------------------------------------------------------------------------

