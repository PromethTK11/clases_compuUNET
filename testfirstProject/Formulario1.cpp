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




void __fastcall TForm1::FormClick(TObject *Sender)
{

        if (i==0){
        	Form1->Color=clBlue;
                i++;
        }
        else if (i==1){
        	Form1->Color=clRed;
                i++;
        }
        else if (i==2){
        	Form1->Color=clTeal;
                i++;
        }
        else if (i==3){
        	Form1->Color=clYellow;
                i=0;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	i=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==VK_UP){
        Form1->Caption="UP = GROUND";
        Form1->Color=clMaroon;
        if (Top==0) Form1->Top=629; 
        else if((Top-100)>0)Form1->Top-=100;
        else Top=0;
    }
    else if(Key==VK_LEFT){
        Form1->Caption="Left = CONTROL";
        Form1->Color=clBlue;
        if(Left==0)Form1->Left=1232;
        else if((Left-100)>0)Form1->Left-=100;
        else Left=0;
    }
    else if(Key==VK_DOWN){
        Form1->Caption="DOWN = TO";
        Form1->Color=clTeal;
        if(Top==610)Form1->Top = 0;
        else if((Top+100)<610)Form1->Top+=100;
        else Top=610;
    }
    else if(Key==VK_RIGHT){
        Form1->Caption="RIGHT = MAJOR TOM";
        Form1->Color=clRed;
        if (Left==1232) Form1->Left = 0;
        else if((Left+100)<1232)Form1->Left+=100;
        else Left=1232;
    }
}
//---------------------------------------------------------------------------


