//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unidad1.h"
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
    cTot=0; cRech=0; cPre=0; cEx=0; cNa=0;    //Contadores totales
    L4->Caption = "ID(Num)\t\t\tTipo\n";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B1Click(TObject *Sender)
{
    if (E1->Text.ToInt()>450&&E2->Text.ToInt()>=9&&E2->Text.ToInt()<=12)
    {
        L4->Caption = L4->Caption + (cTot+1) +"\t\t\tPremium\n";
        cPre++;
    }
        else if (E1->Text.ToInt()>=300&&E1->Text.ToInt()<=450&&E2->Text.ToInt()>=8&&E2->Text.ToInt()<=11)
        {
            L4->Caption = L4->Caption + (cTot+1) +"\t\t\tExtra\n";
            cEx++;
        }
            else if (E1->Text.ToInt()<300&&E2->Text.ToInt()>=7&&E2->Text.ToInt()<=9)
            {
                L4->Caption = L4->Caption + (cTot+1) +"\t\t\tNatural\n";
                cNa++;
            }
                else
                {
                    L4->Caption = L4->Caption + (cTot+1) +"\t\t\tRechazada\n";
                    cRech++;
                }

    cTot++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
    if((Key<'0'||Key>'9')&&Key!=8) Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B2Click(TObject *Sender)
{
    L4->Caption = "ID(Num)\t\t\tTipo\n";
    E1->Clear();
    E2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B3Click(TObject *Sender)
{
    ShowMessage("Produccion y ganancia total");
    ShowMessage("Ganancia de las tipo premium: "+AnsiString(cPre*500)+" Bsf.");
    ShowMessage("Ganancia de las tipo extra: "+AnsiString(cEx*350)+" Bsf.");
    ShowMessage("Ganancia de las tipo natural: "+AnsiString(cNa*200)+" Bsf.");
    ShowMessage("Ganancia total: "+AnsiString((cPre*500)+(cEx*350)+(cNa*350)-(cRech*100))+" Bsf.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::B4Click(TObject *Sender)
{
    ShowMessage("Porcentaje de las rechazadas: "+AnsiString(((float)cRech*100/cTot))+"%");
}
//---------------------------------------------------------------------------
