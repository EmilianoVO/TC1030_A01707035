/*
  Proyecto programación orientada a objetos: main
  Por Emiliano Vásquez Olea - A01707035

  Programa main.cpp donde se generan objetos de prueba y se despliega su información
*/
#include <iostream>
#include <string>
#include "tarea.h"
#include "misc.h"


int main() {
  srand((unsigned) time(0)); //Generamos semilla para los numeros aleatorios de los id

  //Creamos objetos de prueba de las diferentes clases hijas
  Tiempo t(16, 30);

  Tarea_Individual pruebaTI("Carta petición", "Escribir la carta para pedir fondos al gobierno", "Carlos", 2);
  Tarea_Grupal pruebaTG("Entrega de información", "Equipo 2 Recursos Humanos ", 3);
  Evento pruebaE("Plática", "Plática sobre carros", t);

  //Mostramos la información
  pruebaTI.muestra_info();
  pruebaTG.muestra_info();
  pruebaE.muestra_info();

  //Editamos los objetos
  pruebaTG.set_desc("Entregar los registros enviados desde el edificio central");
  pruebaTI.set_titulo("Carta fondos");
  t.hora = 17;
  pruebaE.set_hora_evento(t);

  //Volvemos a desplegar la información
  cout << "Objetos editados: " <<"\n\n";
  pruebaTI.muestra_info();
  pruebaTG.muestra_info();
  pruebaE.muestra_info();
}