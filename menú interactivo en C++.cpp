#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MostrarMenu() {
    printf("\n=========================================\n");
    printf("         MENU DE RESOLUCION DE PROBLEMAS\n");
    printf("=========================================\n");
    printf("1. Promedio de 10 numeros (Bucle while)\n");
    printf("2. Promedio con centinela (-1)\n");
    printf("3. Calificacion en letra (A-F)\n");
    printf("4. Primeras 20 potencias de 4\n");
    printf("5. Mayor y menor de 100 numeros\n");
    printf("6. Conversion de minutos a dias/horas/min\n");
    printf("7. Analisis de numeros pares (20 a 400)\n");
    printf("8. Salir\n");
    printf("Seleccione una opcion (1-8): ");
}

void Problema1() {
    int contador = 0;
    int numero;
    double suma = 0;

    printf("\n--- Problema 1 ---\n");
    printf("Ingrese 10 numeros enteros:\n");

    while (contador < 10) {
        printf("Numero %d: ", contador + 1);
        scanf("%d", &numero);
        suma += numero;
        contador++;
    }

    printf("El promedio es: %.2f\n", suma / 10.0);
}

void Problema2() {
    int numero;
    double suma = 0;
    int contador = 0;

    printf("\n--- Problema 2 ---\n");
    printf("Ingrese numeros enteros positivos (-1 para terminar):\n");

    while (1) {
        scanf("%d", &numero);
        if (numero == -1) {
            break;
        }
        if (numero >= 0) {
            suma += numero;
            contador++;
        }
    }

    if (contador > 0) {
        printf("El promedio de los %d numeros es: %.2f\n", contador, suma / contador);
    } else {
        printf("No se ingresaron numeros validos para promediar.\n");
    }
}

void Problema3() {
    int calificacion;

    printf("\n--- Problema 3 ---\n");
    printf("Ingrese la calificacion (0 - 100): ");
    scanf("%d", &calificacion);

    if (calificacion < 0 || calificacion > 100) {
        printf("Error: Calificacion fuera de rango.\n");
        return;
    }

    printf("Letra correspondiente: ");
    switch (calificacion / 10) {
        case 10:
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        default:
            printf("F\n");
            break;
    }
}

void Problema4() {
    long long potencia = 4;
    
    printf("\n--- Problema 4 ---\n");
    printf("Primeras 20 potencias de 4:\n");

    for (int i = 1; i <= 20; i++) {
        printf("4^%d = %lld\n", i, potencia);
        potencia *= 4;
    }
}

void Problema5() {
    int numero;
    int maximo = -2147483648;
    int minimo = 2147483647;

    printf("\n--- Problema 5 ---\n");
    printf("Ingrese 100 numeros enteros:\n");

    for (int i = 0; i < 100; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);

        if (numero > maximo) {
            maximo = numero;
        }
        if (numero < minimo) {
            minimo = numero;
        }
    }

    printf("\nEl numero mayor ingresado fue: %d\n", maximo);
    printf("El numero menor ingresado fue: %d\n", minimo);
}

void Problema6() {
    int total_minutos;

    printf("\n--- Problema 6 ---\n");
    printf("Ingrese la cantidad de minutos: ");
    scanf("%d", &total_minutos);

    if (total_minutos < 0) {
        printf("Error: No se aceptan minutos negativos.\n");
        return;
    }

    int dias = total_minutos / 1440;
    int minutos_restantes = total_minutos % 1440;
    int horas = minutos_restantes / 60;
    int minutos = minutos_restantes % 60;

    printf("Equivale a: %d dias, %d horas, %d minutos.\n", dias, horas, minutos);
}

void Problema7() {
    long long suma = 0;
    long double producto = 1.0;
    int contador = 0;
    int numeros_pares[200]; 

    printf("\n--- Problema 7 ---\n");
    
    for (int i = 20; i <= 400; i += 2) {
        numeros_pares[contador] = i;
        suma += i;
        producto *= i;
        contador++;
    }

    double promedio = (double)suma / contador;
    int mayores_al_promedio = 0;

    for (int i = 0; i < contador; i++) {
        if (numeros_pares[i] > promedio) {
            mayores_al_promedio++;
        }
    }

    printf("Suma total: %lld\n", suma);
    printf("Producto total: %Le\n", producto);
    printf("Promedio: %.2f\n", promedio);
    printf("Cantidad de numeros mayores al promedio: %d\n", mayores_al_promedio);
}

int main() {
    int opcion;

    do {
        MostrarMenu();
        
        if (scanf("%d", &opcion) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            opcion = 0; 
        }

        if (opcion < 1 || opcion > 8) {
            printf("\n[Error] Opcion invalida. Por favor, ingrese un numero entre 1 y 8.\n");
            continue;
        }

        switch (opcion) {
            case 1: Problema1(); break;
            case 2: Problema2(); break;
            case 3: Problema3(); break;
            case 4: Problema4(); break;
            case 5: Problema5(); break;
            case 6: Problema6(); break;
            case 7: Problema7(); break;
            case 8: printf("\nSaliendo del programa...\n"); break;
        }
    } while (opcion != 8);

    return 0;
}