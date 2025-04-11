#include "tdas/list.h"
#include "tdas/extra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char id[20] ;
  char descripcion[256] ;
  char prioridad[10] ;
  int horaRegistro ;
} Ticket;


// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Gestión Hospitalaria");
  puts("========================================");

  puts("1) Registrar paciente");
  puts("2) Asignar prioridad a paciente");
  puts("3) Mostrar lista de espera");
  puts("4) Atender al siguiente paciente");
  puts("5) Mostrar pacientes por prioridad");
  puts("6) Salir");
}

void registrar_ticket(List *tickets) {
  printf("Registrar nuevo ticket\n");
  Ticket *nuevo = (Ticket *)malloc(sizeof(Ticket));
  printf("Ingrese ID del paciente: ");
  scanf("%s", nuevo->id);
  printf("Ingrese descripción del problema: ");
  getchar();
  fgets(nuevo->descripcion, sizeof(nuevo->descripcion), stdin);

  strcpy(nuevo->prioridad, "Bajo");
  nuevo->horaRegistro = time(NULL);
  list_pushBack(tickets, nuevo);
  printf("Ticket registrado con éxito.\n");

  // Aquí implementarías la lógica para registrar un nuevo paciente
}

void asignar_prioridad(List *tickets) {
  char id[20], nuevaPrioridad[10];
  printf("Asignar prioridad a ticket\n");
  scanf("%s", id);

  Ticket *ticketBuscar = list_first(tickets);
  while(ticketBuscar != NULL)
  {
    if (strcmp(ticketBuscar->id, id) == 0) {
      printf("Ingrese nueva prioridad (Bajo/Medio/Alto): ");
      scanf("%s", nuevaPrioridad);
      strcpy(ticketBuscar->prioridad, nuevaPrioridad);
      printf("Prioridad actualizada con éxito.\n");
      return;
    }
    ticketBuscar = list_next(tickets);
  }
  printf("Ticket no encontrado.\n");
}

void mostrar_lista_tickets(List *tickets) {
  
  List *altos = list_create();
  List *medios = list_create();
  List *bajos = list_create();

  Ticket *t = list_first(tickets);
  while (t != NULL) {
    if (strcmp(t->prioridad, "Alto") == 0) {
      list_pushBack(altos, t);
    } else if (strcmp(t->prioridad, "Medio") == 0) {
      list_pushBack(medios, t);
    } else {
      list_pushBack(bajos, t);
    }
    t = list_next(tickets);
  }

  printf("Pacientes con prioridad ALTA:\n");
  t = list_first(altos);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(altos);
  }

  printf("Pacientes con prioridad MEDIA:\n");
  t = list_first(medios);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(medios);
  }

  printf("Pacientes con prioridad BAJA:\n");
  t = list_first(bajos);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(bajos);
  }

  list_clean(altos);
  list_clean(medios);
  list_clean(bajos);
}

int main() {
  char opcion;
  List *tickets = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); // Nota el espacio antes de %c para consumir el
                           // newline anterior

    switch (opcion) {
    case '1':
      registrar_ticket(tickets);
      break;
    case '2':
      asignar_prioridad(tickets);
      // Lógica para asignar prioridad
      break;
    case '3':
      mostrar_lista_tickets(tickets);
      break;
    case '4':
      // Lógica para atender al siguiente paciente
      break;
    case '5':
      // Lógica para mostrar pacientes por prioridad
      break;
    case '6':
      puts("Saliendo del sistema de gestión hospitalaria...");
      break;
    default:
      puts("Opción no válida. Por favor, intente de nuevo.");
    }
    presioneTeclaParaContinuar();

  } while (opcion != '6');

  // Liberar recursos, si es necesario
  list_clean(tickets);

  return 0;
}