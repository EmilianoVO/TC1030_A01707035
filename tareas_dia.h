/*
  Proyecto programación orientada a objetos Clase Tareas_Dia
  Por Emiliano Vásquez Olea - A01707035

  Se crea la clase Tareas_Dia, en la cuál se guardan por composición diferentes objetos de tipo tarea, alocados en el heap.
*/
#ifndef TAREAS_DIA_H
#define TAREAS_DIA_H

#include <vector>
#include "tarea.h"
#include "misc.h"

//Clase que permite manejar una lista de tareas y mostrar su contenido
class Tareas_Dia
{
  private:
    vector <Tarea*> lista_tareas;  //Vector que contiene las diferentes tareas, utilizando polimorfismo sobre la clase abstracta Tarea
    int n_tareas;
    int n_tareas_completadas;
  
  public:
    int get_n_tareas(){return n_tareas;}
    int get_n_tareas_completadas(){return n_tareas_completadas;}
    void muestra_tareas();
    void ver_datos_tarea(int num_tarea);
    void edita_tarea(int num_tarea);
    void elimina_tarea(int num_tarea);
    void agrega_tarea_individual(string titulo, string desc, string encargado, int prioridad);
    void agrega_tarea_grupal(string titulo, string desc, string equipo, int prioridad);
    void agrega_evento(string titulo, string desc, Tiempo hora_evento);
    void menu_agregar_tarea();
    void menu_tareas_diarias();
    //Constructor y destructor
    Tareas_Dia():
    n_tareas(0),
    n_tareas_completadas(0){}
    ~Tareas_Dia()
    {
      for(vector<Tarea*>::iterator i = lista_tareas.begin(); i != lista_tareas.end(); i++)
      {
        delete(*i);
      }
      lista_tareas.clear();
    }
};

void Tareas_Dia::muestra_tareas()// Muestra una lista resumida de las tareas creadas
{
  if(lista_tareas.empty())
  {
    cout << "No se tienen tareas registradas";
  }
  else
  {
    //Se itera a lo largo del vector de tareas y muestra el titulo y id
    int cTemp = 1;
    for(vector<Tarea*>::iterator i = lista_tareas.begin(); i != lista_tareas.end(); i++)
    {
      cout << cTemp++ << " " << (*i)->get_titulo() << "    ID: " << (*i)->get_id() << '\n';
    }
  }
  cout << "\n\n";
}

void Tareas_Dia::ver_datos_tarea(int num_tarea) //Muestra la información de una tarea a partir de su posición en la lista
{
  num_tarea--; //Utilizamos el índice anterior debido a que se inicia en el 0
  if(num_tarea < 0 || num_tarea > lista_tareas.size())//Revisar si el índice es válido
  {
    cout << "Ingresaste un número de tarea inválido \n\n";
  }
  else
  {
    lista_tareas[num_tarea]->muestra_info(); //Se llama la función sobreescrita muestra_info
  }
}


