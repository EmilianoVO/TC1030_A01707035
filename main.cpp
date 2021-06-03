/*
  Proyecto programación orientada a objetos main.cpp
  Por Emiliano Vásquez Olea - A01707035

  Código main de prueba en el cuál se crean diferentes objetos y se llaman funciones para utilizar las clases definidas
*/
#include <iostream>
#include <string>
#include "plan_semanal.h"
#include "tareas_dia.h"
#include "tarea.h"
#include "misc.h"

int main() {
  srand((unsigned) time(0)); //Se genera semilla para números aleatorios
  
  Plan_Semanal plan_ej;
  plan_ej.crear_ejemplos_tarea(); //Se generan ejemplos en la clase

  plan_ej.menu_plan();
}