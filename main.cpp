#include <QCoreApplication>
#include "listaCircular.h"
#include<bits/stdc++.h>
#include <string.h>
template<typename T>
void tri_rapide (ListaCircular<T> *pLista, int taille, int inicio);

int main(int argc, char *argv[])
{

    char *hola12,hola[]="aaa";
    hola12=hola;
    char *hola144,hola1[]="bbb";
    hola144=hola1;
    char *hola99,hola7[]="ddd";
    hola99=hola7;
    char *hola2,hola3[]="ccc";
    hola2=hola3;

    ListaCircular<char>lista (hola144);
    lista.agregarSiguiente(hola99);
    lista.agregarInicio(hola12);
    lista.agregarFinal(hola2);
    lista.irNodoInicio();
    while(true){

       std::cout <<*(lista.getDatoNodoActual())<<std::endl;

        if (!lista.verSiguiente()){
            break;
        }
        lista.avanzarEnLista();
    }



    tri_rapide<char> (&lista, 4, 0);
    std::cout <<*(lista.GetDatoPosicion(0))<<std::endl;
    std::cout <<*(lista.GetDatoPosicion(1))<<std::endl;
    std::cout <<*(lista.GetDatoPosicion(2))<<std::endl;
    std::cout <<*(lista.GetDatoPosicion(3))<<std::endl;

    while(true){
        lista.eliminarSiguiente();
        if (!lista.verSiguiente()){
            break;
        }
    }

    QCoreApplication a(argc, argv);
    return a.exec();
}


template<typename T>
void tri_rapide (ListaCircular<T>*pLista, int taille, int inicio) {
    int mur,courant;
    T  *pivot,tmp=0;
    if (taille < 2) return;
    pivot = pLista->GetDatoPosicion(taille-1);
    mur  = courant = inicio;
    while (courant<taille) {
        if (*(pLista->GetDatoPosicion(courant)) <= *pivot) {

            if (mur != courant) {
                std::cout <<"Nuevo Intercambio"<<std::endl;
                std::cout <<*(pLista->GetDatoPosicion(mur))<<std::endl;
                std::cout <<*(pLista->GetDatoPosicion(courant))<<std::endl;
                tmp=*(pLista->GetDatoPosicion(courant));
                pLista->SetDatoPosicion(pLista->GetDatoPosicion(mur),courant);
                pLista->SetDatoPosicion(&tmp,mur);
                std::cout <<"Despues de Intercambio"<<std::endl;
                std::cout <<*(pLista->GetDatoPosicion(mur))<<std::endl;
                std::cout <<*(pLista->GetDatoPosicion(courant))<<std::endl;

            }
            mur ++;
        }
        courant ++;

    }

    tri_rapide<T>(pLista, mur - 1,inicio);
    tri_rapide<T>(pLista, taille - mur + 1,inicio +mur-1);


}

