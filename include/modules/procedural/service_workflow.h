#ifndef SERVICE_WORKFLOW_H
#define SERVICE_WORKFLOW_H

#include "models/service_ticket.h"

void execute_service_procedure(const ServiceTicket *ticket, TicketProcedureResult *result);
void print_service_procedure_report(const ServiceTicket *ticket, const TicketProcedureResult *result);

#endif
