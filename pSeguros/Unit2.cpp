//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF2 *F2;
//---------------------------------------------------------------------------
__fastcall TF2::TF2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF2::B2Click(TObject *Sender)
{
	F2->Close();
    F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de cliente No." + AnsiString(F1->cPer+1)+" abortada"));
}
//---------------------------------------------------------------------------
void __fastcall TF2::E2KeyPress(TObject *Sender, char &Key)
{
	if((Key<'A'||Key>'Z'&&Key<'a'||Key>'z')&&Key!=8&&Key!=' ') Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::E3KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8&&Key!='/') Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::E1KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'0'||Key>'9')&&Key!=8) Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TF2::B1Click(TObject *Sender)
{
	if (E1->Text.IsEmpty()||E2->Text.IsEmpty()||E3->Text.IsEmpty())
    	MessageDlg("Campos vacios, ingrese valores validos", mtError, TMsgDlgButtons() << mbOK, 0);

		else
		{
            F2->Close();
            F1->M1->Lines->Add(AnsiString("[" + AnsiString(Time()) + "]Carga de cliente No." + AnsiString(F1->cPer+1)+" exitosa"));
			ofstream clientes;
			clientes.open ("data\\clientes.txt", ios::app);
  			clientes << "Cedula: " << E1->Text.c_str() << endl;
            clientes << "Nombre: " << E2->Text.c_str() << endl;
            clientes << "Sexo: " << CB4->Text.c_str() << endl;
            clientes << "Nacionalidad: " << CB1->Text.c_str() << endl;
            clientes << "Grupo Sanguineo: " << CB2->Text.c_str() << endl;
            clientes << "Fecha de Nacimiento: " << AnsiString(DTP1->Date).c_str() << endl;
            clientes << "Edo Civil: " << CB3->Text.c_str() << endl;
            clientes << "Ciudad Natal: " << E3->Text.c_str() << endl;
            clientes << "==================================================" << endl;
			clientes.close();
            ofstream cindice;
			cindice.open ("data\\indice.txt", ios::app);
  			cindice << E1->Text.c_str() << endl;
			cindice.close();
            F1->cPer++;
            F1->E1->Text=AnsiString(F1->cPer);
		}
}
//---------------------------------------------------------------------------

void __fastcall TF2::CB1KeyPress(TObject *Sender, char &Key)
{
	Key=0;	
}
//---------------------------------------------------------------------------