void Tareas_Dia::edita_tarea(int num_tarea) //Despliega el menu que hace preguntas para editar la Tarea
{
  if(num_tarea < 0 || num_tarea > lista_tareas.size())//Revisar si el índice es válido
  {
    cout << "Ingresaste un número de tarea inválido \n\n";
  }
  else
  {
    num_tarea--; //Utilizamos el índice anterior debido a que se inicia en el 0
    //Primero se preguntoa sobre los atributos generales de la clase Tarea
    string n_titulo, n_desc;
    int n_prioridad;
    cout << "Ingresa el nuevo titulo, ingresa \"0\" para mantener el actual (" << lista_tareas[num_tarea]->get_titulo() << "): \n";
    cin >> n_titulo;
    if(n_titulo != "0") 
      lista_tareas[num_tarea]->set_titulo("Hola");
    
    cout << "Ingresa la nueva descripción, ingresa \"0\" para mantener la actual (" << lista_tareas[num_tarea]->get_desc() << "): \n";
    cin >> n_desc;
    if(n_desc!= "0") 
      lista_tareas[num_tarea]->set_desc(n_desc);
    
    //Cambios de atributos de clases Tarea_Individual y Tarea_Grupal
    if(lista_tareas[num_tarea]->get_tipo() == "Grupal" || lista_tareas[num_tarea]->get_tipo() == "Individual")
    {
      string n_enc;
      if(lista_tareas[num_tarea]->get_tipo() == "Grupal")
      {
        Tarea_Grupal* pTemp = static_cast<Tarea_Grupal*>(lista_tareas[num_tarea]); //Usamos cast para obtener un puntador del tipo de la clase derivada
        cout << "Ingresa el nuevo equipo encargado de la tarea, ingresa \"0\" para mantener el actual (" << pTemp->get_equipo() << "): \n";
        cin >> n_enc;
        if(n_enc != "0") 
          pTemp->set_equipo(n_enc);
        
        cout << "Ingresa la nueva prioridad, ingresa -1 para mantener la actual (" << pTemp->get_prioridad() << "): \n";
        cout << "0. Sin definir \n1. Baja \n2. Media \n3. Alta \n";
        cin >> n_prioridad;
        if(n_prioridad != -1) 
        {
          if(n_prioridad < 0 || n_prioridad > 3)
          {
            cout << "Ingresaste un nivel de prioridad inválido \n";
          }
          else
          {
            pTemp->set_prioridad(n_prioridad);
          }
        }
        
      }
      else
      {
        Tarea_Individual* pTemp = static_cast<Tarea_Individual*>(lista_tareas[num_tarea]); //Usamos cast para obtener un puntador del tipo de la clase derivada
        cout << "Ingresa el nuevo encargado de la tarea, ingresa \"0\" para mantener el actual (" << pTemp->get_encargado() << "): \n";
        cin >> n_enc;
        if(n_enc != "0") 
          pTemp->set_encargado(n_enc);
        
        cout << "Ingresa la nueva prioridad, ingresa -1 para mantener la actual (" << pTemp->get_prioridad() << "): \n";
        cout << "0. Sin definir \n1. Baja \n2. Media \n3. Alta \n";
        cin >> n_prioridad;
        if(n_prioridad != -1) 
        {
          if(n_prioridad < 0 || n_prioridad > 3)
          {
            cout << "Ingresaste un nivel de prioridad inválido \n";
          }
          else
          {
            pTemp->set_prioridad(n_prioridad);
          }
        } 
      }
    }

    else //Para clases evento se cambia la hora
    {
      Evento* pTemp = static_cast<Evento*>(lista_tareas[num_tarea]); //Usamos cast para obtener un puntador del tipo de la clase derivada
      int n_m, n_h;
      cout << "Ingresa la hora del evento (de 0 a 24), ingresa -1 para mantener la actual (" << (pTemp->get_hora_evento()).hora << "): \n";
        cin >> n_h;
      if(n_h == -1)
        n_h = (pTemp->get_hora_evento()).hora;

      cout << "Ingresa el nuevo minuto (de 0 a 59), ingresa -1 para mantener la actual (" << (pTemp->get_hora_evento()).minuto << "): \n";
        cin >> n_m;

      if(n_m == -1)
        n_m = (pTemp->get_hora_evento()).minuto;

      Tiempo n_t(n_h, n_m);
      if(n_t.revisar_fecha())
      {
        pTemp->set_hora_evento(n_t);
      }
      else
      {
        cout << "Ingresaste una hora inválida \n";
      }
    }
  }
}

void Tareas_Dia::elimina_tarea(int num_tarea)//Libera memoria del apuntador y elimina el valor dado del vector
{
  if(num_tarea < 0 || num_tarea > lista_tareas.size())//Revisar si el índice es válido
  {
    cout << "Ingresaste un número de tarea inválido \n\n";
  }
  delete(*(lista_tareas.begin()+num_tarea-1));
  lista_tareas.erase(lista_tareas.begin()+num_tarea-1);
  n_tareas--; //Agrega 1 al contador de tareas
}

void Tareas_Dia::agrega_tarea_individual(string titulo, string desc, string encargado, int prioridad)//Agrega una tarea de tipo Tarea_Individual
{
  if(desc != "0") //Revisa que se haya ingresado una descripción y agrega la tarea al vector
  {
    lista_tareas.push_back(new Tarea_Individual(titulo, desc, encargado, prioridad));
  }
  else
  {
    lista_tareas.push_back(new Tarea_Individual(titulo, encargado, prioridad));
  }
  n_tareas++; //Agrega 1 al contador de tareas
}

void Tareas_Dia::agrega_tarea_grupal(string titulo, string desc, string equipo, int prioridad)//Agrega una tarea de tipo Tarea_Grupal
{
  if(desc != "0") //Revisa que se haya ingresado una descripción y agrega la tarea al vector
  {
    lista_tareas.push_back(new Tarea_Grupal(titulo, desc, equipo, prioridad));
  }
  else
  {
    lista_tareas.push_back(new Tarea_Grupal(titulo, equipo, prioridad));
  }
  n_tareas++; //Agrega 1 al contador de tareas
}

