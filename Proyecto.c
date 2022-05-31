// Se incluyen las librerias y constantes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

// Se declaran las funciones
void opc1();
void opc2();
void ManejoDeRegistro();

// Se inicia la funcion principal o main
int main()
{
    int opc, selec = 1;

    while (selec == 1) // Ciclo para ejecutar el programa
    {
        printf("\e[1;1H\e[2J");
        printf("\tCADENAS, ARREGLOS Y REGISTROS\n");
        printf("\n1- Búsqueda de un caracter en una cadena de caracteres");
        printf("\n2- Ordenamiento de un arreglo unidimensional");
        printf("\n3- Manejo de registros");
        printf("\n4- Salir del programa");
        printf("\n\nSeleccione una opcion: ");
        while (scanf("%d", &opc) == 0) // Si no se logra leer un dato tipo entero
        {
            printf("\nNo ha ingresado un numero. Intente de nuevo: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ; // limpia la entrada
        }
        switch (opc) // Se ejecutara la funcion que el usuario decida
        {
        case 1:
            opc1();
            break;
        case 2:
            opc2();
            break;
        case 3:
            ManejoDeRegistro();
            break;
        case 4:
            exit(1);
        default:
            printf("\nEl numero ingresado es incorrecto");
            break;
        }
        do
        {
            printf("\n\nIngrese '1' para escoger otra opcion: ");
            while (scanf("%d", &selec) == 0) // Si no se logra leer un dato tipo entero
            {
                printf("\nNo ha ingresado el numero '1'. Intente de nuevo: ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF)
                    ; // limpia la entrada
            }
        } while (selec != 1);
    }
    return 0;
}

void opc1()
{
    printf("\e[1;1H\e[2J");

    int i;
    char cadena[20];
    char caracter;
    int contador = 0;
    printf("1- Búsqueda de un caracter en una cadena de caracteres\n\n");
    printf("Ingrese una cadena\n");
    scanf("%s", cadena);
    printf("Ingrese el caracter el caracter que desea contar: ");
    scanf(" %c", &caracter);
    contador = 0;
    for (int i = 0; i < 20; i++)
    {
        if (cadena[i] == caracter)
        {
            contador++;
        }
    }
    printf("\nEl caracter '%c' se repite: %d veces\n", caracter, contador);
}

void opc2()
{
    printf("\e[1;1H\e[2J"); // Se limpia la consola

    int arr[6], i, a, j;
    printf("2- Ordenamiento de un arreglo unidimensional\n\n");
    for (i = 0; i < 6; i++)
    { // Se ingresan los numeros al arreglo
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArreglo original: \n");
    for (i = 0; i < 6; i++)
    { // Se imprime el arreglo original
        printf("%d, ", arr[i]);
    }

    for (i = 0; i < 6; ++i)
    { // Se ejecuta algoritmo de ordenacion
        for (j = i + 1; j < 6; ++j)
        {
            if (arr[i] > arr[j])
            {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }

    printf("\n\nArreglo ordenado: \n");
    for (i = 0; i < 6; i++)
    { // Se imprime el arreglo ya ordenado
        printf("%d, ", arr[i]);
    }
}

void ManejoDeRegistro()
{
    struct ESTU // creacion del registro
    {
        char Nombre[MAX];
        char Materia[MAX];
        float Notas[3];
    };
    printf("\e[1;1H\e[2J"); // Se limpia la consola
    float prom;
    struct ESTU estudiante[4];  // declaracion del arreglo registro
    for (int i = 0; i < 4; i++) // Este primer ciclo for es para ingresar los datos como nombre y materia de los estudiantes
    {
        printf("[%d]Nombre del estudiante: ", i + 1);
        scanf("%s", estudiante[i].Nombre);
        printf("[%d]Nombre de la materia: ", i + 1);
        scanf("%s", estudiante[i].Materia);
        for (int j = 0; j < 3; j++) // este es para introducir las notas del estudiante i
        {
            printf("[%d]Nota[%d]: ", i + 1, j + 1);
            scanf("%f", &estudiante[i].Notas[j]);
        }
    }
    for (int i = 0; i < 4; i++) // ciclo para imprimir los datos de lista de estudiante
    {
        prom = 0;
        for (int j = 0; j < 3; j++) // ciclo de suma
        {
            prom += estudiante[i].Notas[j];
        }
        prom = prom / 3; // sacar promedio
        printf("Estudiante: %s, Materia: %s , Promedio: %.2f \n", estudiante[i].Nombre, estudiante[i].Materia, prom);
    }
}