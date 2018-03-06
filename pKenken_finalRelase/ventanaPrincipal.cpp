//---------------------------------------------------------------------------

#include <vcl.h>
#include <memory>	//Para cargar los string grids
#pragma hdrstop

#include "ventanaPrincipal.h"
#include "ventanaTablero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{

    nivel=3;
}
//---------------------------------------------------------------------------

//Funci�n para cargar la stringbox.
//Source: Una revista del 2002 de BCB

void __fastcall LoadCells(TStringGrid* StringGrid,const AnsiString& FileName)
{

	std::auto_ptr<TStrings> LoadStrings(new TStringList()); //Crea string temporal
	LoadStrings->LoadFromFile(FileName);	//Carga desde el archivo

	int index = 0;
	const int col_count = StringGrid->ColCount;
	const int row_count = StringGrid->RowCount;

	for (int col=0;col<col_count;++col)
	{
		for (int row=0;row<row_count;++row)
		{
			StringGrid->Cells[col][row] = LoadStrings->Strings[index++];
     		}
  	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_3Click(TObject *Sender)
{
    nivel=3;
    T13_S->Caption="Actual: 3x3";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_4Click(TObject *Sender)
{
    nivel=4;
    T13_S->Caption="Actual: 4x4";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_5Click(TObject *Sender)
{
    nivel=5;
    T13_S->Caption="Actual: 5x5";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_6Click(TObject *Sender)
{
    nivel=6;
    T13_S->Caption="Actual: 6x6";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_7Click(TObject *Sender)
{
    nivel=7;
    T13_S->Caption="Actual: 7x7";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_8Click(TObject *Sender)
{
    nivel=8;
    T13_S->Caption="Actual: 8x8";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T13_9Click(TObject *Sender)
{
    nivel=9;
    T13_S->Caption="Actual: 9x9";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::T11Click(TObject *Sender)
{
    TForm2* game = new TForm2(this);
    int conteo;
    cantAgrup=0;

    game->ClientHeight = (60*nivel)+nivel+10;
    game->ClientWidth = (60*nivel)+nivel+10+game->P1->Width;
    game->SG1->Left = 5;
    game->SG1->Top = 5;
    game->SG1->Height = (60*nivel)+nivel+5;
    game->SG1->Width = (60*nivel)+nivel+5;
    game->SG1->ColCount=nivel;
    game->SG1->RowCount=nivel;
    game->Position=poDesktopCenter;

    ShowMessage("La partida se generar� al presionar \"Ok\", por favor tenga paciencia.");

    for(int i=0;i<nivel;i++) //Llenado de la matriz basica
    {
        conteo=i+1;
        for(int j=0;j<nivel;j++)
        {
            tablero[i][j]=conteo;
            conteo++;
            if(conteo>nivel)conteo=1;
        }
    }

    for(int i=0;i<(nivel/2+1);i++) //Aleatorizando filas
    {
        int randNum1,randNum2;
        do
        {
            srand(time(NULL)+i*nivel*100);
            randNum1 = rand() % (nivel);
            srand(time(NULL)-i*nivel*100);
            randNum2  = rand() % (nivel);
        }while(randNum1==randNum2);
        int tempVector[9];
        for(int j=0;j<nivel;j++)
        {
            tempVector[j]=tablero[randNum1][j];
        }
        for(int j=0;j<nivel;j++)
        {
            tablero[randNum1][j]=tablero[randNum2][j];
        }
        for(int j=0;j<nivel;j++)
        {
            tablero[randNum2][j]=tempVector[j];
        }
    }
    for(int i=0;i<(nivel/2+1);i++)  //Aleatorizando Columnas
    {
        int randNum1,randNum2;
        do
        {
            srand(time(NULL)/(i*nivel+1));
            randNum1 = rand() % (nivel);
            srand(time(NULL)/(i*nivel-1));
            randNum2  = rand() % (nivel);
        }while(randNum1==randNum2);
        int tempVector[9];
        for(int j=0;j<nivel;j++)
        {
            tempVector[j]=tablero[j][randNum1];
        }
        for(int j=0;j<nivel;j++)
        {
            tablero[j][randNum1]=tablero[j][randNum2];
        }
        for(int j=0;j<nivel;j++)
        {
            tablero[j][randNum2]=tempVector[j];
        }
    }

    for(int i=0;i<nivel;i++) //Conversion de agrup a matriz de ceros
    {
        for(int j=0;j<nivel;j++)
        {
            agrup[i][j]=0;
        }
    }
    for(int i=0;i<nivel;i++) //Conversion de agrup a matriz de ceros
    {
        for(int j=0;j<nivel;j++)
        {
            if(agrup[i][j]==0)
            {
                do
                {
                    sucess='S';
                    int side,squares;
                    srand(time(NULL)/rand()/(cantAgrup+1));
                    side=rand() % 2;
                    srand(time(NULL)/rand()*(cantAgrup+1));
                    if(nivel<5)squares=rand() % nivel + 1;
                    else squares=rand() % 5 + 1;
                    if(i==nivel-1)
                        side=0;
                    if(j==nivel-1)
                        side=1;
                    if(j==nivel-1&&i==nivel-1)
                        squares=1;

                    if(side==1)
                    {
                        for(int k=0;k<squares;k++)
                        {
                            if((i+squares)>nivel)
                            {
                                sucess='N';
                                k=squares;
                            }
                            else if(agrup[i+k][j]>0)
                            {
                                sucess='N';
                                k=squares;
                            }
                        }
                        if(sucess=='S')
                        {
                            cantAgrup++;
                            sqAgrup[cantAgrup-1]=0;
                            for(int k=0;k<squares;k++)
                            {
                                sqAgrup[cantAgrup-1]++;
                                agrup[i+k][j]=cantAgrup;
                            }
                        }
                    }
                    if(side==0)
                    {
                        for(int k=0;k<squares;k++)
                        {
                            if((j+squares)>nivel)
                            {
                                sucess='N';
                                k=squares;
                            }
                            else if(agrup[i][j+k]>0)
                            {
                                sucess='N';
                                k=squares;
                            }
                        }
                        if(sucess=='S')
                        {
                            cantAgrup++;
                            sqAgrup[cantAgrup-1]=0;
                            for(int k=0;k<squares;k++)
                            {
                                sqAgrup[cantAgrup-1]++;
                                agrup[i][j+k]=cantAgrup;
                            }
                        }
                    }
                }while(sucess=='N');
            }
        }
    }
    for(int i=0;i<cantAgrup;i++)
    {
        results[i]=0;
        if(cantAgrup<50)
            colors[i] = (0xffffff/50)*i;
        else
            colors[i] = (0xffffff/cantAgrup)*i;
        int numOp;
        srand(time(NULL)/(i+1));
        numOp=rand() % 3;
        if(numOp==0)
            operations[i]='+';
        if(numOp==1)
            operations[i]='-';
        if(numOp==2)
            operations[i]='*';
    }

    for(int k=0;k<cantAgrup;k++)
    {
        for(int i=0;i<nivel;i++)
        {
            for(int j=0;j<nivel;j++)
            {
                if(k+1==agrup[i][j])
                {
                    if(sqAgrup[k]==1)
                        operations[k]='.';
                    if(results[k]==0)
                        results[k]=tablero[i][j];
                    else{
                        if(results[k]%tablero[i][j]==0&&sqAgrup[k]==2)
                        {
                            operations[k]='/';
                            results[k]/=tablero[i][j];
                        }
                        else if(tablero[i][j]%results[k]==0&&sqAgrup[k]==2)
                        {
                            operations[k]='/';
                            results[k]=tablero[i][j]/results[k];
                        }
                        if(operations[k]=='+')
                            results[k]+=tablero[i][j];
                        if(operations[k]=='-')
                            results[k]-=tablero[i][j];
                        if(operations[k]=='*')
                            results[k]*=tablero[i][j];



                    }
                }
            }
        }
    }
/* Resultado for cheaters:
	for(int i=0;i<nivel;i++)
    	{
        	for(int j=0;j<nivel;j++)
        	{
            		game->SG1->Cells[i][j]=AnsiString(tablero[i][j]);
	        }
        } */
    game->ShowModal();
    delete game;
    game = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T4Click(TObject *Sender)
{
	MessageDlg("Realizado Por:\n\nLino Ruben Maldonado Ramirez\n\nCedula: V-27.239.681\n\nCarlos Alfredo de Jesus Morales Mora\n\nCedula: V-26.934.960", mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T5Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T12Click(TObject *Sender)
{
        ifstream inform;
        inform.open("data\\info.txt");
        inform >> (int)nivel;
        inform >> (int)cantAgrup;
        inform >> (int)Form2->s;
        inform >> (int)Form2->m;
        inform.close();

        TForm2* game = new TForm2(this);
	int conteo;

	game->ClientHeight = (60*nivel)+nivel+10;
    	game->ClientWidth = (60*nivel)+nivel+10+game->P1->Width;
    	game->SG1->Left = 5;
    	game->SG1->Top = 5;
    	game->SG1->Height = (60*nivel)+nivel+5;
    	game->SG1->Width = (60*nivel)+nivel+5;
    	game->SG1->ColCount=nivel;
    	game->SG1->RowCount=nivel;
    	game->Position=poDesktopCenter;

	ShowMessage("La partida se cargar� al presionar \"Ok\", por favor tenga paciencia.");

        game->SG1->Visible=false;

        LoadCells(game->SG1, "data\\savedGroups.txt");
        for(int i=0;i<nivel;i++)
    	{
        	for(int j=0;j<nivel;j++)
        	{
            		agrup[i][j]=game->SG1->Cells[i][j].ToInt();
	        }
        }

        LoadCells(game->SG1, "data\\savedResult.txt");
        for(int i=0;i<Form1->nivel;i++)
    	{
        	for(int j=0;j<Form1->nivel;j++)
        	{
                	tablero[i][j]=((game->SG1->Cells[i][j].ToInt())>>18);
	        }
        }

        LoadCells(game->SG1, "data\\savedGame.txt");

        game->SG1->Visible=true;

    for(int i=0;i<cantAgrup;i++)
    {
        results[i]=0;
        if(cantAgrup<50)
            colors[i] = (0xffffff/50)*i;
        else
            colors[i] = (0xffffff/cantAgrup)*i;
        int numOp;
        srand(time(NULL)/(i+1));
        numOp=rand() % 3;
        if(numOp==0)
            operations[i]='+';
        if(numOp==1)
            operations[i]='-';
        if(numOp==2)
            operations[i]='*';
    }

    for(int k=0;k<cantAgrup;k++)
    {
        for(int i=0;i<nivel;i++)
        {
            for(int j=0;j<nivel;j++)
            {
                if(k+1==agrup[i][j])
                {
                    if(sqAgrup[k]==1)
                        operations[k]='.';
                    if(results[k]==0)
                        results[k]=tablero[i][j];
                    else{
                        if(results[k]%tablero[i][j]==0&&sqAgrup[k]==2)
                        {
                            operations[k]='/';
                            results[k]/=tablero[i][j];
                        }
                        else if(tablero[i][j]%results[k]==0&&sqAgrup[k]==2)
                        {
                            operations[k]='/';
                            results[k]=tablero[i][j]/results[k];
                        }
                        if(operations[k]=='+')
                            results[k]+=tablero[i][j];
                        if(operations[k]=='-')
                            results[k]-=tablero[i][j];
                        if(operations[k]=='*')
                            results[k]*=tablero[i][j];



                    }
                }
            }
        }
    }



    /*SG1->Hint=AnsiString(Form1->results[(Form1->agrup[x][y])-1]);
	if(Form1->sqAgrup[(Form1->agrup[x][y])-1] > 1)
        	SG1->Hint=SG1->Hint +" "+ AnsiString(Form1->operations[(Form1->agrup[x][y])-1]);
    */
    cargar=true;
    game->ShowModal();
    delete game;
    game = NULL;

}
//---------------------------------------------------------------------------

