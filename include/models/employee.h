#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEE_NAME_LENGTH 80
#define MAX_ROLE_LENGTH 60

typedef struct {
    char name[MAX_EMPLOYEE_NAME_LENGTH];
    char role[MAX_ROLE_LENGTH];
    float base_salary;
    float monthly_bonus;
    int admission_year;
    float attendance_rate;
} Employee;

#endif
