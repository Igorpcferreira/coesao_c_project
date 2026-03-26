#include <stdio.h>

#include "modules/functional/student_performance.h"

/*
 * Modulo com coesao funcional:
 * todas as funções existem para avaliar o desempenho de um aluno.
 */

static int is_student_pointer_invalid(const Student *student) {
    return student == NULL;
}

float calculate_average(const Student *student) {
    /* Soma todas as notas e devolve a média final. */
    if (is_student_pointer_invalid(student)) {
        return 0.0f;
    }

    float sum_of_scores = 0.0f;

    for (int exam_index = 0; exam_index < EXAM_COUNT; exam_index++) {
        sum_of_scores += student->exam_scores[exam_index];
    }

    return sum_of_scores / EXAM_COUNT;
}

float find_highest_score(const Student *student) {
    /* Percorre o vetor para descobrir a maior nota. */
    if (is_student_pointer_invalid(student)) {
        return 0.0f;
    }

    float highest_score = student->exam_scores[0];

    for (int exam_index = 1; exam_index < EXAM_COUNT; exam_index++) {
        if (student->exam_scores[exam_index] > highest_score) {
            highest_score = student->exam_scores[exam_index];
        }
    }

    return highest_score;
}

float find_lowest_score(const Student *student) {
    /* Percorre o vetor para descobrir a menor nota. */
    if (is_student_pointer_invalid(student)) {
        return 0.0f;
    }

    float lowest_score = student->exam_scores[0];

    for (int exam_index = 1; exam_index < EXAM_COUNT; exam_index++) {
        if (student->exam_scores[exam_index] < lowest_score) {
            lowest_score = student->exam_scores[exam_index];
        }
    }

    return lowest_score;
}

int has_minimum_attendance(const Student *student) {
    /* Regra simples de frequência mínima. */
    if (is_student_pointer_invalid(student)) {
        return 0;
    }

    return student->attendance_rate >= 75.0f;
}

const char *get_student_status(const Student *student) {
    /* Consolida as regras acadêmicas de aprovação. */
    if (is_student_pointer_invalid(student)) {
        return "Dados invalidos";
    }

    const float average = calculate_average(student);
    const int attendance_is_valid = has_minimum_attendance(student);

    if (!attendance_is_valid) {
        return "Reprovado por falta";
    }

    if (average >= 7.0f) {
        return "Aprovado";
    }

    if (average >= 5.0f) {
        return "Recuperacao";
    }

    return "Reprovado por nota";
}

void print_student_report(const Student *student) {
    /* Exibe um resumo final reutilizando as funções do módulo. */
    if (is_student_pointer_invalid(student)) {
        printf("Nao foi possivel gerar o relatorio do aluno.\n");
        return;
    }

    printf("\n=== RELATORIO DE DESEMPENHO DO ALUNO ===\n");
    printf("Nome: %s\n", student->name);
    printf("Notas: %.1f | %.1f | %.1f | %.1f\n",
           student->exam_scores[0],
           student->exam_scores[1],
           student->exam_scores[2],
           student->exam_scores[3]);
    printf("Media: %.2f\n", calculate_average(student));
    printf("Maior nota: %.1f\n", find_highest_score(student));
    printf("Menor nota: %.1f\n", find_lowest_score(student));
    printf("Frequencia: %.1f%%\n", student->attendance_rate);
    printf("Situacao final: %s\n", get_student_status(student));
}
