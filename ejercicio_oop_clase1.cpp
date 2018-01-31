// Actividad: 3 pts
//Usar la siguiente clase e implementarla para N estudiantes
//Dentro del ciclo se valide las notas, que sea del 1 al 9
//Para N estudiantes

#include <iostream>
#include <string>

using namespace std;

class ESTUDIANTE
{
	public:
		void cargar();
		void promedio();
		void listar(); //Mostrar los datos
	
	private:
		string nom;
		int notas[3]; //Validar 1 - 9
		float prom;
};

void ESTUDIANTE::cargar()
{
	cout << "Ingrese nombre del estudiante: " << endl;
	cin.ignore(256, '\n');	//para limpiar el \n en enter, como un fflush
	getline(cin, nom);	//se usa getline en vez de cout para mantener espacios en nombres
	for (int i=0;i<3;i++)
	{
		do {
		cout << "Ingrese nota numero " << i+1 << " del 1 al 9" << endl;
		cin >> notas[i];
		} while (notas[i]<1 || notas[i]>9);
	}
}

void ESTUDIANTE::promedio()
{
	prom = 0;
	for (int i=0;i<3;i++)
	{
		prom += notas[i];
	}
	prom /= 3;
}

void ESTUDIANTE::listar()
{
	cout << nom << "\t" << notas[0] << "\t" << notas[1] << "\t" << notas[2] 
		<< "\t" << prom << endl;
}

int main(){
	ESTUDIANTE classroom[20];
	int n;
	cout << "Booting up... \nBienvenido\n" << endl;
		do {		
		cout << "Ingrese la cantidad de estudiantes que desee procesar (Del 1 al 20)" << endl;
		cin >> n;
		} while (n<1 || n>20);
	for (int k=0;k<n;k++)
	{
		classroom[k].cargar();
		classroom[k].promedio();
	}	
	cout << "Nombre\t\tNota 1\tNota 2\tNota 3\tPromedio" << endl;
	cout << "================================================" << endl;
	for (int k=0;k<n;k++)
	{
		classroom[k].listar();
	}	
	cout << "Cerrando programa..." << endl;
return 0;	
}


