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
    bool fl1=false, fl2=true;
    char cdi[10],cdi2[10];
	if (E1->Text.IsEmpty()||E2->Text.IsEmpty())
    	MessageDlg("Campos vacios, ingrese valores validos", mtError, TMsgDlgButtons() << mbOK, 0);

    //El proceso para chequear si se repite es simple, pasa primero por el archivo indice para chequear si existe
    //Y luego pasa por el archivo de las ubicaciones para ver si ya se ha guardado algo existente
    //Cada flag es un proceso completado

    else
    {
    	ifstream cindice;
        cindice.open ("data\\indice.txt");
        for (int i=0; i<F1->cPer&&fl1==false; i++)
        {
        	cindice >> cdi;
            if (AnsiString(cdi)==LE1->Text)
            {
            	ifstream cindice2;
                cindice2.open("data\\tallas.txt");
                for (int j=0; j<(F1->cPer*10)&&fl2==true; j++)
                {
                	cindice2 >> cdi2;
                    if (AnsiString(cdi2)==LE1->Text)
                    {
                    	MessageDlg("El ciente ya posee datos de talla, ingrese un cliente valido", mtError, TMsgDlgButtons() << mbOK, 0);
                        fl2=false;
                    }

                }
                fl1=true;
                cindice2.close();
            }
            else
            	MessageDlg("Cedula no existente, ingrese una cedula existente", mtError, TMsgDlgButtons() << mbOK, 0);
        }
        cindice.close();
    }

    if (fl1==true&&fl2==true)
    {
    	F3->Close();
		F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de tallas exitosa"));
		ofstream tallas;
        tallas.open ("data\\tallas.txt", ios::app);
        tallas << LE1->Text.c_str() << endl;
        tallas << "Chaqueta: " << CB1->Text.c_str() << endl;
        tallas << "Camisa: " << CB2->Text.c_str() << endl;
        tallas << "Sombrero: " << CB3->Text.c_str() << endl;
        tallas << "Pantalon: " << E1->Text.c_str() << endl;
        tallas << "Zapato: " << E2->Text.c_str() << endl;
        tallas << "==================================================" << endl;
        tallas.close();
        LE1->Clear();
        CB1->ItemIndex=0;
        CB2->ItemIndex=0;
        CB3->ItemIndex=0;
        E1->Clear();
        E2->Clear();
    }
}
//---------------------------------------------------------------------------

