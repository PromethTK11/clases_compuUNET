#include <iostream>
#include <conio>

// Ejemplo de clases POO 30-01-2018

using namespace std;

class NUMERO
{

	public:
		void leer();
		void mostrar();

	private:
		int x;

};

void NUMERO::leer()
{
	cout << "Dar X:";
	cin >> x;
}

void NUMERO::mostrar()
{
	cout << "x= " << x << endl;
}
 /* version 1
 void main ()
{
	NUMERO entero;
	entero.leer();
	entero.mostrar();
	getch();
}*/

/* version 2
void main(){
        NUMERO entero,natural;
        entero.leer();
        natural.leer();
        entero.mostrar();
        natural.mostrar();
        getch();
}
*/

//Version 3

void main(){
        NUMERO entero[10];
        for (int i=0; i<10; i++)
        {
                entero[i].leer();
        }
        for (int i=0; i<10; i++)
        {
                entero[i].mostrar();
        }
        detch();
}

