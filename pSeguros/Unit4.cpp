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
	if (LE1->Text.IsEmpty()||LE2->Text.IsEmpty()||LE3->Text.IsEmpty()||LE4->Text.IsEmpty()||LE5->Text.IsEmpty()||LE6->Text.IsEmpty()||LE7->Text.IsEmpty()||LE8->Text.IsEmpty()||LE9->Text.IsEmpty())
    	MessageDlg("Campos vacios", mtError, TMsgDlgButtons() << mbOK, 0);
    	else
        {
        	F4->Close();
            F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de ubicacion abortada"));
            ofstream ubicacion;
            ubicacion.open ("data\\ubicacion.txt", ios::app);
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
