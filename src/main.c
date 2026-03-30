#include <stdio.h>

#include "models/employee.h"
#include "models/notification.h"
#include "models/service_ticket.h"
#include "models/startup_context.h"
#include "modules/coincidental/misc_helpers.h"
#include "modules/communicational/employee_record.h"
#include "modules/logical/notification_dispatcher.h"
#include "modules/procedural/service_workflow.h"
#include "modules/temporal/startup_tasks.h"

/*
 * O main apenas organiza a demonstracao dos cinco tipos de coesao pedidos.
 * Cada funcao abaixo aciona um modulo especifico e deixa a leitura bem direta.
 */
static void demonstrate_communicational_cohesion(void) {
    const Employee employee = {
        "Marina Souza",
        "Analista de Suporte",
        3200.00f,
        450.00f,
        2020,
        96.0f
    };

    print_employee_summary(&employee, 2026);
}

static void demonstrate_procedural_cohesion(void) {
    const ServiceTicket ticket = {
        "Clinica Vida",
        "Trocar cabecote da impressora e recalibrar o sistema",
        7,
        9,
        1
    };
    TicketProcedureResult result = {"", 0, ""};

    execute_service_procedure(&ticket, &result);
    print_service_procedure_report(&ticket, &result);
}

static void demonstrate_temporal_cohesion(void) {
    StartupContext context = {
        "ClinicGateway",
        "Producao",
        0,
        0,
        0,
        0
    };

    run_startup_tasks(&context);
    print_startup_report(&context);
}

static void demonstrate_logical_cohesion(void) {
    const Notification notification = {
        "paciente@exemplo.com",
        "Sua consulta foi confirmada para amanha as 14:00."
    };

    dispatch_notification(CHANNEL_EMAIL, &notification);
}

static void demonstrate_coincidental_cohesion(void) {
    print_welcome_banner();
    printf("Area do circulo de raio 3: %.2f\n", calculate_circle_area(3.0));
    printf("Quantidade de vogais em 'coesao': %d\n", count_vowels("coesao"));
    printf("14 e par? %s\n", is_even(14) ? "Sim" : "Nao");
}

int main(void) {
    printf("Estudo de coesao em C\n");
    printf("Tipos abordados: comunicacional, procedural, temporal, logica e coincidental\n");

    demonstrate_communicational_cohesion();
    demonstrate_procedural_cohesion();
    demonstrate_temporal_cohesion();
    demonstrate_logical_cohesion();
    demonstrate_coincidental_cohesion();

    return 0;
}
