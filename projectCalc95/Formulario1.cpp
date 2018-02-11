//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
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
//Init

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	op='0';
    n1=0;
    m=0;
}
//---------------------------------------------------------------------------
//Cleaning functions

void TForm1::e1Clean()
{
	E1->Clear();
    E1->Text="0";
    E1->SetFocus();
    E1->ReadOnly=false;
    error=0;
}

void TForm1::cleanErr(){
	if(error==1){
        BCE->Click();
    }
}
//---------------------------------------------------------------------------
//Num input and calc functions

void TForm1::pressNum(char num){
    cleanErr();
    E1->Text=E1->Text + num;
}

int TForm1::pointHunt()
{
	for(int p=1;p<E1->Text.Length();p++){
        if(E1->Text[p]=='.')return 1;
    }
    return 0;
}

void TForm1::calc(){
	if(op!='0'&&!(E1->Text.ToDouble()==1)){
			if (op=='+')E1->Text=n1+E1->Text.ToDouble();
        	if (op=='-')E1->Text=n1-E1->Text.ToDouble();
        	if (op=='*')E1->Text=n1*E1->Text.ToDouble();
        	if (op=='/'){
            	if(E1->Text.ToDouble()!=0)E1->Text=(double)n1/E1->Text.ToDouble();
                if(E1->Text.ToDouble()==0){
                E1->Text="MATH ERROR";
                E1->ReadOnly=true;
                error=1;
                }
            }
    }
    op='0';
}
//---------------------------------------------------------------------------
//Keyboard press function

void __fastcall TForm1::E1KeyPress(TObject *Sender, char &Key)
{
	if (Key==',') Key='.';
    if (Key=='+') Bp->Click();
    if (Key=='-') Bmin->Click();
    if (Key=='*') Bmult->Click();
    if (Key=='/') Bdiv->Click();
    if (Key=='=') Beq->Click();
    if (Key=='.'){
    	if (pointHunt()==0) Key='.';
        else Key=0;
    }
    if ((Key<'0'||Key>'9')&&Key!=8&&Key!='.') Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BeqClick(TObject *Sender)
{
	calc();
    L1->Caption="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BCEClick(TObject *Sender)
{
	e1Clean();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BCClick(TObject *Sender)
{
	e1Clean();
    L1->Caption="";
    n1=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BpClick(TObject *Sender)
{
    if (error!=1){
   		L1->Caption=L1->Caption+E1->Text + " + ";
    	calc();
		n1=E1->Text.ToDouble();
		e1Clean();
	    op='+';
    	E1->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BminClick(TObject *Sender)
{

	if(error!=1){
		L1->Caption=L1->Caption+E1->Text + " - ";
    	calc();
		n1=E1->Text.ToDouble();
		e1Clean();
	    op='-';
    	E1->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BmultClick(TObject *Sender)
{
    if(error!=1){
		L1->Caption=L1->Caption+E1->Text + " * ";
    	calc();
	    n1=E1->Text.ToDouble();
		e1Clean();
	    op='*';
   		E1->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BdivClick(TObject *Sender)
{
    if (error!=1){
		L1->Caption=L1->Caption+E1->Text + " / ";
	    calc();
		n1=E1->Text.ToDouble();
		e1Clean();
    	op='/';
	    E1->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B1Click(TObject *Sender)
{
	pressNum('1');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B2Click(TObject *Sender)
{
    pressNum('2');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B3Click(TObject *Sender)
{
	pressNum('3');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B4Click(TObject *Sender)
{
	pressNum('4');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B5Click(TObject *Sender)
{
	pressNum('5');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B6Click(TObject *Sender)
{
	pressNum('6');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B7Click(TObject *Sender)
{
	pressNum('7');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B8Click(TObject *Sender)
{
	pressNum('8');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B9Click(TObject *Sender)
{
	pressNum('9');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::B0Click(TObject *Sender)
{
	pressNum('0');
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BsqClick(TObject *Sender)
{
    if(error!=1){
    	if (E1->Text.ToDouble()>=0){
        	E1->Text=AnsiString(sqrt(E1->Text.ToDouble()));
	    }
    	if (E1->Text.ToDouble()<0){
    		E1->Text="MATH ERROR";
	        E1->ReadOnly=true;
    	    error=1;
	    }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BreciClick(TObject *Sender)
{
    if (error!=1){
    	if (E1->Text.ToDouble()!=0){
    		E1->Text=AnsiString(1/E1->Text.ToDouble());
	    }
    	if (E1->Text.ToDouble()==0){
    		E1->Text="MATH ERROR";
	        E1->ReadOnly=true;
    	    error=1;
	    }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BBackClick(TObject *Sender)
{
	E1->Text=E1->Text.SetLength(E1->Text.Length()-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BpmClick(TObject *Sender)
{
    if (error!=1){
		if(E1->Text[1]=='-'){
        	E1->Text=E1->Text.Delete(1,1);
	    }
    	else{
        	E1->Text="-"+E1->Text;
	    }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BMSClick(TObject *Sender)
{
    m=E1->Text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BMRClick(TObject *Sender)
{
	if(error!=1)E1->Text=m;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BMCClick(TObject *Sender)
{
	m=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BMpClick(TObject *Sender)
{
	m+=E1->Text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BpoiClick(TObject *Sender)
{
    if (pointHunt()==0) E1->Text = E1->Text + '.';
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BporClick(TObject *Sender)
{

	if (error!=1)
    	E1->Text = AnsiString(n1*(E1->Text.ToDouble()/100));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BmmClick(TObject *Sender)
{
	m-=E1->Text.ToDouble();
}
//---------------------------------------------------------------------------

