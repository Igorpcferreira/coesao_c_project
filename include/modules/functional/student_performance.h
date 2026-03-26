#ifndef STUDENT_PERFORMANCE_H
#define STUDENT_PERFORMANCE_H

#include "models/student.h"

float calculate_average(const Student *student);
float find_highest_score(const Student *student);
float find_lowest_score(const Student *student);
int has_minimum_attendance(const Student *student);
const char *get_student_status(const Student *student);
void print_student_report(const Student *student);

#endif
