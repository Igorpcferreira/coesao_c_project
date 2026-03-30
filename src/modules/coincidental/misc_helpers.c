#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "modules/coincidental/misc_helpers.h"

#define PI_VALUE 3.141592653589793

/*
 * Este modulo e propositalmente ruim do ponto de vista de coesao.
 * As funcoes abaixo nao compartilham um objetivo unico, nem o mesmo dado,
 * nem o mesmo momento de execucao. Elas foram agrupadas apenas por acaso.
 */
double calculate_circle_area(double radius) {
    return PI_VALUE * radius * radius;
}

int count_vowels(const char *text) {
    int total = 0;
    size_t index = 0U;

    while (text[index] != '\0') {
        const char character = (char)tolower((unsigned char)text[index]);

        if (character == 'a' || character == 'e' || character == 'i' ||
            character == 'o' || character == 'u') {
            total++;
        }

        index++;
    }

    return total;
}

int is_even(int value) {
    return value % 2 == 0;
}

void print_welcome_banner(void) {
    printf("\n=== COESAO COINCIDENTAL: UTILITARIOS MISCELANEOS ===\n");
    printf("Este modulo reune funcoes sem relacao direta entre si.\n");
    printf("Ele foi mantido apenas como contraexemplo didatico.\n");
}
