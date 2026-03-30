#include <stdio.h>
#include <string.h>

#include "modules/procedural/service_workflow.h"

/* Define a prioridade do atendimento seguindo regras simples de negocio. */
static void define_priority(const ServiceTicket *ticket, TicketProcedureResult *result) {
    if (ticket->customer_waiting_days >= 7 || ticket->estimated_complexity >= 8) {
        strcpy(result->priority, "Alta");
    } else if (ticket->estimated_complexity >= 5) {
        strcpy(result->priority, "Media");
    } else {
        strcpy(result->priority, "Baixa");
    }
}

/* Estima o esforco considerando complexidade e necessidade de visita tecnica. */
static void estimate_service_hours(const ServiceTicket *ticket, TicketProcedureResult *result) {
    result->estimated_hours = ticket->estimated_complexity * 2;

    if (ticket->requires_onsite_visit) {
        result->estimated_hours += 3;
    }
}

/* Fecha o procedimento com base no que foi calculado nas etapas anteriores. */
static void define_status(const ServiceTicket *ticket, const TicketProcedureResult *result,
                          TicketProcedureResult *final_result) {
    if (ticket->customer_waiting_days > 10 && strcmp(result->priority, "Alta") == 0) {
        strcpy(final_result->status, "Escalonar imediatamente");
    } else if (final_result->estimated_hours > 12) {
        strcpy(final_result->status, "Agendar especialista");
    } else {
        strcpy(final_result->status, "Atender na fila padrao");
    }
}

/*
 * A coesao procedural aparece porque as funcoes fazem sentido pela ordem em que rodam.
 * Se a ordem mudar, o fluxo perde consistencia.
 */
void execute_service_procedure(const ServiceTicket *ticket, TicketProcedureResult *result) {
    define_priority(ticket, result);
    estimate_service_hours(ticket, result);
    define_status(ticket, result, result);
}

void print_service_procedure_report(const ServiceTicket *ticket, const TicketProcedureResult *result) {
    printf("\n=== COESAO PROCEDURAL: FLUXO DE ATENDIMENTO ===\n");
    printf("Cliente: %s\n", ticket->customer_name);
    printf("Servico: %s\n", ticket->service_description);
    printf("Complexidade: %d\n", ticket->estimated_complexity);
    printf("Dias de espera: %d\n", ticket->customer_waiting_days);
    printf("Precisa de visita tecnica: %s\n", ticket->requires_onsite_visit ? "Sim" : "Nao");
    printf("Prioridade: %s\n", result->priority);
    printf("Horas estimadas: %d\n", result->estimated_hours);
    printf("Decisao do procedimento: %s\n", result->status);
}
