//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unidad1.h"

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
int imgChanger(int est, double pe){
    if (est<180&&pe>80)return 0;
	else if (est>180&&pe>50&&pe<60)return 1;
    	else if (est>180&&pe>60&&pe<75)return 2;
        	else if (est>180&&pe>80)return 3;
            	else return 4;

}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	n=0;
    medad=100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
	if((Key<'A'||Key>'Z'&&Key<'a'||Key>'z')&&Key!=8&&Key!=32) Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::E4KeyPress(TObject *Sender, char &Key)
{
	if((Key<'0'||Key>'9')&&Key!=8&&Key!='.') Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B2Click(TObject *Sender)
{
	E1->Clear();
    E2->Clear();
    E3->Clear();
    E4->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B1Click(TObject *Sender)
{
    AnsiString ruta;
    if (n<12){
        persona[n].nombre = E1->Text;
		persona[n].estatura = E2->Text.ToInt();
		persona[n].peso = E3->Text.ToDouble();
        persona[n].edad = E4->Text.ToInt();
        if (persona[n].edad<medad)
        	medad=persona[n].edad;
        ruta = "images\\" + AnsiString(imgChanger(persona[n].estatura,persona[n].peso)) + ".bmp";
        I1->Picture->LoadFromFile(ruta);
        n++;
    }
    if (n==12){
    	L6->Visible=true;
    	float prom=0;
        int j=0;
    	for (int p=0;p<12;p++){
        	if(persona[p].estatura>180&&persona[p].edad<18&&persona[p].peso<=80)
   			{
    			L6->Caption=L6->Caption+persona[p].nombre+"\n";
                prom+=persona[p].estatura;
                j++;
		    }
        }
        L6->Caption=L6->Caption+"\nAltura promedio= "+prom/j+"\nMenor edad: "+medad+"\n";
    }
}
//---------------------------------------------------------------------------
