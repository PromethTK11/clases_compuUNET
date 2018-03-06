//---------------------------------------------------------------------------

#include <vcl.h>
#include <memory> 	//Para las funciones SaveCells y LoadCells
#include <fstream>
#pragma hdrstop

#include "ventanaTablero.h"
#include "ventanaPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
    check=0;
    s=0;
    m=0;
}
//----------------------------------------------------------------------------
//Funci�n para guardar la stringbox.
//Source: Una revista del 2002 de BCB

void __fastcall SaveCells(TStringGrid* StringGrid,const AnsiString& FileName)
{
	std::auto_ptr<TStrings> SaveStrings(new TStringList()); //Crea un StringList temporal
	const int col_count = StringGrid->ColCount;

	for (int index = 0; index < col_count; ++index) //Lo llena con la info del actual
        {
    		SaveStrings->AddStrings(StringGrid->Cols[index]);
  	}

  	SaveStrings->SaveToFile(FileName); //Y lo guarda usando la funcion SaveToFile(Presente en la clase TStrings)
}

//---------------------------------------------------------------------------

void __fastcall TForm2::SG1SelectCell(TObject *Sender, int ACol, int ARow,
      bool &CanSelect)
{
        //ACol y ARow son variables int propias de estos objetos
        //Estas varibles representan la casilla seleccionada
	x = ACol;
	y = ARow;
	SG1->Hint=AnsiString(Form1->results[(Form1->agrup[x][y])-1]);
	if(Form1->sqAgrup[(Form1->agrup[x][y])-1] > 1)
        	SG1->Hint=SG1->Hint +" "+ AnsiString(Form1->operations[(Form1->agrup[x][y])-1]);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LE1KeyPress(TObject *Sender, char &Key)
{
	if ((Key<'1' || Key>Form1->nivel+48) && Key!=8)Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::B1Click(TObject *Sender)
{
    check=1;
	for(int i=0;i<Form1->nivel;i++)
    {
        for(int j=0;j<Form1->nivel;j++)
        {
            if(SG1->Cells[i][j].IsEmpty())
            {
                check=0;
                i=Form1->nivel;
                j=Form1->nivel;
            }
            else if(SG1->Cells[i][j]!=AnsiString(Form1->tablero[i][j]))
            {
                check=0;
                i=Form1->nivel;
                j=Form1->nivel;
            }
        }
    }
    if(check)
    {
        Timer1->Enabled=false;
        ShowMessage("�Correcto! Nivel "+AnsiString(Form1->nivel)+"x"+AnsiString(Form1->nivel)+" completado en "+L1->Caption);
        Close();
    }
    else
    {
       ShowMessage("Respuesta Incorrecta");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SG1KeyPress(TObject *Sender, char &Key)
{
    if((Key<'1'||Key>Form1->nivel+48) &&Key!=8)
        Key=0;
    else if(SG1->Cells[x][y].Length()>0)
        SG1->Cells[x][y]="";
}
//---------------------------------------------------------------------------

//Esta funci�n maneja el renderizado de las cells
//Como la propiedad SG1->DefaultDrawing==false
//Tenemos que definir todo lo que normalmente manejaria el IDE
//La ventaja es que tenemos completo control del renderizado
//Por lo tanto, este proyecto se beneficia de eso
void __fastcall TForm2::SG1DrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{

        //Canvas para tener la font default
	TCanvas* SGCanvas = SG1->Canvas;
    	SGCanvas->Font = SG1->Font;

        //Esto funciona asi
        //Cada vez que renderiza chequea cada celda
        //Y busca ciertas condiciones...
	RECT RText = static_cast<RECT>(Rect);
	const AnsiString text(SG1->Cells[ACol][ARow]);

        //Determina si la celda esta focused
	const bool focused = State.Contains(gdFocused);

        //Determina si le diste click a una celda
	bool selected = State.Contains(gdSelected);

    if (!SG1->Options.Contains(goDrawFocusSelected))
		selected = selected && !focused;


	// Si la celda est� seleccionada...
	if (selected)
        {
   		SGCanvas->Brush->Color = clHighlight;
		SGCanvas->Font->Color = clHighlightText;
		SGCanvas->FillRect(Rect);
  	}

 	 // Y si la celda es normal...
 	else
        {
		SGCanvas->Brush->Color = SG1->Color;
    		SGCanvas->Font->Color = SG1->Font->Color;
    		SGCanvas->FillRect(Rect);
  	}

    //Colorizado de los grupos
    //Esto le hace overwritte a los colores de arribas, ya que arriba es solo para definir
    //Pero es necesario para definir los grupos
    	for (int z=0; z<Form1->cantAgrup; z++)
        {
          	for (int i=0; i<Form1->nivel; i++)
                {
                        for (int j=0; j<Form1->nivel; j++)
                        {
                        	if (i==ACol&&j==ARow&&z+1==Form1->agrup[i][j])
                                {
                                	SGCanvas->Brush->Color = TColor(Form1->colors[z]);
                                    if(Form1->colors[z]<0x5fffff)
                                        SGCanvas->Font->Color = clWhite;
                                    else
					                    SGCanvas->Font->Color = clBlack;
					                SGCanvas->FillRect(Rect);
                                }

                        }
                }
        }

    // Entonces, si la celda esta focused
	if (focused)
        	DrawFocusRect(SGCanvas->Handle, &RText);

    // Renderiza el texto y lo centra en la cell
    RText.left += 2; RText.top += 2;
  	DrawText(SGCanvas->Handle, text.c_str(), text.Length(), &RText, DT_CENTER | DT_VCENTER |DT_SINGLELINE);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormDestroy(TObject *Sender)
{
    if(check){
        if(Form1->nivel<9)
        {
            Form1->nivel++;
            if(MessageDlg("�Continuar con el siguiente nivel?", mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
                Form1->T11->Click();
        }
        else
            ShowMessage("Enhorabuena, �usted es el ganador absoluto del juego!");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    s++;
    if(s>59)
    {
        m++;
        s=0;
    }
    if(m==Form1->nivel)
    {
        Timer1->Enabled=false;
        ShowMessage("Tiempo Agotado");
        check=0;
        Close();
    }
    L1->Caption=AnsiString(m)+":"+AnsiString(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{
    Timer1->Enabled=true;
    fl1=true;
    if (Form1->cargar==true)
    {
        int trash;
    	ifstream info;
        info.open("data\\info.txt");
        info >> trash;
        info >> trash;
        info >> (int)s;
        info >> (int)m;
        info.close();
        Form1->cargar=false;
    }

    for(int k=0;k<Form1->cantAgrup;k++)
    {
        char labeled='N';
        for(int i=0;i<Form1->nivel;i++)
        {
            for(int j=0;j<Form1->nivel;j++)
            {
                if((k+1)==Form1->agrup[j][i]&&labeled=='N')
                {
                    labeled='S';
                    TLabel* pista = new TLabel(this);
                    pista->Parent = SG1;
                    pista->Caption=AnsiString(Form1->results[(Form1->agrup[j][i])-1]);
                    if(Form1->sqAgrup[(Form1->agrup[j][i])-1] > 1)
        	            pista->Caption=pista->Caption+" "+ AnsiString(Form1->operations[(Form1->agrup[j][i])-1]);
                    pista->AutoSize=false;
                    pista->Font->Size=8;
                    //pista->Color=clWhite;
                    //pista->Font->Color=clBlack;
                    pista->Width=50;
                    pista->Height=10;
                    pista->Visible=true;
                    pista->Top=i*60+5+i;
                    pista->Left=j*60+j+10;
                    pista->Color = TColor(Form1->colors[k]);
                                    if(Form1->colors[k]<0x5fffff)
                                        pista->Font->Color = clWhite;
                                    else
					                    pista->Font->Color = clBlack;

                }
            }
        }
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::B4Click(TObject *Sender)
{
        if (fl1==true)
        {
        	int randNum1,randNum2;
		randNum1 = rand()%(Form1->nivel);
	        srand(time(NULL));
        	randNum2  = rand()%(Form1->nivel);
                srand(time(NULL));
	        SG1->Cells[randNum1][randNum2]=AnsiString(Form1->tablero[randNum1][randNum2]);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::B2Click(TObject *Sender)
{
	if (fl1==true)
        {
                Timer1->Enabled=false;
        	fl1=false;
                SG1->Visible=false;
                B2->Caption="| >";
        }
        else
        {
                Timer1->Enabled=true;
        	fl1=true;
                SG1->Visible=true;
                B2->Caption="| |";
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm2::B3Click(TObject *Sender)
{
        SG1->Visible=false;

	SaveCells(SG1, "data\\savedGame.txt");

        for(int i=0;i<Form1->nivel;i++)
    	{
        	for(int j=0;j<Form1->nivel;j++)
        	{
            		SG1->Cells[i][j]=AnsiString(Form1->tablero[i][j]<<18);
	        }
        }
        SaveCells(SG1, "data\\savedResult.txt");

        for(int i=0;i<Form1->nivel;i++)
    	{
        	for(int j=0;j<Form1->nivel;j++)
        	{
            		SG1->Cells[i][j]=AnsiString(Form1->agrup[i][j]);
	        }
        }
        SaveCells(SG1, "data\\savedGroups.txt");

        ofstream info;
        info.open("data\\info.txt");
        info << Form1->nivel << endl << Form1->cantAgrup
        	<< endl << s << endl << m;
        info.close();
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::B5Click(TObject *Sender)
{
	MessageDlg("Para ver la pista/operaci�n de un grupo:\n\nDale click a un cuadro del grupo, seleccionandolo, y deja el click encima de cualquier lugar del grid un segundo, aparecer� la pista/operaci�n abajo del cursor", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

