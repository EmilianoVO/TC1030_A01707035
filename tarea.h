/*
  Proyecto programación orientada a objetos Clase Tarea
  Por Emiliano Vásquez Olea - A01707035

  Se crea la clase Tarea, de la cuál heredan las clases Tarea_Individual, Tarea_Grupal y Evento
*/
#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <string>
#include "misc.h"
using namespace std;

//Clase abstracta Tarea que contiene información general de una tarea creada por el usuario
class Tarea
{
  protected:
    string titulo_;
    string desc_;
    int id = rand();
    string tipo;
  
  public:
    //Funciones para extraer o cambiar información del objeto
    string get_titulo(){return titulo_;}
    void set_titulo(string titulo){titulo_ = titulo;}
    string get_desc(){return desc_;}
    void set_desc(string desc){desc_ = desc;}
    int get_id(){return id;}
    string get_tipo(){return tipo;}
    virtual void muestra_info(); //Método  que será sobreescrito por clases hijas
    //Constructores y destructor
    Tarea(string titulo):
    titulo_(titulo),
    desc_("Sin descripción"){cout << "Tarea añadida (sin descripción)" << '\n';}
    Tarea(string titulo, string desc):
    titulo_(titulo),
    desc_(desc){cout << "Tarea añadida (con descripción)" << '\n';}
    ~Tarea(){cout << "Tarea eliminada" << '\n';}
};

void Tarea::muestra_info() //Muestra información del objeto
{
  cout << '\n' << titulo_ << "      ID: " << id << "\n\n";
  cout << "Descripción:" << '\n' << desc_ << "\n\n";
}


//Clase Tarea_Individual que hereda de Tarea
class Tarea_Individual : public Tarea
{
  private:
    string encargado_;
    int prioridad_;
  
  public:
    //Funciones para extraer o cambiar información del objeto
    string get_encargado(){return encargado_;}
    void set_encargado(string encargado){encargado_ = encargado;}
    int get_prioridad(){return prioridad_;}
    void set_prioridad(int prioridad){prioridad_ = prioridad;}
    void muestra_info();
    string msg_prioridad(int prioridad); 
    //Constructores y destructor
    Tarea_Individual(string titulo, string encargado, int prioridad):
    encargado_(encargado),
    prioridad_(prioridad),
    Tarea(titulo){tipo = "Individual";}
    Tarea_Individual(string titulo, string desc, string encargado, int prioridad):
    encargado_(encargado),
    prioridad_(prioridad),
    Tarea(titulo, desc){tipo = "Individual";}
    ~Tarea_Individual(){}
};

//Función para generar el mensaje apropiado para el nivel de prioridad
string Tarea_Individual::msg_prioridad(int prioridad)
{
  string msg;
  switch(prioridad)
  {
    case 0:
      msg = "sin definir";
      break;
    case 1:
      msg = "baja";
      break;
    case 2:
      msg = "media";
      break;
    case 3:
      msg = "alta";
      break;
  }
  return msg;
}

void Tarea_Individual::muestra_info() //Muestra información del objeto
{
  Tarea::muestra_info();
  cout << "Encargado: " << encargado_ << "    Prioridad: " << msg_prioridad(prioridad_) << "\n\n";
  cout << "---------------------------------------------" << '\n';
}

//Clase Tarea_Grupal que hereda de Tarea
class Tarea_Grupal : public Tarea
{
  private:
    string equipo_;
    int prioridad_;
  
  public:
    //Funciones para extraer o cambiar información del objeto
    string get_equipo(){return equipo_;}
    void set_equipo(string equipo){equipo_ = equipo;}
    int get_prioridad(){return prioridad_;}
    void set_prioridad(int prioridad){prioridad_ = prioridad;}
    void muestra_info();
    string msg_prioridad(int prioridad); 
    //Constructores y destructor
    Tarea_Grupal(string titulo, string equipo, int prioridad):
    equipo_(equipo),
    prioridad_(prioridad),
    Tarea(titulo){tipo = "Grupal";}
    Tarea_Grupal(string titulo, string desc, string equipo, int prioridad):
    equipo_(equipo),
    prioridad_(prioridad),
    Tarea(titulo, desc){tipo = "Grupal";}
    ~Tarea_Grupal(){}
};

//Función para generar el mensaje apropiado para el nivel de prioridad
string Tarea_Grupal::msg_prioridad(int prioridad)
{
  string msg;
  switch(prioridad)
  {
    case 0:
      msg = "sin definir";
      break;
    case 1:
      msg = "baja";
      break;
    case 2:
      msg = "media";
      break;
    case 3:
      msg = "alta";
      break;
  }
  return msg;
}

void Tarea_Grupal::muestra_info() //Muestra información del objeto
{
  Tarea::muestra_info();
  cout << "Equipo encargado: " << equipo_ << "    Prioridad: " << msg_prioridad(prioridad_) << "\n\n";
  cout << "---------------------------------------------" << '\n';
}

//Clase Evento que hereda de Tarea
class Evento : public Tarea
{
  private:
    Tiempo hora_evento_;
  
  public:
    //Funciones para extraer o cambiar información del objeto
    Tiempo get_hora_evento(){return hora_evento_;}
    void set_hora_evento(Tiempo hora_evento){hora_evento_ = hora_evento;}
    void muestra_info();
    //Constructores y destructor
    Evento(string titulo, Tiempo hora_evento):
    hora_evento_(hora_evento),
    Tarea(titulo){tipo = "Evento";}
    Evento(string titulo, string desc, Tiempo hora_evento):
    hora_evento_(hora_evento),
    Tarea(titulo, desc){tipo = "Evento";}
    ~Evento(){}
};

void Evento::muestra_info() //Muestra información del objeto
{
  Tarea::muestra_info();
  cout << "Hora del evento: " << hora_evento_.hora << ":" << hora_evento_.minuto << "\n\n";
  cout << "---------------------------------------------" << '\n';
}

#endif