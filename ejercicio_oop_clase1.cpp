// Actividad: 3 pts
//Usar la siguiente clase e implementarla para N estudiantes
//Dentro del ciclo se valide las notas, que sea del 1 al 9
//Para N estudiantes

#include <iostream>
#include <conio.h>
using namespace std;

class ESTUDIANTE
{
	public:
		void cargar();
		void promedio();
		void listar(); //Mostrar los datos
	
	private:
		char nom[12];
		int notas[3]; //Validar 1 - 9
		float prom	
};

void ESTUDIANTE::cargar()
{
	cout << "Ingrese nombre del estudiante: " << endl;
	cin >> nombre;
	for (int i=0;i<3;i++)
	{
		cout << "Ingrese nota numero " << i+1 << endl;
		cin << notas[i];		
	}
}
