#include <stdio.h>
#include <math.h>

void operacion(int n1, int n2, char oper, float *resul, int *error);

int main() {
    int n1, n2, error;
    float resultado;
    char opcion;

    do {
        printf("\nMENU\n");
        printf("+ --> Sumar\n");
        printf("- --> Restar\n");
        printf("* --> Multiplicar\n");
        printf("/ --> Dividir\n");
        printf("^ --> Potencia\n");
        printf("s --> Salir\n");
        printf("Elija opción: ");
        scanf(" %c", &opcion);

        if (opcion != 's') {
            printf("Ingrese el primer número: ");
            scanf("%d", &n1);
            printf("Ingrese el segundo número: ");
            scanf("%d", &n2);

            operacion(n1, n2, opcion, &resultado, &error);

            if (error == 1) {
                printf("El resultado es: %.2f\n", resultado);
            } else if (error == -1) {
                printf("Error: operación no válida.\n");
            } else {
                printf("Error: opción desconocida.\n");
            }
        }

    } while (opcion != 's');

    printf("Programa terminado.\n");
    return 0;
}

void operacion(int n1, int n2, char oper, float *resul, int *error) {
    switch (oper) {
        case '+':
            *resul = n1 + n2;
            *error = 1;
            break;
        case '-':
            *resul = n1 - n2;
            *error = 1;
            break;
        case '*':
            *resul = n1 * n2;
            *error = 1;
            break;
        case '/':
            if (n2 != 0) {
                *resul = (float)n1 / n2;
                *error = 1;
            } else {
                *error = -1;
            }
            break;
        case '^':
            *resul = pow(n1, n2);
            *error = 1;
            break;
        default:
            *error = -1;
            break;
    }
}
