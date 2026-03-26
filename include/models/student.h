#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 100
#define EXAM_COUNT 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    float exam_scores[EXAM_COUNT];
    float attendance_rate;
} Student;

#endif
