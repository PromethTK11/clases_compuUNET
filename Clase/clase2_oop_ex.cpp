//Clase 31-01-18 EJEMPLO DE CLASE

#include <iostream>
#include <conio.h>
#include <ctype.h>

using namespace std;

class EMPLEADO
{
	public:
		void leer(int);
		void maysueldo(float &, int *, int);
		void mostrar();
	private:
		char nom[12], ci[10];
		float sueldo;
};

//Diseño de los métodos de la clase

void EMPLEADO::leer(int e)
{
	cout << "Dats del empleado No. " << e+1 << endl;
	cout << "Dar Cedula:" << endl;
	cin >> ci;
	cout << "Dar nombre: " << endl;
	cin >> nom;
	cout << "Dar sueldo: " << endl;
	do{
		cin>>sueldo;
		if (sueldo<=0) cout << "ERROR: Sueldo incorrecto..." << endl;
	}while (sueldo<=0);
}

void EMPLEADO::maysueldo(float &may, int *pos, int aux)
{
	if (sueldo>may)
	{
		may = sueldo;
		*pos = aux;
	}
}

void EMPLEADO::mostrar()
{
	cout << "Nombre: " << nom << endl;
	cout << "Cedula: " << ci;
}

//Cuerpo principal AKA main you fucc

void main()
{
	EMPLEADO unet[10];
	char resp;
	int cp=0,posx=-1;
	float mayx=0;
	do{
		unet[cp].leer(cp);
		cout << "Existe otro empleado a procesar? (S/N):" << endl;
		cin >> resp;
		resp = toupper(resp);
		cp++;
	}while (resp == 'S'&& cp<10);
	for (int k=0;k<cp;k++) 
	{
	unet[k].maysueldo(mayx, &posx, k);
	}
	clrscr();
	cout << "El mayor sueldo entre los empleados procesados es: " << mayx
		<< " Bs. y le corersopnde a: " <<endl;
	unet[posx].mostrar();
	cout << "\nFin del programa,\tcerrando...";
	getch();
}
