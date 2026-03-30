#ifndef STARTUP_CONTEXT_H
#define STARTUP_CONTEXT_H

#define MAX_SERVICE_NAME_LENGTH 80
#define MAX_ENVIRONMENT_LENGTH 40

typedef struct {
    char service_name[MAX_SERVICE_NAME_LENGTH];
    char environment[MAX_ENVIRONMENT_LENGTH];
    int configuration_loaded;
    int logger_initialized;
    int database_connected;
    int cache_warmed;
} StartupContext;

#endif
