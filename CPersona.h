#pragma once
#include <iostream>
#include <string>
#include <functional>
using namespace std; 
using namespace System;
using std::to_string; 

class CPersona
{
public:
	CPersona(string _nombre, string _direccion, string _telefono, int _edad, string nombre);
	~CPersona();
	string datos();
	void setGanador(bool _ganador); 
	void setDinero(float _dinero); 
	bool getGanador(); 
	float getDinero(); 
	string getNombre(); 
	string getDireccion(); 
	string gettelefono(); 
	int getEdad(); 
	string getNumeroComprado(); 

private:
	string nombre, direccion; 
	string telefono;
	string numeroComprado; 
	int edad; 
	bool ganador;
	float dinero; 
};

CPersona::CPersona(string _nombre, string _direccion, string _telefono, int _edad, string _numeroComprado)
{
	this->nombre = _nombre;
	this->direccion = _direccion;
	this->telefono = _telefono;
	this->numeroComprado = _numeroComprado; 
	this->edad = _edad;
	dinero = 0.0; 
	ganador = false; 
}

CPersona::~CPersona()
{
}
string CPersona::datos() {
	return "Nombre: " + nombre +
		"\nDireccion: " + direccion +
		"\nTelefono: " + telefono +
		"\nEdad: " + to_string(edad) +
		"\nNumero Comprado: " + numeroComprado + "\n"; cout << endl;
}
string CPersona::getNombre() { return nombre;  }
string CPersona::getDireccion() { return direccion;  }
string CPersona::gettelefono() { return telefono;  }
int CPersona::getEdad() { return edad; }
string CPersona::getNumeroComprado() { return numeroComprado; }
void CPersona::setGanador(bool _ganador) { this->ganador = _ganador;  }
void CPersona::setDinero(float _dinero){ this->dinero= _dinero; }
bool CPersona::getGanador() { return ganador; }
float CPersona::getDinero() { return dinero;  }