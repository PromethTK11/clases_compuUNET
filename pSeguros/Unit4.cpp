//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF4 *F4;
//---------------------------------------------------------------------------
__fastcall TF4::TF4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF4::B1Click(TObject *Sender)
{
    bool fl1=false, fl2=true;
    char cdi[10],cdi2[10];
	if (LE1->Text.IsEmpty()||LE2->Text.IsEmpty()||LE3->Text.IsEmpty()||LE4->Text.IsEmpty()||LE5->Text.IsEmpty()||LE6->Text.IsEmpty()||LE7->Text.IsEmpty()||LE8->Text.IsEmpty()||LE9->Text.IsEmpty())
    	MessageDlg("Campos vacios", mtError, TMsgDlgButtons() << mbOK, 0);

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
            if (AnsiString(cdi)==LE0->Text)
            {
                ifstream cindice2;
                cindice2.open("data\\ubicacion.txt");
                for (int j=0; j<(F1->cPer*10)&&fl2==true; j++)
                {
                	cindice2 >> cdi2;
                    if (AnsiString(cdi2)==LE0->Text)
                    {
                    	MessageDlg("El ciente ya posee datos de ubicacion, ingrese un cliente valido", mtError, TMsgDlgButtons() << mbOK, 0);
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
        	F4->Close();
            F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de ubicacion exitosa"));
            ofstream ubicacion;
            ubicacion.open ("data\\ubicacion.txt", ios::app);
            ubicacion << LE0->Text.c_str() << endl;
            ubicacion << "Correo Electronico: " << LE9->Text.c_str() << endl;	//Correo electronico
            ubicacion << "Pais: " << LE1->Text.c_str() << endl;
            ubicacion << "Estado: " << LE2->Text.c_str() << endl;
            ubicacion << "Ciudad: " << LE3->Text.c_str() << endl;
            ubicacion << "Calle o avenida: " << LE4->Text.c_str() << endl;
            ubicacion << "Urbanizacion o edificio: " << LE5->Text.c_str() << endl;
            ubicacion << "Casa o Apart: " << LE6->Text.c_str() << endl;
            ubicacion << "Telefono celular: " << LE8->Text.c_str() << endl;
            ubicacion << "Telefono-Habitacion: " << LE7->Text.c_str() << endl;
            ubicacion << "==================================================" << endl;
            ubicacion.close();
            LE0->Clear();
            LE9->Clear();
            LE1->Clear();
            LE2->Clear();
            LE3->Clear();
            LE4->Clear();
            LE5->Clear();
            LE6->Clear();
            LE7->Clear();
            LE8->Clear();
    }
}
//---------------------------------------------------------------------------
void __fastcall TF4::B2Click(TObject *Sender)
{
	F4->Close();
	F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de ubicacion abortada"));
}
//---------------------------------------------------------------------------
void __fastcall TF4::LE1KeyPress(TObject *Sender, char &Key)
{
	if((Key<'A'||Key>'Z'&&Key<'a'||Key>'z')&&Key!=8&&Key!=' ') Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF4::LE7KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8) Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF4::LE9KeyPress(TObject *Sender, char &Key)
{
	if (Key==' ')Key=0;
}
//---------------------------------------------------------------------------

