// NOMBRE Y APELLIDOS: MART�N SENDE POMBO
// CURSO: 2019/20   ESTUDIOS: GRADO DE BIOTECNOLOG�A

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main()
{
    // Permite emplear los carateres propios del espa�ol incluidos en el alfabeto ASCII extendido
    setlocale(LC_ALL, "spanish");

    const int cargos_electos;
    printf("\nPrograma de Simulaci�n de la Ley Electoral D'Hont\n\nIntroduzca el n�mero de cargos electos a repartir:  ");
    scanf("%d", &cargos_electos);

/* En base a estas instrucciones de selecci�n, el programa descarta aquel valor asignado al n�mero de esca�os (siempre un dato de
tipo entero) que sea incompatible con las condiciones a evaluar m�s adelante */

    const int numero_partidos;
    if(cargos_electos <= 0){
        printf("\n\nEl valor introducido no es v�lido.\n\n");
        system("pause");
    }
    else {
        printf("\nIntroduzca el n�mero de partidos participantes:  ");
        scanf("%d", &numero_partidos);
        printf("\n\n");
    }

/* En estas instrucciones de selecci�n se abordan los casos en los que, el n�mero total de partidos que se presentan a las
elecciones (siempre un dato de tipo entero) toma un valor imposible o improbable */

    if (numero_partidos < 0){
        printf("El �ltimo n�mero introducido no es v�lido.\n\n");
        system("pause");
    }
    else if(numero_partidos == 0){
            printf ("Esto implica que ning�n partido ha concurrido a las elecciones.\n\n");
            system("pause");
        }

/* Mediante las siguientes instrucciones de selecci�n, puede introducirse el n�mero de votos obtenido por hasta 3 partidos
diferentes, cantidad que te�ricamente podr�a ampliarse. Despu�s, lo usa para calcular el porcentaje de voto obtenido por cada
uno de ellos y les asigna un determinado n�mero de esca�os, en funci�n del sistema D'Hondt */

    if(numero_partidos == 1){
        // Permite introducir el n�mero de votos de un �nico partido
        printf("Introduzca el n�mero de votos conseguidos por el Partido 1: ");
        const int numero_votos_P1;
        scanf("%d", &numero_votos_P1);

        // Devuelve el porcentaje de votos y n�mero de electos correspondientes al caso de un �nico partido
        printf("\nPorcentaje de votos del Partido 1: 100,00");
        printf("\n\nAsignaci�n de cargos electos por Partido \n\nCargos electos Partido 1: %d\n\n", cargos_electos);
        system("pause");
    }
    else if(numero_partidos == 2){
            // Permite introducir el n�mero de votos de 2 partidos distintos
            printf("Introduzca el n�mero de votos conseguidos por el Partido 1: ");
            const int numero_votos_P1;
            scanf("%d", &numero_votos_P1);

            printf("Introduzca el n�mero de votos conseguidos por el Partido 2: ");
            const int numero_votos_P2;
            scanf("%d", &numero_votos_P2);

            // Esta bloque de sentencias calcula el porcentaje de voto de cada uno de los 2 partidos
            float porcentaje_votos_P1, porcentaje_votos_P2;
            float numero_total_votos = numero_votos_P1 + numero_votos_P2;
            porcentaje_votos_P1 = (float)(numero_votos_P1 * 100 / numero_total_votos);
            porcentaje_votos_P2 = (float)(numero_votos_P2 * 100 / numero_total_votos);

            // Este bucle calcula el n� de cargos electos correspondiente a cada partido
            int numero_escanos_P1 = 0, numero_escanos_P2 = 0, contador = 0; float divisor1 = 0.0000, divisor2 = 0.0000, res_div_P1 = 0.0000, res_div_P2 = 0.0000;
            while(contador < cargos_electos){
                contador = numero_escanos_P1 + numero_escanos_P2;
                res_div_P1 = (numero_votos_P1 / (divisor1 + 1));
                res_div_P2 = (numero_votos_P2 / (divisor2 + 1));

                if((res_div_P1 >= res_div_P2) && (numero_escanos_P1 < cargos_electos) && (contador < cargos_electos)){
                        ++numero_escanos_P1;
                        ++divisor1;
                }
                if((res_div_P2 >= res_div_P1) && (numero_escanos_P2 < cargos_electos) && (contador < cargos_electos)){
                        ++numero_escanos_P2;
                        ++divisor2;
                }
            }

            // Imprime en pantalla el porcentaje de votos y n�mero de electos correspondientes a cada uno de los 2 partidos
            printf("\nPorcentaje de votos del Partido 1: %.2f", porcentaje_votos_P1);
            printf("\nPorcentaje de votos del Partido 2: %.2f", porcentaje_votos_P2);

            printf("\n\nAsignaci�n de cargos electos por Partido");
            printf("\n\nCargos electos Partido 1: %d", numero_escanos_P1);
            printf("\nCargos electos Partido 2: %d\n\n", numero_escanos_P2);
            system("pause");
        }
        else if(numero_partidos == 3){
                // Permite introducir el n�mero de votos de 3 partidos distintos
                printf("Introduzca el n�mero de votos conseguidos por el Partido 1: ");
                const int numero_votos_P1;
                scanf("%d", &numero_votos_P1);

                printf("Introduzca el n�mero de votos conseguidos por el Partido 2: ");
                const int numero_votos_P2;
                scanf("%d", &numero_votos_P2);

                printf("Introduzca el n�mero de votos conseguidos por el Partido 3: ");
                const int numero_votos_P3;
                scanf("%d", &numero_votos_P3);

                // Esta bloque de sentencias calcula el porcentaje de voto de cada uno de los 3 partidos
                float porcentaje_votos_P1, porcentaje_votos_P2, porcentaje_votos_P3;
                float numero_total_votos = numero_votos_P1 + numero_votos_P2 + numero_votos_P3;
                porcentaje_votos_P1 = (float)(numero_votos_P1 * 100 / numero_total_votos);
                porcentaje_votos_P2 = (float)(numero_votos_P2 * 100 / numero_total_votos);
                porcentaje_votos_P3 = (float)(numero_votos_P3 * 100 / numero_total_votos);

                // Este bucle calcula el n� de cargos electos correspondiente a cada partido
                int numero_escanos_P1 = 0, numero_escanos_P2 = 0, numero_escanos_P3 = 0, contador = 0;
                float divisor1 = 0.0000, divisor2 = 0.0000, divisor3 = 0.0000;
                float res_div_P1 = numero_votos_P1, res_div_P2 = numero_votos_P2, res_div_P3 = numero_votos_P3;
                while(contador < cargos_electos){
                    ++contador;

                    if((res_div_P1 >= res_div_P2) && (res_div_P1 >= res_div_P3) && ((numero_escanos_P1 + numero_escanos_P2 + numero_escanos_P3) < cargos_electos)){
                        ++numero_escanos_P1;
                        ++divisor1;
                        res_div_P1 = (numero_votos_P1 / (divisor1 + 1));
                    }
                    else if((res_div_P2 >= res_div_P1) && (res_div_P2 >= res_div_P3) && ((numero_escanos_P1 + numero_escanos_P2 + numero_escanos_P3) < cargos_electos)){
                            ++numero_escanos_P2;
                            ++divisor2;
                            res_div_P2 = (numero_votos_P2 / (divisor2 + 1));
                        }
                        else if((res_div_P3 >= res_div_P1) && (res_div_P3 >= res_div_P2) && ((numero_escanos_P1 + numero_escanos_P2 + numero_escanos_P3) < cargos_electos)){
                                ++numero_escanos_P3;
                                ++divisor3;
                                res_div_P3 = (numero_votos_P3 / (divisor3 + 1));
                            }
                }

                // Imprime en pantalla el porcentaje de votos y n�mero de electos correspondientes a cada uno de los 3 partidos
                printf("\nPorcentaje de votos del Partido 1: %.2f", porcentaje_votos_P1);
                printf("\nPorcentaje de votos del Partido 2: %.2f", porcentaje_votos_P2);
                printf("\nPorcentaje de votos del Partido 3: %.2f", porcentaje_votos_P3);

                printf("\n\nAsignaci�n de cargos electos por Partido");
                printf("\n\nCargos electos Partido 1: %d", numero_escanos_P1);
                printf("\nCargos electos Partido 2: %d", numero_escanos_P2);
                printf("\nCargos electos Partido 3: %d\n\n", numero_escanos_P3);
                system("pause");
            }

    if(numero_partidos > 3){
        // Imprime en pantalla un mensaje de disculpa
        printf("Lamentablemente, esta posibilidad a�n no ha sido implementada.\n\n");
        system("pause");
    }
}
