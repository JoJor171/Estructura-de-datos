#include "tdas/list.h"
#include "tdas/extra.h"
#include "struct.h"
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  char opcion;
  List *tickets = list_create(); 

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

  list_clean(tickets);

  return 0;
}