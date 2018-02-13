//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
int TForm1::pointHunt()
{
	for(int p=1;p<E1->Text.Length();p++){
        if(E1->Text[p]=='.')return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
    if (Key=='.'){
    	if (pointHunt()==0) Key='.';
        else Key=0;
    }
	if((Key<'0'||Key>'9')&&Key!=8&&Key!='.') Key=0;	//Validar entrada de numeros
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B1Click(TObject *Sender)
{
	if (E1->Text.ToDouble()>302)
    	ShowMessage("La medida es mayor a 150 °C");
	    else if (E1->Text.ToDouble()<302)
    		ShowMessage("La medida es menor a 150 °C");
    		else if (E1->Text.ToDouble()==302)
    			ShowMessage("La medida es igual a 150 °C");
               	else ShowMessage("Ingrese un valor válido");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B2Click(TObject *Sender)
{
	ShowMessage("Gracias por utilizar el programa!");
    Form1->Close();
}
//---------------------------------------------------------------------------
