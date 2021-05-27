/*
  Proyecto programación orientada a objetos main.cpp
  Por Emiliano Vásquez Olea - A01707035

  Código main de prueba en el cuál se crean diferentes objetos y se llaman funciones para utilizar las clases definidas
*/
#include <iostream>
#include <string>
#include "tareas_dia.h"
#include "tarea.h"
#include "misc.h"

int main() {
  srand((unsigned) time(0)); //Se genera semilla para números aleatorios
  
  Tareas_Dia prueba_tareas;
  Tiempo t(16, 30);

  //Agregamos tareas de ejemplo con elmétodo de la clase Tareas_Dia
  prueba_tareas.agrega_tarea_grupal("Entrega de información","0", "Equipo 2 Recursos Humanos ", 3);
  prueba_tareas.agrega_tarea_individual("Carta petición", "Escribir la carta para pedir fondos al gobierno", "Carlos", 2);
  prueba_tareas.agrega_evento("Plática", "Plática sobre carros", t);

  prueba_tareas.menu_tareas_diarias();
}