void Tareas_Dia::agrega_evento(string titulo, string desc, Tiempo hora_evento)//Agrega una tarea de tipo Evento
{
  if(desc != "0") //Revisa que se haya ingresado una descripción y agrega la tarea al vector
  {
    lista_tareas.push_back(new Evento(titulo, desc, hora_evento));
  }
  else
  {
    lista_tareas.push_back(new Evento(titulo, hora_evento));
  }
  n_tareas++; //Agrega 1 al contador de tareas
}

void Tareas_Dia::menu_agregar_tarea()// Despliega una serie de preguntas al usuario para que ingrese los datos para crear una nueva tarea
{
  string n_titulo, n_desc;
  //Variables para las preguntas hechas en el menu
  bool l = false;
  int selec;
  while(!l) //Primero se pide el tipo de tarea a crear
  {
    cout << "Ingresa el tipo de tarea que deseas agregar: \n1. Tarea individual \n2. Tarea grupal \n3. Evento \n";
    cin >> selec;
    if(selec > 0 && selec < 4) //Se revisa que se ingrese una opción válida
    {
      l = true;
    }
    else
    {
      cout << "Ingresaste una opción inválida \n";
    }
  }

  cout << "Ingresa el titulo para la tarea: \n";
  cin >> n_titulo; 

  cout << "Ingresa la descripción de la tarea, ingresa \"0\" si aún no la defines: \n";
  cin >> n_desc;

  if(selec == 1 || selec == 2)//Si la tarea será de tipo individual o grupal
  {
    string n_enc;
    int n_prioridad;
    l = false;
    cout << "Ingresa la persona/equipo encargado: \n";
    cin >> n_enc; 

    while(!l)
    {
      cout << "El nivel de prioridad de la tarea: \n0. Sin definir \n1. Baja \n2. Media \n3. Alta \n";
      cin >> n_prioridad;
      if(n_prioridad >= 0 && n_prioridad < 4) //Se revisa que se ingrese una opción válida
      {
        l = true;
      }
      else
      {
        cout << "Ingresaste una opción inválida \n";
      }
    }

    if(selec == 1)
    {
      agrega_tarea_individual(n_titulo, n_desc, n_enc, n_prioridad);
    }
    else
    {
      agrega_tarea_grupal(n_titulo, n_desc, n_enc, n_prioridad);
    }
  }
  else //Si la tarea es de clase evento
  {
    l = false;

    while(!l)
    {
      int n_m, n_h;
      cout << "Ingresa la hora del evento (de 0 a 24): \n";
        cin >> n_h;

      cout << "Ingresa el minuto del evento (de 0 a 59): \n";
        cin >> n_m;

      Tiempo n_t(n_h, n_m);
      if(n_t.revisar_fecha()) //Se revisa que se ingrese una opción válida
      {
        l = true;
        agrega_evento(n_titulo, n_desc, n_t);
      }
      else
      {
        cout << "La hora (o minuto) ingesado es inválido \n";
      }
    }
  }
}

void Tareas_Dia::menu_tareas_diarias() //Se despliegan las opciones apra manejar las tareas del día
{
  int selec = 1;
  while(selec != 0)
  {
    cout << "Tareas del día: \n\n";
    muestra_tareas();

    cout << "Elige lo que deseas hacer: (ingresa el número de la opción): \n";
    if(lista_tareas.empty()) //Se muestran menos opciones si la lista está vacía
    {
      cout << "1. Agregar tarea \n0. Salir";
      cin >> selec;
      switch(selec)
      {
        case 1:
          menu_agregar_tarea();
          break;
        case 0:
          break;
        default:
          cout << "Ingresaste una opción inválida \n";
      }
    }
    else
    {
      int t;
      cout << "1. Agregar tarea \n2. Editar una tarea \n3. Marcar tarea como completada \n4. Eliminar una tarea \n5. Ver los datos de una tarea \n0. Salir \n";
      cin >> selec;
      switch(selec)
      {
        case 1:
          menu_agregar_tarea();
          break;
        case 2:
          cout << "Ingresa el número de la tarea que deseas editar (no el ID): ";
          cin >> t;
          edita_tarea(t);
          break;
        case 3:
          cout << "Ingresa el número de la tarea que deseas marcar como completada (no el ID): ";
          cin >> t;
          elimina_tarea(t);
          n_tareas_completadas++; //Se incrementa el contador de tareas completadas
          break;
        case 4:
          cout << "Ingresa el número de la tarea que deseas eliminar (no el ID): ";
          cin >> t;
          elimina_tarea(t);
          break;
        case 5:
          cout << "Ingresa el número de la tarea de la cuál deseas ver los datos (no el ID): ";
          cin >> t;
          ver_datos_tarea(t);
          break;
        case 0:
          break;
        default:
          cout << "Ingresaste una opción inválida \n";
      }
    }
  }
}

#endif