#ifndef LISTA_H
#define LISTA_H
#include "iostream"
template <class T>
class ListaDoble
{
    class Nodo
    {  private:
        T *dato;
        Nodo* anterior=0;
        Nodo* siguiente=0;
       public:
           Nodo(T *pDato){
               dato=pDato;
               siguiente=0;
               anterior=0;
           }
           void asignarNodo(Nodo *pSiguiente,Nodo *pAnterior){
               siguiente=pSiguiente;
               anterior=pAnterior;
           }

           void setSiguiente(Nodo *pSiguiente){
               anterior=pSiguiente;
           }
           void setAnterior(Nodo *pAnterior){
               siguiente=pAnterior;
           }
           Nodo* getAnterior(){
               return anterior;
           }
           Nodo* getSiguiente(){
               return siguiente;
           }
           T* getDato(){
               return dato;
           }
           void setDato(T *pDato){
               dato=pDato;
           }
           ~Nodo(){;}
    };


private:
    Nodo *nodoInicio=0;
    Nodo *nodoFinal=0;
    Nodo *nodoActual=0;
public:
    ListaDoble(T *dato);
    void avanzarEnLista();
    void retrocederEnLista();
    void agregarFinal(T *dato);
    void agregarInicio(T *dato);
    void agregarSiguiente(T *dato);
    void agregarAtras(T *dato);
    void irNodoInicio();
    void irNodoFinal();
    bool verSiguiente();
    bool verAnterior();
    T* getDatoNodoActual();
    void eliminarSiguiente();
    void eliminarAnterior();
    ~ListaDoble();
};
#endif // LISTA_H

template <class T>
ListaDoble<T>::ListaDoble(T *dato)
{
    nodoActual= new Nodo(dato);
    nodoFinal=nodoActual;
    nodoInicio=nodoActual;
}

template <class T>
void ListaDoble<T>::agregarSiguiente( T *dato){
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
template <class T>
void ListaDoble<T>::agregarAtras(T *dato){
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
template <class T>
void ListaDoble<T>::agregarInicio(T *dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoInicio->setAnterior(nuevoNodo);
    nuevoNodo->setSiguiente(nodoInicio);
    nodoInicio=nuevoNodo;
}
template <class T>
void ListaDoble<T>::agregarFinal(T *dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoFinal->setSiguiente(nuevoNodo);
    nuevoNodo->setAnterior(nodoFinal);
    nodoFinal=nuevoNodo;
}
template <class T>
void ListaDoble<T>::avanzarEnLista(){
    if (nodoActual->getSiguiente()!=0)
       nodoActual=nodoActual->getSiguiente();
    else
        return;
}
template <class T>
void ListaDoble<T>::retrocederEnLista(){
    if (nodoActual->getAnterior()!=0)
       nodoActual=nodoActual->getAnterior();
    else
        return;
}
template <class T>
void ListaDoble<T>::irNodoFinal(){
    nodoActual=nodoFinal;
}
template <class T>
void ListaDoble<T>::irNodoInicio(){
    nodoActual=nodoInicio;
}
template <class T>
bool ListaDoble<T>::verSiguiente(){
    if (nodoActual->getSiguiente()==0)
        return 0;
    return 1;
}
template <class T>
bool ListaDoble<T>::verAnterior(){
    if (nodoActual->getAnterior()==0)
        return 0;
    return 1;
}
template <class T>
T* ListaDoble<T>::getDatoNodoActual(){
    return nodoActual->getDato();
}
template <class T>
void ListaDoble<T>::eliminarSiguiente(){
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
template <class T>
void ListaDoble<T>::eliminarAnterior(){
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
template <class T>
ListaDoble<T>::~ListaDoble(){;}

