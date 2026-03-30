#include <stdio.h>

#include "modules/communicational/employee_record.h"

#define PROMOTION_MIN_YEARS 3
#define PROMOTION_MIN_ATTENDANCE 90.0f

/* Calcula a compensacao mensal total com base no salario e no bonus. */
float calculate_monthly_compensation(const Employee *employee) {
    return employee->base_salary + employee->monthly_bonus;
}

/* Mede ha quantos anos a funcionaria esta na empresa. */
int calculate_years_in_company(const Employee *employee, int current_year) {
    return current_year - employee->admission_year;
}

/* Verifica se a assiduidade atende ao criterio esperado. */
int has_high_attendance(const Employee *employee) {
    return employee->attendance_rate >= PROMOTION_MIN_ATTENDANCE;
}

/* Combina tempo de empresa e assiduidade para avaliar promocao. */
int is_eligible_for_promotion(const Employee *employee, int current_year) {
    const int years_in_company = calculate_years_in_company(employee, current_year);
    return years_in_company >= PROMOTION_MIN_YEARS && has_high_attendance(employee);
}

/* Todas as funcoes deste modulo giram em torno do mesmo registro: Employee. */
void print_employee_summary(const Employee *employee, int current_year) {
    printf("\n=== COESAO COMUNICACIONAL: REGISTRO DE FUNCIONARIO ===\n");
    printf("Funcionaria: %s\n", employee->name);
    printf("Cargo: %s\n", employee->role);
    printf("Salario base: R$ %.2f\n", employee->base_salary);
    printf("Bonus mensal: R$ %.2f\n", employee->monthly_bonus);
    printf("Compensacao mensal total: R$ %.2f\n", calculate_monthly_compensation(employee));
    printf("Anos na empresa: %d\n", calculate_years_in_company(employee, current_year));
    printf("Assiduidade: %.1f%%\n", employee->attendance_rate);
    printf("Elegivel para promocao: %s\n",
           is_eligible_for_promotion(employee, current_year) ? "Sim" : "Nao");
}
