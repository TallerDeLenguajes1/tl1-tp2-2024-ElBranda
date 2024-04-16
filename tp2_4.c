#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CANT_PC 5

struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};

void registrarPC(struct compu *PC);
void lista(struct compu *PC, int cantPC);
int PCvieja(struct compu *PC, int cantPC);
int PCveloz(struct compu *PC, int cantPC);

int main() {
    struct compu *PC = (struct compu *)malloc(CANT_PC*sizeof(struct compu));

    srand(time(NULL)); //setteando la seed

    for (int i = 0; i < CANT_PC; i++) {
        printf("PC %d\n", i+1);
        registrarPC(&PC[i]);
    }

    lista(PC, CANT_PC);

    printf("La PC mas vieja es: PC %d\n", PCvieja(PC, CANT_PC));
    printf("La PC mas veloz es: PC %d", PCveloz(PC, CANT_PC));

    return 0;
}

void registrarPC(struct compu *PC) {
    char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    PC->tipo_cpu = (char *)malloc(10*sizeof(char));

    printf("Ingrese la velocidad: ");
    scanf("%d", &PC->velocidad);
    printf("Ingrese el anio: ");
    scanf("%d", &PC->anio);
    printf("Ingrese la cantidad de nucleos: ");
    scanf("%d", &PC->cantidad);
    strcpy(PC->tipo_cpu, tipos[rand()%6]);
}

void lista(struct compu *PC, int cantPC) {
    for (int i = 0; i < cantPC; i++) {
        printf("PC %d\n", i+1);
        printf("Velocidad: %d\n", (PC+i)->velocidad);
        printf("Anio: %d\n", (PC+i)->anio);
        printf("Nucleos: %d\n", (PC+i)->cantidad);
        printf("Tipo: %s\n", (PC+i)->tipo_cpu);
    }
}

int PCvieja(struct compu *PC, int cantPC) {
    int myr = 2023, i_myr;

    for (int i = 0; i < cantPC; i++) {
        if ((PC+i)->anio < myr) {
            myr = (PC+i)->anio;
            i_myr = i+1;
        }
    }

    return i_myr;
}

int PCveloz(struct compu *PC, int cantPC){
    int vel = 0, i_vel;

    for (int i = 0; i < cantPC; i++) {
        if ((PC+i)->velocidad > vel) {
            vel = (PC+i)->velocidad;
            i_vel = i+1;
        }
    }

    return i_vel;
}