/*
  Proyecto programación orientada a objetos Estructura Tiempo
  Por Emiliano Vásquez Olea - A01707035

  En este archivo se encuentran funciones o estructuras generales que serán utilizadas por las clases
*/
#ifndef MISC_H
#define MISC_H

#include <cstdlib>
#include <ctime>

using namespace std;

//Definimos estructura tiempo que será utilizada por las clases de tipo evento
struct Tiempo
{
  int hora;
  int minuto;
  Tiempo(int h, int m): 
  hora(h),
  minuto(m){};

  //Función para revisar si la fecha que guarda la estructura es válida o no
  bool revisar_fecha()
  {
    return (hora >= 0 && hora <= 24 && minuto >= 0 && minuto <= 59) ? true : false;
  }
};

#endif