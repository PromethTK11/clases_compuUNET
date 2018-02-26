//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
using namespace std;

#include "bitsWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TbitsF5 *bitsF5;
//---------------------------------------------------------------------------
__fastcall TbitsF5::TbitsF5(TComponent* Owner)
	: TForm(Owner)
{
	cont=0;
    LE3->Text=AnsiString(cont);
}
//---------------------------------------------------------------------------
void __fastcall TbitsF5::B1Click(TObject *Sender)
{
    LE1->Text = AnsiString( (781<<4) & (65450) | (123) );
    LE2->Text = AnsiString( (2723>>2) & (65450) | (123<<2) );
}
//---------------------------------------------------------------------------
void __fastcall TbitsF5::B2Click(TObject *Sender)
{
	cont++;
    cont=cont&3;
    LE3->Text=AnsiString(cont);
}
//---------------------------------------------------------------------------
void __fastcall TbitsF5::E1KeyPress(TObject *Sender, char &Key)
{
	if (Key!='1' && Key!='0' && Key!=8)Key=0;
}
//---------------------------------------------------------------------------
void __fastcall TbitsF5::B3Click(TObject *Sender)
{
	int RGB=0,R=0,G=0,B=0;
    char *z;

    RGB = strtol(E1->Text.c_str(), &z, 2);
    R=RGB&0x7C00;
    G=RGB&0x3E0;
    B=RGB&0x1F;

    L9->Text=AnsiString(bitset<16>(R).to_string<char,char_traits<char>,allocator<char> >().c_str());
    R>>=10;
    L9->Color=(TColor)RGB(R*255/31,0,0);

    L8->Text=AnsiString(bitset<16>(G).to_string<char,char_traits<char>,allocator<char> >().c_str());
    G>>=5;
    L8->Color=(TColor)RGB(0/31,G*255/31,0);

    L10->Text=AnsiString(bitset<16>(B).to_string<char,char_traits<char>,allocator<char> >().c_str());
    L10->Color=(TColor)RGB(0,0,B*255/31);

    L11->Color=(TColor)RGB(R*255/31,G*255/31,B*255/31);
}
//---------------------------------------------------------------------------

