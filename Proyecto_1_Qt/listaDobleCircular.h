#ifndef LISTA_H
#define LISTA_H
#include "iostream"
template <class T>
class ListaDobleCircular
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
               siguiente=pSiguiente;
           }
           void setAnterior(Nodo *pAnterior){
               anterior=pAnterior;
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
               *dato=*pDato;
           }
           ~Nodo(){;}
    };


private:
    Nodo *nodoInicio=0;
    Nodo *nodoFinal=0;
    Nodo *nodoActual=0;
public:
    ListaDobleCircular(T *dato);
    void avanzarEnLista();
    void retrocederEnLista();
    void agregarFinal(T *dato);
    void agregarInicio(T *dato);
    void agregarSiguiente(T *dato);
    void agregarAtras(T* dato);
    T* GetDatoPosicion(int Posicion);
    void SetDatoPosicion(T* dato,int Posicion);

    void irNodoInicio();
    void irNodoFinal();
    bool verSiguiente();
    bool verAnterior();
    T* getDatoNodoActual();
    void eliminarSiguiente();
    void eliminarActual();
    void eliminarAnterior();
    ~ListaDobleCircular();
};
#endif // LISTA_H

template <class T>
ListaDobleCircular<T>::ListaDobleCircular(T *dato)
{
    nodoActual= new Nodo(dato);
    nodoFinal=nodoActual;
    nodoInicio=nodoActual;
}

template <class T>
void ListaDobleCircular<T>::agregarSiguiente( T *dato){
    Nodo *nuevoNodo= new Nodo(dato);
    if (nodoActual==nodoFinal){
        nodoInicio->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(nodoInicio);

        nodoFinal->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(nodoFinal);
        nodoFinal=nuevoNodo;
    }else{
            nodoActual->getSiguiente()->setAnterior(nuevoNodo);
            nuevoNodo->setSiguiente(nodoActual->getSiguiente());
            nodoActual->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(nodoActual);
        }
    }
template <class T>
void ListaDobleCircular<T>::agregarAtras(T *dato){
    Nodo *nuevoNodo= new Nodo(dato);
    if (nodoActual==nodoInicio){
        nodoFinal->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(nodoFinal);

        nodoInicio->setAnterior(nuevoNodo);
        nuevoNodo->setSiguiente(nodoInicio);
        nodoInicio=nuevoNodo;
    }else{
            nodoActual->getAnterior()->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(nodoActual->getAnterior());

            nodoActual->setAnterior(nuevoNodo);
            nuevoNodo->setSiguiente(nodoActual);
        }
    }


template <class T>
void ListaDobleCircular<T>::agregarInicio(T *dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoInicio->setAnterior(nuevoNodo);
    nuevoNodo->setSiguiente(nodoInicio);

    nodoFinal->setSiguiente(nuevoNodo);
    nuevoNodo->setAnterior(nodoFinal);
    nodoInicio=nuevoNodo;
}
template <class T>
void ListaDobleCircular<T>::agregarFinal(T *dato){
    Nodo *nuevoNodo=new Nodo(dato);
    nodoFinal->setSiguiente(nuevoNodo);
    nuevoNodo->setAnterior(nodoFinal);

    nodoInicio->setAnterior(nuevoNodo);
    nuevoNodo->setSiguiente(nodoInicio);
    nodoFinal=nuevoNodo;
}
template <class T>
void ListaDobleCircular<T>::avanzarEnLista(){
    if (!(nodoActual==nodoFinal && nodoActual==nodoInicio))
       nodoActual=nodoActual->getSiguiente();
        return;
}
template <class T>
void ListaDobleCircular<T>::retrocederEnLista(){
    if (!(nodoActual==nodoFinal && nodoActual==nodoInicio))
       nodoActual=nodoActual->getAnterior();
    else
        return;
}
template <class T>
void ListaDobleCircular<T>::irNodoFinal(){
    nodoActual=nodoFinal;
}
template <class T>
void ListaDobleCircular<T>::irNodoInicio(){
    nodoActual=nodoInicio;
}

template <class T>
bool ListaDobleCircular<T>::verSiguiente(){
    if (nodoActual->getSiguiente()==nodoInicio)
        return 0;
    return 1;
}
template <class T>
bool ListaDobleCircular<T>::verAnterior(){
    if (nodoActual->getAnterior()==nodoFinal)
        return 0;
    return 1;
}
template <class T>
T *ListaDobleCircular<T>::getDatoNodoActual(){
    return nodoActual->getDato();
}
template <class T>
T* ListaDobleCircular<T>::GetDatoPosicion(int Posicion){
    Nodo *NodoAux=0;
    T *datoDeRetorno;
    NodoAux=nodoInicio;
    for (int n=0;n<Posicion;n++){
        NodoAux=NodoAux->getSiguiente();
    }
    datoDeRetorno=NodoAux->getDato();
    NodoAux=0;
    delete NodoAux;
    return datoDeRetorno;
}
template <class T>
void ListaDobleCircular<T>::SetDatoPosicion(T* dato,int Posicion){
    Nodo *NodoAux=0;
    NodoAux=nodoInicio;
    for (int n=0;n<Posicion;n++){
        NodoAux=NodoAux->getSiguiente();
    }
    NodoAux->setDato(dato);
    NodoAux=0;
    delete NodoAux;
    return;
}


template <class T>
void ListaDobleCircular<T>::eliminarSiguiente(){
    Nodo *nodoSig=nodoActual->getSiguiente();
    if (nodoSig->getSiguiente()==nodoSig){
        return;
    }
    nodoSig->getSiguiente()->setAnterior(nodoActual);
    nodoActual->setSiguiente(nodoSig->getSiguiente() );
    delete nodoSig;
}
template <class T>
void ListaDobleCircular<T>::eliminarActual(){
    Nodo *nodoAct=nodoActual;
    nodoActual=nodoActual->getSiguiente();
    if (nodoAct->getSiguiente()==nodoAct){
        return;
    }
    nodoAct->getSiguiente()->setAnterior(nodoAct->getAnterior());
    nodoAct->getAnterior()->setSiguiente(nodoAct->getSiguiente());
    delete nodoAct;
}



template <class T>
void ListaDobleCircular<T>::eliminarAnterior(){
    Nodo *nodoAnt=nodoActual->getAnterior();
    if (nodoAnt->getAnterior()==nodoAnt){
        return;
    }
    nodoAnt->getAnterior()->setSiguiente(nodoActual);
    nodoActual->setAnterior(nodoAnt->getAnterior() );
    delete nodoAnt;
}

template <class T>
ListaDobleCircular<T>::~ListaDobleCircular(){;}

