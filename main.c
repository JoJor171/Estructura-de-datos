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
  time_t horaRegistro ;
} Ticket;

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("     Sistema de Tickets de Soporte");
  puts("========================================");
  puts("1) Registrar ticket");
  puts("2) Asignar prioridad a ticket");
  puts("3) Mostrar lista de tickets pendientes");
  puts("4) Procesar siguiente ticket");
  puts("5) Buscar ticket por ID");
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

}

void asignar_prioridad(List *tickets) {
  char id[20], nuevaPrioridad[10];
  printf("ID del Ticket a asignar prioridad:\n");
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

  printf("Tickets con prioridad ALTA:\n");
  t = list_first(altos);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(altos);
  }

  printf("Tickets con prioridad MEDIA:\n");
  t = list_first(medios);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(medios);
  }

  printf("Tickets con prioridad BAJA:\n");
  t = list_first(bajos);
  while (t != NULL) {
    printf("ID: %s, Descripción: %s", t->id, t->descripcion);
    t = list_next(bajos);
  }

  list_clean(altos);
  list_clean(medios);
  list_clean(bajos);
}

void procesar_ticket(List *tickets) {
  if (list_first(tickets) == NULL) {
    printf("No hay tickets pendientes.\n");
    return;
  }
  Ticket *mejor = NULL;
  Ticket *actual = list_first(tickets);

  while (actual != NULL) {
    if (mejor == NULL || strcmp(actual->prioridad, mejor->prioridad) == 0 && (actual->horaRegistro < mejor->horaRegistro)) {
      mejor = actual;
    }
    actual = list_next(tickets);
  }
  if (mejor != NULL) {
    printf("Procesando ticket:\n");
    printf("ID: %s\nDescripción: %s\nPrioridad: %s\nHora: %s\n",
    mejor->id, mejor->descripcion, mejor->prioridad,
    ctime(&mejor->horaRegistro));
    
    list_popCurrent(tickets);
    free(mejor);
  } else {
    printf("No se encontró un ticket para atender.\n");
  }
  return;
}

void buscar_ticket(List *tickets) {
  char id[20];
  printf("Buscar ticket por ID\n");
  printf("Ingrese ID del paciente: ");
  scanf("%s", id);

  Ticket *ticketBuscar = list_first(tickets);
  while(ticketBuscar != NULL)
  {
    if (strcmp(ticketBuscar->id, id) == 0) {
      printf("Ticket encontrado:\n");
      printf("ID: %s\nDescripción: %s\nPrioridad: %s\nHora: %s\n",
      ticketBuscar->id, ticketBuscar->descripcion, ticketBuscar->prioridad,
      ctime(&ticketBuscar->horaRegistro));
      return;
    }
    ticketBuscar = list_next(tickets);
  }
  printf("Ticket no encontrado.\n");
} 

int main() {
  char opcion;
  List *tickets = list_create(); // puedes usar una lista para gestionar los pacientes

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); 

    switch (opcion) {
    case '1':
      registrar_ticket(tickets);
      break;
    case '2':
      asignar_prioridad(tickets);
      break;
    case '3':
      mostrar_lista_tickets(tickets);
      break;
    case '4':
      procesar_ticket(tickets);
      break;
    case '5':
      buscar_ticket(tickets);
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