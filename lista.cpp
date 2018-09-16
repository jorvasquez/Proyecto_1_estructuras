/*
#include "lista.h"

Lista::Lista(int dato)
{
    nodoActual= new Nodo(dato);
    nodoFinal=nodoActual;
    nodoInicio=nodoActual;
}
void Lista::agregarSiguiente( int dato){
    Nodo *nuevoNodo= new Nodo(dato);
    if (nodoActual->getSiguiente()==0){
        nodoActual->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(nodoActual);
        nodoFinal=nuevoNodo;
    }else{
            nodoActual->getSiguiente()->setAnterior(nuevoNodo);
            nuevoNodo->setSiguiente(nodoActual->getSiguiente());
            nodoActual->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(nodoActual);
        }
    }
void Lista::agregarAtras(int dato){
    Nodo *nuevoNodo= new Nodo(dato);
    if (nodoActual->getAnterior()==0){
        nodoActual->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(nodoActual);
        nodoInicio=nuevoNodo;
    }else{

            nodoActual->getAnterior()->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(nodoActual->getAnterior());

            nodoActual->setAnterior(nuevoNodo);
            nuevoNodo->setSiguiente(nodoActual);
        }
    }
void Lista::agregarInicio(int dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoInicio->setAnterior(nuevoNodo);
    nuevoNodo->setSiguiente(nodoInicio);
    nodoInicio=nuevoNodo;
}
void Lista::agregarFinal(int dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoFinal->setSiguiente(nuevoNodo);
    nuevoNodo->setAnterior(nodoFinal);
    nodoFinal=nuevoNodo;
}
void Lista::avanzarEnLista(){
    if (nodoActual->getSiguiente()!=0)
       nodoActual=nodoActual->getSiguiente();
    else
        return;
}

void Lista::retrocederEnLista(){
    if (nodoActual->getAnterior()!=0)
       nodoActual=nodoActual->getAnterior();
    else
        return;
}
void Lista::irNodoFinal(){
    nodoActual=nodoFinal;
}
void Lista::irNodoInicio(){
    nodoActual=nodoInicio;
}
int Lista::verSiguiente(){
    if (nodoActual->getSiguiente()==0)
        return 0;
    return 1;
}
int Lista::verAnterior(){
    if (nodoActual->getAnterior()==0)
        return 0;
    return 1;
}
int Lista::getDatoNodoActual(){
    return nodoActual->getDato();
}

void Lista::eliminarSiguiente(){
    Nodo *nodoSig=nodoActual->getSiguiente();
    if (nodoSig==0){
        return;
    }
    if (nodoSig->getSiguiente()!=0){// 0 es un puntero a NULL
        nodoSig->getSiguiente()->setAnterior(nodoActual);
        nodoActual->setSiguiente(nodoSig->getSiguiente() );
    }else{
        nodoActual->setSiguiente(0);
    }
    delete nodoSig;
}
void Lista::eliminarAnterior(){
    Nodo *nodoAnt=nodoActual->getAnterior();
    if (nodoAnt==0){
        return;
    }
    if (nodoAnt->getAnterior()!=0){// 0 es un puntero a NULL
        nodoAnt->getAnterior()->setSiguiente(nodoActual);
        nodoActual->setAnterior(nodoAnt->getAnterior() );
    }else{
        nodoActual->setAnterior(0);
    }
    delete nodoAnt;
}


Lista::~Lista(){;}
*/
