// NOMBRE Y APELLIDOS: MARTÍN SENDE POMBO
// CURSO: 2019/20   ESTUDIOS: GRADO DE BIOTECNOLOGÍA

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main()
{
    // Permite emplear los carateres propios del español incluidos en el alfabeto ASCII extendido
    setlocale(LC_ALL, "spanish");

    const int cargos_electos;
    printf("\nPrograma de Simulación de la Ley Electoral D'Hont\n\nIntroduzca el número de cargos electos a repartir:  ");
    scanf("%d", &cargos_electos);

/* En base a estas instrucciones de selección, el programa descarta aquel valor asignado al número de escaños (siempre un dato de
tipo entero) que sea incompatible con las condiciones a evaluar más adelante */

    const int numero_partidos;
    if(cargos_electos <= 0){
        printf("\n\nEl valor introducido no es válido.\n\n");
        system("pause");
    }
    else {
        printf("\nIntroduzca el número de partidos participantes:  ");
        scanf("%d", &numero_partidos);
        printf("\n\n");
    }

/* En estas instrucciones de selección se abordan los casos en los que, el número total de partidos que se presentan a las
elecciones (siempre un dato de tipo entero) toma un valor imposible o improbable */

    if (numero_partidos < 0){
        printf("El último número introducido no es válido.\n\n");
        system("pause");
    }
    else if(numero_partidos == 0){
            printf ("Esto implica que ningún partido ha concurrido a las elecciones.\n\n");
            system("pause");
        }

/* Mediante las siguientes instrucciones de selección, puede introducirse el número de votos obtenido por hasta 3 partidos
diferentes, cantidad que teóricamente podría ampliarse. Después, lo usa para calcular el porcentaje de voto obtenido por cada
uno de ellos y les asigna un determinado número de escaños, en función del sistema D'Hondt */

    if(numero_partidos == 1){
        // Permite introducir el número de votos de un único partido
        printf("Introduzca el número de votos conseguidos por el Partido 1: ");
        const int numero_votos_P1;
        scanf("%d", &numero_votos_P1);

        // Devuelve el porcentaje de votos y número de electos correspondientes al caso de un único partido
        printf("\nPorcentaje de votos del Partido 1: 100,00");
        printf("\n\nAsignación de cargos electos por Partido \n\nCargos electos Partido 1: %d\n\n", cargos_electos);
        system("pause");
    }
    else if(numero_partidos == 2){
            // Permite introducir el número de votos de 2 partidos distintos
            printf("Introduzca el número de votos conseguidos por el Partido 1: ");
            const int numero_votos_P1;
            scanf("%d", &numero_votos_P1);

            printf("Introduzca el número de votos conseguidos por el Partido 2: ");
            const int numero_votos_P2;
            scanf("%d", &numero_votos_P2);

            // Esta bloque de sentencias calcula el porcentaje de voto de cada uno de los 2 partidos
            float porcentaje_votos_P1, porcentaje_votos_P2;
            float numero_total_votos = numero_votos_P1 + numero_votos_P2;
            porcentaje_votos_P1 = (float)(numero_votos_P1 * 100 / numero_total_votos);
            porcentaje_votos_P2 = (float)(numero_votos_P2 * 100 / numero_total_votos);

            // Este bucle calcula el nº de cargos electos correspondiente a cada partido
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

            // Imprime en pantalla el porcentaje de votos y número de electos correspondientes a cada uno de los 2 partidos
            printf("\nPorcentaje de votos del Partido 1: %.2f", porcentaje_votos_P1);
            printf("\nPorcentaje de votos del Partido 2: %.2f", porcentaje_votos_P2);

            printf("\n\nAsignación de cargos electos por Partido");
            printf("\n\nCargos electos Partido 1: %d", numero_escanos_P1);
            printf("\nCargos electos Partido 2: %d\n\n", numero_escanos_P2);
            system("pause");
        }
        else if(numero_partidos == 3){
                // Permite introducir el número de votos de 3 partidos distintos
                printf("Introduzca el número de votos conseguidos por el Partido 1: ");
                const int numero_votos_P1;
                scanf("%d", &numero_votos_P1);

                printf("Introduzca el número de votos conseguidos por el Partido 2: ");
                const int numero_votos_P2;
                scanf("%d", &numero_votos_P2);

                printf("Introduzca el número de votos conseguidos por el Partido 3: ");
                const int numero_votos_P3;
                scanf("%d", &numero_votos_P3);

                // Esta bloque de sentencias calcula el porcentaje de voto de cada uno de los 3 partidos
                float porcentaje_votos_P1, porcentaje_votos_P2, porcentaje_votos_P3;
                float numero_total_votos = numero_votos_P1 + numero_votos_P2 + numero_votos_P3;
                porcentaje_votos_P1 = (float)(numero_votos_P1 * 100 / numero_total_votos);
                porcentaje_votos_P2 = (float)(numero_votos_P2 * 100 / numero_total_votos);
                porcentaje_votos_P3 = (float)(numero_votos_P3 * 100 / numero_total_votos);

                // Este bucle calcula el nº de cargos electos correspondiente a cada partido
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

                // Imprime en pantalla el porcentaje de votos y número de electos correspondientes a cada uno de los 3 partidos
                printf("\nPorcentaje de votos del Partido 1: %.2f", porcentaje_votos_P1);
                printf("\nPorcentaje de votos del Partido 2: %.2f", porcentaje_votos_P2);
                printf("\nPorcentaje de votos del Partido 3: %.2f", porcentaje_votos_P3);

                printf("\n\nAsignación de cargos electos por Partido");
                printf("\n\nCargos electos Partido 1: %d", numero_escanos_P1);
                printf("\nCargos electos Partido 2: %d", numero_escanos_P2);
                printf("\nCargos electos Partido 3: %d\n\n", numero_escanos_P3);
                system("pause");
            }

    if(numero_partidos > 3){
        // Imprime en pantalla un mensaje de disculpa
        printf("Lamentablemente, esta posibilidad aún no ha sido implementada.\n\n");
        system("pause");
    }
}
