//SHIPS BARCOS EN PUERTO CABELLO//////////
#include <iostream>

using namespace std;

//Clases de barcos////////////////

class BARCO{
	public:
		void registrar();
		void mostrarNom();
	private:
		char nombre[20];
	protected:
		int estado;
};

class CRUCER: public BARCO{
	public:
		void registrar();
		void alerta();
	private:
		int nTuristas;
};

class CARRIER: public BARCO{
	public:
		void registrar();
		void alerta();
	private:
		int nCrew;
		int nAviones;
};

class PESQUERO: public BARCO{
	public:
		void registrar();
		void alerta();
	private:
		int nPescador;
		int clasific; //1 = Atunero, 2 = Palangrero, 3 = Cerquero//
};

//Diseño de los métodos barco

void BARCO::registrar(){
	cout<<"Ingrese el nombre del barco:"<<endl;
	cin.getline(nombre,20);	
	do{
	cout<<"Ingrese el estado del barco (1 para navegando, 2 para anclado)\n";
	cin>>estado;
	if (estado !=1 && estado !=2)cout<<"ERROR: Valor invalido, ingrese 1 o 2\n";
	}while(estado != 1 && estado !=2);
}

void BARCO::mostrarNom(){
	cout << nombre;
}


//Diseño de los métodos crucero

void CRUCER::registrar(){
	BARCO::registrar();
	do{
	cout<<"Ingrese la cantidad de turistas en el crucero\n";
	cin>>nTuristas;
	if (nTuristas < 0)cout<<
		"ERROR: Valor invalido, ingrese un valor positivo\n";
	}while(nTuristas<0);
}

void CRUCER::alerta(){
	if (estado == 1){
		mostrarNom();
		cout << " EN ALTAMAR CON: " 
			<< nTuristas << " TRIPULANTES, EMERGENCIA" << endl; 
	}
}

//Diseño de los métodos carrier

void CARRIER::registrar(){
	BARCO::registrar();
	do{
	cout<<"Ingrese la cantidad de tripulantes en el porta-aviones\n";
	cin>>nCrew;
	if (nCrew < 0)cout<<
		"ERROR: Valor invalido, ingrese un valor positivo\n";
	}while(nCrew<0);
	do{
	cout<<"Ingrese la cantidad de aviones en el porta-aviones\n";
	cin>>nAviones;
	if (nAviones < 0)cout<<
		"ERROR: Valor invalido, ingrese un valor positivo\n";
	}while(nAviones<0);
}

void CARRIER::alerta(){
	if (estado == 1){
		mostrarNom();
		cout << " EN ALTAMAR CON: " 
			<< nCrew << " TRIPULANTES, EMERGENCIA" << endl; 
	}
}

//Diseño de los métodos pesquero

void PESQUERO::registrar(){
	BARCO::registrar();
	do{
	cout<<"Ingrese la cantidad de pescadores en el pesquero\n";
	cin>>nPescador;
	if (nPescador < 0)cout<<
		"ERROR: Valor invalido, ingrese un valor positivo\n";
	}while(nPescador<0);
	do{
	cout<<"Ingrese el tipo del pesquero (1 = Atunero, 2 = Palangrero, 3 = Cerquero)\n";
	cin>>clasific;
	if (clasific < 0 || clasific > 3)cout<<
		"ERROR: Valor invalido, ingresar 1, 2 o 3 para la clasificacion\n";
	}while(clasific < 0 || clasific > 3);
}

void PESQUERO::alerta(){
	if (estado == 1){
		mostrarNom();
		cout << " EN ALTAMAR CON: " << nPescador
			<< " TRIPULANTES, ALERTA" << endl; 
	}
}

//CUERPO PRINCIPAL

int main(){
	int resp=0,cpor=0,cpes=0,ccrus=0;	//Cpor = C carriers, Cpes = C pesquero, Ccrus = C cruceros
	int tipo=0;
	int nBarcos;
	CARRIER porta[30];
	PESQUERO pesq[30];
	CRUCER cruceros[30];
	cout << "Iniciando programa barcosControl.exe... Presione una tecla para continuar" << endl;
	cin.get();
	
	do{
		do{
			system("cls");
			cout<<"\t[[[MENU]]]\n"<<endl;
			cout<<"Seleccione una accion con un numero:"<<endl
				<<"1.-\tRegistrar un barco"<<endl
				<<"2.-\tActivar alerta de tifon"<<endl
				<<"3.-\tSalir del programa"<<endl
				<<"OPCION: ";
			cin >> resp;
			if (resp<1 || resp>3){
				cout<<"ERROR: Valor invalido, ingrese una opcion valida\n";
				cin.sync();
				cin.get();
			}
			cin.sync();
		}while(resp<1||resp>3);
		
		if (resp==1){
				
			do{
				system("cls");
				cout<<"Seleccione un tipo de embarcacion con un numero:"<<endl
				<<"1.-\tPesquero"<<endl
				<<"2.-\tCrucero"<<endl
				<<"3.-\tPorta-Aviones"<<endl
				<<"TIPO: ";
				cin>>tipo;
				if (tipo < 0 || tipo > 3){
					cout<<"ERROR: Valor invalido, ingresar 1, 2 o 3 para la clasificacion\n";
					cin.sync();
					cin.get();
				}
				cin.sync();
			}while(tipo < 0 || tipo > 3);
			
			if (tipo==3){
				porta[cpor].CARRIER::registrar();
				cpor++;
				cin.get();
			}
			
			if (tipo==2){
				cruceros[ccrus].CRUCER::registrar();
				ccrus++;
				cin.get();
			}
			
			if (tipo==1){
				pesq[cpes].PESQUERO::registrar();
				cpes++;
				cin.get();
			}
		}
		cout << "Presione una tecla para continuar...";
		cin.sync();
		cin.get();
		
		if(resp==2){ 
			system("cls");
			cout << "Alerta de TIFON emitida, barcos en altamar..."<<endl;
			cout << "CRUCEROS:"<<endl;
			for (int z=0;z<ccrus;z++)cruceros[z].CRUCER::alerta();
			cout << endl;
			cout << "PESQUEROS:"<<endl;
			for (int p=0;p<cpes;p++)pesq[p].PESQUERO::alerta();
			cout << endl;
			cout << "PORTA-AVIONES:"<<endl;
			for (int i=0;i<cpor;i++)porta[i].CARRIER::alerta();
			cout << endl;
			cin.get();
		}
		
	}while(resp!=3);
	cout<<"\nCerrando programa...\t...\t...\nHasta luego :)";
	cin.get();
}
