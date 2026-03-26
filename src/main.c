#include <stdio.h>

#include "models/student.h"
#include "models/sales_order.h"
#include "modules/functional/student_performance.h"
#include "modules/sequential/order_pipeline.h"

/* Demonstra o modulo funcional com um exemplo de aluno. */
static void demonstrate_functional_cohesion(void) {
    const Student student = {
        .name = "Ana Carolina",
        .exam_scores = {8.5f, 7.0f, 9.0f, 6.5f},
        .attendance_rate = 92.0f
    };

    print_student_report(&student);
}

/* Demonstra o modulo sequencial com um exemplo de pedido. */
static void demonstrate_sequential_cohesion(void) {
    const SalesOrder input_order = {
        .customer_name = "Carlos Henrique",
        .product_name = "Notebook para estudo",
        .quantity = 2,
        .unit_price = 350.0f,
        .discount_percentage = 10.0f
    };

    ProcessedOrder processed_order;
    process_order(&input_order, &processed_order);
    print_processed_order(&processed_order);
}

/* Ponto de entrada: apenas organiza a demonstracao dos modulos. */
int main(void) {
    printf("Projeto demonstrativo sobre coesao em C\n");
    printf("- Modulo 1: coesao funcional\n");
    printf("- Modulo 2: coesao sequencial\n");

    demonstrate_functional_cohesion();
    demonstrate_sequential_cohesion();

    return 0;
}
