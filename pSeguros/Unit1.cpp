//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF1 *F1;
//---------------------------------------------------------------------------
__fastcall TF1::TF1(TComponent* Owner)
	: TForm(Owner)
{
	cPer=0;
    M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Programa abierto, bienvenido"));
    E1->Text=AnsiString(cPer);
    //OJO SOLO PARA TESTEAR
    ofstream clientes, cindice, ubicacion,talla;
    clientes.open ("data\\clientes.txt", ios::trunc);
    cindice.open ("data\\indice.txt", ios::trunc);
    ubicacion.open ("data\\ubicacion.txt", ios::trunc);
    talla.open ("data\\tallas.txt", ios::trunc);
    //end testing
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

