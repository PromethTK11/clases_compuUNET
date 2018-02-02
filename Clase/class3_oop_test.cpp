//Ejemplo made by me, no de la clase

#include <iostream>

using namespace std;

class ship{
	public:
		void move();				//Public -> Puede ser accedida hasta por el yomber "cara e rata" y el pulgas
	private:
		int casilla=0;				// Private -> Solo se pueden acceder por las funciones de public
	protected:
		char h = 'h';				//Prueba de protegido -> Se puede acceder solo por los hijos de esta funcion, y por esta
};

class fighter:public ship{
	public:
		void shoot();
	private:
		int shotsfired=0;
};

void ship::move(){
	cout << "Te mueves 1 casilla, ahora estas en: " << casilla+1 << endl;
	casilla++;
	cout << h << endl;
}

void fighter::shoot(){
	cout << "Disparas 1 misil, hasta ahora has disparado: " << shotsfired+1 << endl;
	shotsfired++;
}

int main(){
	ship kestrel;
	fighter tristan;
	barge ss;
	char resp;
	int resp1;
	do{
		 cout << "Comande la nave tristan, 1 para mover, 2 para disparar: " << endl;
		cin >> resp1;
		if (resp1==1)tristan.move();
		if(resp1==2)tristan.shoot();
		cout << "Desea seguir?: (S/N)" << endl;
		cin.sync();
		cin >> resp;
	}while (resp != 'N');
	do{
		cout << "Comande la nave kestrel, 1 para mover: " << endl;
		cin >> resp1;
		if (resp1==1)kestrel.move();
		cout << "Desea seguir?: (S/N)" << endl;
		cin.sync();
		cin >> resp;
	}while (resp != 'N');
	return 0;
}

