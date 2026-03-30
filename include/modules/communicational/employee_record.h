#ifndef EMPLOYEE_RECORD_H
#define EMPLOYEE_RECORD_H

#include "models/employee.h"

float calculate_monthly_compensation(const Employee *employee);
int calculate_years_in_company(const Employee *employee, int current_year);
int has_high_attendance(const Employee *employee);
int is_eligible_for_promotion(const Employee *employee, int current_year);
void print_employee_summary(const Employee *employee, int current_year);

#endif
