#ifndef SERVICE_TICKET_H
#define SERVICE_TICKET_H

#define MAX_CUSTOMER_NAME_LENGTH 80
#define MAX_SERVICE_DESCRIPTION_LENGTH 120
#define MAX_STATUS_LENGTH 50
#define MAX_PRIORITY_LENGTH 20

typedef struct {
    char customer_name[MAX_CUSTOMER_NAME_LENGTH];
    char service_description[MAX_SERVICE_DESCRIPTION_LENGTH];
    int estimated_complexity;
    int customer_waiting_days;
    int requires_onsite_visit;
} ServiceTicket;

typedef struct {
    char priority[MAX_PRIORITY_LENGTH];
    int estimated_hours;
    char status[MAX_STATUS_LENGTH];
} TicketProcedureResult;

#endif
