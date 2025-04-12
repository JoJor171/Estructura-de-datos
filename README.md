
# Sistema de Gestión de Tickets de Soporte Técnico

## Descripción

Este sistema permite a los usuarios registrar y gestionar tickets de soporte técnico. A través de una interfaz de consola, los usuarios pueden registrar nuevos tickets, asignar prioridades, visualizar tickets pendientes organizados por nivel de urgencia, procesar tickets según su prioridad y buscar tickets por ID. El objetivo es facilitar la atención oportuna de los requerimientos según su nivel de importancia.

## Cómo compilar y ejecutar

Este sistema ha sido desarrollado en lenguaje C y puede ser ejecutado utilizando **Visual Studio Code** junto a extensiones y herramientas para C/C++. A continuación se detallan los pasos necesarios para compilarlo y ejecutarlo.

### Requisitos previos:

- [Visual Studio Code](https://code.visualstudio.com/)
- Extensión **C/C++** (Microsoft)
- Compilador de C (recomendado: **gcc** con [MinGW](https://www.mingw-w64.org/) o usando [WSL](https://learn.microsoft.com/en-us/windows/wsl/))

### Pasos para compilar y ejecutar:

1. **Clona el repositorio o descomprime el proyecto**
   ```bash
   git clone https://github.com/OptativoPUCV/lab-1-uso-de-tdas-JoJor171.git
   ```

2. **Abre el proyecto en Visual Studio Code**
   - `Archivo > Abrir carpeta...` y selecciona la carpeta del proyecto.

3. **Compila el programa**
   - Abre la terminal integrada (`Terminal > Nueva terminal`)
   - Ejecuta:
     ```bash
     gcc main.c tdas/list.c tdas/extra.c -o gestor_tickets
     ```

4. **Ejecuta la aplicación**
   ```bash
   ./gestor_tickets
   ```

## Funcionalidades

- Registrar tickets con ID, descripción y prioridad por defecto ("Bajo").
- Asignar prioridad a tickets existentes ("Bajo", "Medio", "Alto").
- Visualizar lista de tickets pendientes, ordenados por prioridad.
- Procesar el siguiente ticket según prioridad y orden de llegada.
- Buscar tickets por ID.

## Ejemplo de uso

**Registrar un Ticket**
```
Opción seleccionada: 1
Ingrese ID del paciente: T001
Ingrese descripción del problema: No hay internet en oficina 23
```

**Asignar Prioridad**
```
Opción seleccionada: 2
ID del Ticket: T001
Nueva prioridad: Alto
```

**Mostrar Lista de Tickets**
```
Opción seleccionada: 3
Pacientes con prioridad ALTA:
ID: T001, Descripción: No hay internet en oficina 23
...
```

**Procesar Siguiente Ticket**
```
Opción seleccionada: 4
Procesando ticket:
ID: T001
Descripción: No hay internet en oficina 23
Prioridad: Alto
Hora: Fri Apr 11 10:53:01 2025
```

**Buscar Ticket**
```
Opción seleccionada: 5
Ingrese ID del paciente: T001
Ticket encontrado:
ID: T001
Descripción: No hay internet en oficina 23
Prioridad: Alto
Hora: Fri Apr 11 10:53:01 2025
```
