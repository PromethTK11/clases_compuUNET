#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* HACIENDA lECHERA */

/*     Programa elaborado por:
Prometh C.I: @144854065900158976
Prometh friend1 C.I: asdasd
Prometh friend2 C.I: asdsad     */

struct cow {   //Estructura de datos de cada vaca
    char pseudonimo[30];
    int numpartos;
    float produccion;
    char raza; //C: Cebú, H: Holster, J: Jersey
    int vacunada; // 1=Si, 0= No
};

struct cow carga(){ //Funcion carga para montar las vacas en el camion de datos
    struct cow vaca;
    fflush(stdin);
    printf ("\nIngrese el pseudonimo de la vaca: ");
    gets(vaca.pseudonimo);
    fflush(stdin);
    do{
    	printf ("\nIngrese el numero de partos de %s: ", vaca.pseudonimo);
    	scanf("%d",&vaca.numpartos);
    	fflush(stdin);
    }while(vaca.numpartos<0);
    	printf ("\nIngrese la produccion de leche por dia de %s: ", vaca.pseudonimo);
    	scanf("%f",&vaca.produccion);
    	fflush(stdin);
    do{
        fflush(stdin);
        printf ("\nIngrese la raza de %s (C para Cebu, H para Holster, J para Jersey): ", vaca.pseudonimo);
        scanf("%c",&vaca.raza);
        vaca.raza = toupper(vaca.raza);
    }while(vaca.raza!='C' && vaca.raza!='H' && vaca.raza!='J');
    do{
    	fflush(stdin);
    	printf ("\nLa vaca se encuentra vacunada? (1 para Si, 0 para No): ");
    	scanf("%d",&vaca.vacunada);
    }while(vaca.vacunada!=1 && vaca.vacunada!=0);
    return vaca;
}

float leche(struct cow vacas[315], int dias, int i) //Funcion para calcular la prod de leche para 1, 15 y 30 dias, i=cantidad de vacas en el rancho
{
    int k=0;
    float lechetotal=0;
    for (k=0;k<i;k++)
    {
        lechetotal=vacas[k].produccion+lechetotal;
    }
    lechetotal=lechetotal*dias;
    return lechetotal;
}

int partos(struct cow vacas[315], int i) //Funcion para mostrar todos los partos, i=cantidad de vacas en el rancho
{
    int k=0;
    int partostotal=0;
    for (k=0;k<i;k++)
    {
        partostotal=vacas[k].numpartos+partostotal;
    }
    return partostotal;
}

void maspartos(struct cow vacas[315], int i) //Funcion para la mayor cantidad de partos de una vaca/vacas
{
    int k=0, mayorparto=0;
    for (k=0;k<i;k++)
    {
        if (vacas[k].numpartos>mayorparto) mayorparto=vacas[k].numpartos;
    }
    printf("\n\n\t\t[VACAS QUE MAS PARTOS HAN TENIDO]\n\t\t\(En este caso %d partos)", mayorparto);
    printf("\n\t|Nombre|\t|Raza|\t|Leche Producida|");
    for (k=0;k<i;k++)
    {
        if (vacas[k].numpartos==mayorparto)
        {
            printf("\n\t%s",vacas[k].pseudonimo);
            if (vacas[k].raza=='C')printf("\tCebu");
            if (vacas[k].raza=='H')printf("\tHolster");
            if (vacas[k].raza=='J')printf("\tJersey");
            printf("\t%.2f litros/dia",vacas[k].produccion);
        }
    }
}

void razalp(struct cow vacas[315], char raza, int i) //Partos y leche de la raza que ingrese
{
    int k=0;
    printf("\n\nListado de produccion y partos de las vacas no vacunadas de la raza:");
    if (raza=='C')printf(" Cebu");
    if (raza=='H')printf(" Holster");
    if (raza=='J')printf(" Jersey");
    printf("\n\n\t|Partos|\t|Leche producida|");
    for (k=0;k<i;k++)
    {
        if (vacas[k].vacunada==0&&vacas[k].raza==raza)
        {
            printf("\n\n\t%d",vacas[k].numpartos);
            printf("\t\t%.2f",vacas[k].produccion);
        }
    }
}

int main()
{
    struct cow rancho[315]; //rancho = Lista de vacas en la hacienda registradas
    int i=0;
    float lechetotal;
    char resp;
	printf ("\n\tBienvenido");
	do{
		rancho[i]=carga(); //funcion para almacenar datos de las vacas
        do{
			printf("\nDesea cargar la informacion de otra vaca?(s/n): ");
            fflush(stdin);
            scanf("%c",&resp);
            resp=toupper(resp);
		}while(resp!='S'&&resp!='N');
		i++;	
	}while (resp=='S');
	printf("\n Partos totales atendidos en la hacienda: %d",partos(rancho,i)); //Pregunta 2, partos totales
	maspartos(rancho,i); //Pregunta 3, vaca con mayor cantidad de partos
	printf ("\n");
	printf("\n Produccion de leche estimada en un dia \(1 dia):\t%.2f",leche(rancho,1,i));
    printf("\n Produccion de leche estimada en una semana \(7 dias):\t%.2f",leche(rancho,7,i)); //Pregunta 4, Produccion estimada de leche
    printf("\n Produccion de leche estimada en un mes \(30 dias):\t%.2f",leche(rancho,30,i));
    razalp(rancho,'C',i);
	razalp(rancho,'H',i); //Pregunta 5, Listado de informacion sobre las vacas
	razalp(rancho,'J',i);
    return 0;
}
