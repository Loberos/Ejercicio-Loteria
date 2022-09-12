#pragma once

#include <functional>
#include <iostream>
using namespace std;
typedef unsigned int uint;


template <typename T, T NADA = 0>
class Lista {
    struct Nodo;
    typedef function<int(T, T)> Comp;
    Nodo* ini; 
    uint elementoLista; 
    Comp comparar;
public:
    Lista() : ini(nullptr), elementoLista(0), comparar([](T a, T b) {return a - b; }) {}
    Lista(Comp comparar) : ini(nullptr), elementoLista(0), comparar(comparar) {}
    ~Lista();

    uint longitud();
    bool esVacia();
    void agregaInicial(T elemento);
    void agregaPos(T elemento, uint pos);
    void agregaFinal(T elemento);
    void modificarInicial(T elemento);
    void modificarPos(T elemento, uint pos);
    void modificarFinal(T elemento);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal(); 
    T buscar(T elemento);
};

template <typename T, T NADA>
struct Lista<T, NADA>::Nodo {
    T elemento;
    Nodo* sig; 
    Nodo(T elemento = NADA, Nodo* sig = nullptr) : elemento(elemento), sig(sig) {}
};

template <typename T, T NADA>
Lista<T, NADA>::~Lista() {
    Nodo* aux = ini;
    while (aux != nullptr) {
        aux = ini;
        ini = ini->sig;
        delete aux;
    }
}

template <typename T, T NADA>
uint Lista<T, NADA>::longitud() {
    return elementoLista;
}

template <typename T, T NADA>
bool Lista<T, NADA>::esVacia() {
    return elementoLista == 0;
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaInicial(T elemento) {
    Nodo* nuevo = new Nodo(elemento, ini);
    if (nuevo != nullptr) {
        ini = nuevo;
        elementoLista++;
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPos(T elemento, uint pos) {
    if (pos > elementoLista) return;
    if (pos == 0) {
        agregaInicial(elemento);
    }
    else {
        Nodo* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->sig;
        }
        Nodo* nuevo = new Nodo(elemento, aux->sig);
        if (nuevo != nullptr) {
            aux->sig = nuevo;
            elementoLista++;
        }
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaFinal(T elemento) {
    agregarPos(elemento, elementoLista); 
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarInicial(T elemento) {
    if (elementoLista > 0) {
        ini->elemento = elemento;
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarPos(T elemento, uint pos) {
    if (pos >= 0 && pos < elementoLista) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        aux->elemento = elemento;
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarFinal(T elemento) {
    modificar(elemento, elementoLista - 1);
}

template <typename T, T NADA>
void Lista<T, NADA>::eliminaInicial() {
    if (elementoLista > 0) {
        Nodo* aux = ini;
        ini = ini->sig;
        delete aux;
        elementoLista--;
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::eliminaPos(uint pos) {
    if (pos < lon) {
        if (pos==0) {
            eliminaInicial(); 
        }
        else {
            Nodo* aux1=ini; 
            Nodo* aux2; 
            for (int i = 1; i < pos - 1; i++) {
                aux1 = aux1->sig;
            }
            aux2 = aux1->sig; 
            aux1->sig = aux2->sig; 
            delete aux2; 
        }
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::eliminaFinal() {
    eliminaPos(lon - 1); 
}

template <typename T, T NADA>
T Lista<T, NADA>::obtenerInicial() {
    return obtenerPos(0);
}

template <typename T, T NADA>
T Lista<T, NADA>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < elementoLista) {
        Nodo* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sig;
        }
        return aux->elemento;
    }
    else {
        return NADA;
    }
}

template <typename T, T NADA>
T Lista<T, NADA>::obtenerFinal() {
    return obtenerPos(elementoLista - 1);
}

template <typename T, T NADA>
T Lista<T, NADA>::buscar(T elemento) {
    Nodo* aux = ini;
    while (aux != nullptr) {
        if (comparar(aux->elemento, elemento) == 0) {
            return aux->elemento;
        }
        aux = aux->sig;
    }
    return NADA;
}
