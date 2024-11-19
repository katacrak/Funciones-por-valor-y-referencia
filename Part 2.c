#include <stdio.h>
#include <math.h>

int menu();
void operacion(int n1, int n2, char oper, float *resul, int *error);

int main() {
    int n1, n2, error, opcion;
    float resultado;

    do {
        opcion = menu();

        if (opcion != 6) {
            printf("Ingrese el primer número: ");
            scanf("%d", &n1);
            printf("Ingrese el segundo número: ");
            scanf("%d", &n2);

            char oper;
            switch (opcion) {
                case 1: oper = '+'; break;
                case 2: oper = '-'; break;
                case 3: oper = '*'; break;
                case 4: oper = '/'; break;
                case 5: oper = '^'; break;
                default: oper = '\0'; break;
            }

            operacion(n1, n2, oper, &resultado, &error);

            if (error == 1) {
                printf("El resultado es: %.2f\n", resultado);
            } else if (error == -1) {
                printf("Error: operación no válida.\n");
            }
        }

    } while (opcion != 6);

    printf("Programa terminado.\n");
    return 0;
}

int menu() {
    int opcion;
    do {
        printf("\nMENU\n");
        printf("1 --> Sumar\n");
        printf("2 --> Restar\n");
        printf("3 --> Multiplicar\n");
        printf("4 --> Dividir\n");
        printf("5 --> Potencia\n");
        printf("6 --> Salir\n");
        printf("Elija opción: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 6) {
            printf("Opción no válida. Inténtelo de nuevo.\n");
        }
    } while (opcion < 1 || opcion > 6);

    return opcion;
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
