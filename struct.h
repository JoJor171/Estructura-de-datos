#include <time.h>

typedef struct {
    char id[20] ;
    char descripcion[256] ;
    char prioridad[10] ;
    time_t horaRegistro ;
  } Ticket;