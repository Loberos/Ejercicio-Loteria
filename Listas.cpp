#include "pch.h"
#include<fstream>
#include <conio.h>
#include "CPersona.h"
#include "CLista.h"
using namespace System;


CPersona* RegistrarDatosPersona() {
	string nombre, direccion, telefono, numeroGanado;
	int edad;
	cout << "Ingrese su Nombre: "; cin >> nombre;cout << endl;
	cout << "Ingrese su Direccion: "; cin >> direccion; cout << endl;
	cout << "Ingrese su Telefono: "; cin >> telefono; cout << endl;
	cout << "Ingrese su Edad: "; cin >> edad; cout << endl;
	cout << "Ingrese su Numero Obtenido (6 Digitos): "; cin >> numeroGanado; cout << endl;
	CPersona* objPersona = new CPersona(nombre, direccion, telefono, edad, numeroGanado);
	return objPersona; 	
}
void agregarPersona(Lista<CPersona*>* Lista) {
	cout << "::::::::::::::::Registar Jugador " << Lista->longitud() + 1 << " ::::::::::::::::" << endl;
	CPersona* objPersona = RegistrarDatosPersona(); 
	if (objPersona != nullptr) {
		Lista->agregaInicial(objPersona);
	}
}
void NumeroGanadoreExacto(Lista<CPersona*>* Lista, string numeroGanador, float POZO) {
	int conGanadores = 0; 

	for (int i = 0; i < Lista->longitud(); i++)
	{
		CPersona* objPersona = Lista->obtenerPos(i);	
		if (objPersona->getNumeroComprado() == numeroGanador) {
			objPersona->setDinero(true); 
			cout << "El numero de ganadores: " << conGanadores++ << endl; 
			cout << objPersona->datos() << endl; 
		}
	}
	for (int i = 0; i < Lista->longitud(); i++)
	{
		CPersona* objPersona = Lista->obtenerPos(i); 
		if (objPersona->getNumeroComprado() == numeroGanador) {
			objPersona->setDinero(POZO / conGanadores); 
		}
	}
	if (conGanadores > 1) {
		cout << "Los " << conGanadores << " ganadores se reparten el premio de " << POZO << endl;
		cout << "y cada uno obtiene: " << POZO / conGanadores << " soles "<<endl;
	}
	else if (conGanadores == 1) {
		cout << "El dinero que obtendra sera " << POZO << endl;
	}
	else cout << "No hay ganadores" << "\n";
}
void NumeroGanadores4Digitos(Lista<CPersona*>* Lista, string numeroGanador, float POZO4) {
	int contGanador = 0; 
	int character = 0;
	for (int i = 0; i < Lista->longitud(); i++)
	{
		CPersona* objPersona = Lista->obtenerPos(i);
		string numeroJugador = objPersona->getNumeroComprado(); 
		for (int j = 0; j < numeroGanador.size(); j++)
		{
			if (numeroJugador != numeroGanador && numeroGanador[j] == numeroJugador[j]) {
				character++;
				if (character == 4) {
					objPersona->setGanador(true); 

					cout << "Ganador: " << contGanador++ << endl; 
					objPersona->setDinero(POZO4); 
				}
			}
		}
	}
}

void Menu() {
	Lista<CPersona*>* lst = new Lista<CPersona*>(
		[](CPersona* p1, CPersona* p2) {
			if (p1->datos() > p2->datos()) return 1;
			else if (p1->datos() < p2->datos()) return -1;
			else return 0; });
	string numeroGanador; 
	int pozo = 1000000.0;
	int pozo2 = 20000.0;
	int opcion; 
	do
	{
		cout << ":::::::::::::: MENU ::::::::::::::::::::" << endl;
		cout << "1. Ingresar Jugador" << endl;
		cout << "2. Realizar Sorteo" << endl;
		cout << "3. Ver Ganadores Numero Exacto" << endl;
		cout << "4. Ver Ganadores 4 Digitos Iguales" << endl; 
		cout << "5. Salir" << endl;
		cout << "Ingresar Opcion: "; cin >> opcion; cout << endl;
		switch (opcion)
		{
		case 1: 
			agregarPersona(lst);
			system("pause");
			break; 
		case 2: 
			cout << "Ingrese el numero ganador: ";
			cin >> numeroGanador;
			system("pause");
			break;
		case 3: 
			cout << "=GANADORES NUMERO EXACTO=\n";
			NumeroGanadoreExacto(lst, numeroGanador,pozo);
			system("pause");
			break;
		case 4: 
			NumeroGanadores4Digitos(lst, numeroGanador, pozo2); 
			system("pause");
			break;
		}
		system("cls");
	} while (opcion!=5);
}

int main()
{
	Menu(); 
	_getch(); 
	return 0; 
}
