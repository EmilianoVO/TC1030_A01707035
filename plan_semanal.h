/*
  Proyecto programación orientada a objetos Clase Plan_Semanal
  Por Emiliano Vásquez Olea - A01707035

  Se crea la clase PLan_Semanal, donde se almacenan las tareas diarias para cada día de la semana, y permite accesar a estos datos
*/
#ifndef PLAN_SEMANAL_H
#define PLAN_SEMANAL_H

#include "tareas_dia.h"
#include "tarea.h"
#include "misc.h"

//Clase para manejar las tareas de cada día de la semana
class Plan_Semanal
{
  private:
    Tareas_Dia plan_diario[7];
    int tareas_completadas;
  public:
    //Funciones para ingresar a la información de las tareas de cada día
    void revisar_tareas_diarias(int num_dia);
    void crear_tarea(int num_dia);
    void crear_ejemplos_tarea();
    void menu_plan();
    Plan_Semanal():
    tareas_completadas(0){}
    ~Plan_Semanal(){cout << "¡Adiós! \n";}
};

void Plan_Semanal::revisar_tareas_diarias(int num_dia) //Se abre la información de las tareas del dia
{
  if(num_dia > 7 || num_dia < 1)
  {
    cout << "Ingresaste un valor inválido \n";
  }
  else
  {
    plan_diario[num_dia-1].menu_tareas_diarias();
  }
}

void Plan_Semanal::crear_tarea(int num_dia)//Acceso rápido al menu para agregar una tarea
{
  if(num_dia > 7 || num_dia < 1)
  {
    cout << "Ingresaste un valor inválido \n";
  }
  else
  {
    plan_diario[num_dia-1].menu_agregar_tarea();
  }
}

void Plan_Semanal::crear_ejemplos_tarea()
{
  //Se agregan tareas de ejemplo a cada día
  Tiempo t(16, 30);
  Tiempo t1(9, 15);
  Tiempo t2(14, 0);
  plan_diario[0].agrega_tarea_grupal("Entrega de información","0", "Equipo 2 Recursos Humanos ", 3);
  plan_diario[0].agrega_tarea_individual("Carta petición", "Escribir la carta para pedir fondos al gobierno", "Carlos", 2);
  plan_diario[1].agrega_evento("Plática", "Plática sobre carros", t);
  plan_diario[2].agrega_tarea_individual("Entrega de portafolios", "0", "Javier", 2);
  plan_diario[2].agrega_tarea_grupal("Generar itinerario", "Itinerario de viaje para jovenes", "Equipo 3 Servicio", 0);
  plan_diario[3].agrega_evento("Servicio social", "Servivio social en Casa San Juan", t1);
  plan_diario[4].agrega_tarea_grupal("Actividad Física", "0", "Equipo 6", 1);
  plan_diario[5].agrega_evento("Junta sociedad de alumnos", "0", t2);
  plan_diario[5].agrega_tarea_individual("Subir archivos", "Cargar documentos de estudio", "Karla", 2);
  plan_diario[6].agrega_tarea_individual("Detalles documento", "Afinar detalles de carta", "Pedro", 1);
}

void Plan_Semanal::menu_plan()//Primer menu que se muestra al usuario, acceso a tareas por dia
{
  cout << "Hola, bienvenido a tu plan semanal de tareas \n";
  int op = 1;
  while(op != 0)
  {
    tareas_completadas = 0;
    for(int i = 0; i < 7; i++)
      tareas_completadas += plan_diario[i].get_n_tareas_completadas();
    
    cout << "En total, se han completado " << tareas_completadas << " tareas \n";
    cout << "1. Lunes: " << plan_diario[0].get_n_tareas() << " por completar \n";
    cout << "2. Martes: " << plan_diario[1].get_n_tareas() << " por completar \n";
    cout << "3. Miércoles: " << plan_diario[2].get_n_tareas() << " por completar \n";
    cout << "4. Jueves: " << plan_diario[3].get_n_tareas() << " por completar \n";
    cout << "5. Viernes: " << plan_diario[4].get_n_tareas() << " por completar \n";
    cout << "6. Sabado: " << plan_diario[5].get_n_tareas() << " por completar \n";
    cout << "7. Domingo: " << plan_diario[5].get_n_tareas() << " por completar \n\n";

    cout << "Ingresa la opción que deseas elegir: \n1. Ver tareas de un día \n2. Agregar tarea a un día \n0. Salir\n";
    cin >> op;
    int n_T;
    switch(op)
    {
      case 1:
        cout << "Ingresa el número del día en que quieres ver las tareas: ";
        cin >> n_T;
        revisar_tareas_diarias(n_T);
        break;
      case 2:
        cout << "Ingresa el número del día en que quieres agregar una tarea: ";
        cin >> n_T;
        crear_tarea(n_T);
        break;
      case 0:
        break;
      default:
        cout << "Ingresaste una opción inválida \n";
    } 
  }
}

#endif