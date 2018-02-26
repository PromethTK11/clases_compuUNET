//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "bitsWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF1 *F1;
//---------------------------------------------------------------------------
__fastcall TF1::TF1(TComponent* Owner)
	: TForm(Owner)
{
	cPer=0;
    M1->Clear();
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Programa abierto, bienvenido"));
    E1->Text=AnsiString(cPer);
    //OJO SOLO PARA TESTEAR
    ofstream clientes, cindice, ubicacion,talla;
    clientes.open ("data\\clientes.txt", ios::trunc);
    cindice.open ("data\\indice.txt", ios::trunc);
    ubicacion.open ("data\\ubicacion.txt", ios::trunc);
    talla.open ("data\\tallas.txt", ios::trunc);
    clientes.close();
    cindice.close();
    ubicacion.close();
    talla.close();

}
//---------------------------------------------------------------------------

void __fastcall TF1::Cargar1Click(TObject *Sender)
{
   F2->Show();
   M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Intento de carga de info de cliente No." + AnsiString(cPer+1)));
}
//---------------------------------------------------------------------------

void __fastcall TF1::Acercade1Click(TObject *Sender)
{
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Apertura de \"Acerca De\""));
	MessageDlg("Realizado Por:\n\nLino Ruben Maldonado Ramirez\n\nCedula: V-27.239.681\tSeccion: 01", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------


void __fastcall TF1::B1Click(TObject *Sender)
{
	M1->Clear();
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Limpiado correctamente"));
}
//---------------------------------------------------------------------------

void __fastcall TF1::DatosdeUbicacion1Click(TObject *Sender)
{
	F4->Show();
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Intento de carga de ubicacion"));
}
//---------------------------------------------------------------------------

void __fastcall TF1::DatosdeTalla1Click(TObject *Sender)
{
	F3->Show();
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Intento de carga de tallas"));
}
//---------------------------------------------------------------------------

void __fastcall TF1::B2Click(TObject *Sender)
{

	if (LE1->Text.IsEmpty())
    	MessageDlg("Campo vacios, ingrese cedula a buscar", mtError, TMsgDlgButtons() << mbOK, 0);

    else
    {
    	char scdi[1024];
        string input;
        bool fl3;

        M1->Clear();
        M1->Lines->Add("Resultados de la busqueda:");

    	ifstream clientes,tallas,ubicacion;
        ofstream resultado;
        clientes.open ("data\\clientes.txt");
        tallas.open ("data\\tallas.txt");
        ubicacion.open ("data\\ubicacion.txt");
        resultado.open ("data\\resultado.txt");

        //Busqueda para datos como tal
        for (int k=0; k<(cPer*10); k++)
        {
        	clientes >> scdi;
            if (AnsiString(scdi)==LE1->Text)
            {
                M1->Lines->Add("\n--------Datos Personales--------");
                resultado << "\n--------Datos Personales--------";

            	for (int z=0; z<9; z++)
                {
                    std::getline(clientes,input);
                    resultado << input.c_str() << endl;
                    M1->Lines->Add(AnsiString(input.c_str()));

                }

                fl3=true;
            }

        }

        //Busqueda para datos de ubicacion
        for (int k=0; k<(cPer*11); k++)
        {
        	ubicacion >> scdi;
            if (AnsiString(scdi)==LE1->Text)
            {
                M1->Lines->Add("\n--------Datos de Ubicacion--------");
                resultado << "\n--------Datos de Ubicacion--------";

            	for (int z=0; z<10; z++)
                {
                    std::getline(ubicacion,input);
                    resultado << input.c_str() << endl;
                    M1->Lines->Add(AnsiString(input.c_str()));

                }

            }

        }

        //Busqueda para datos de talla
        for (int k=0; k<(cPer*7); k++)
        {
        	tallas >> scdi;
            if (AnsiString(scdi)==LE1->Text)
            {
                M1->Lines->Add("\n--------Datos de Talla--------");
                resultado << "\n--------Datos de Talla--------";

            	for (int z=0; z<6; z++)
                {
                    std::getline(tallas,input);
                    resultado << input.c_str() << endl;
                    M1->Lines->Add(AnsiString(input.c_str()));

                }

            }

        }

        if (fl3==false)
        	M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Persona no encontrada"));

        clientes.close();
        tallas.close();
        ubicacion.close();
        resultado.close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TF1::LE1KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8) Key=0;
}
//---------------------------------------------------------------------------


void __fastcall TF1::I1Click(TObject *Sender)
{
	bitsF5->ShowModal();
}
//---------------------------------------------------------------------------

