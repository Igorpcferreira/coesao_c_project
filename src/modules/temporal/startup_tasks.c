#include <stdio.h>

#include "modules/temporal/startup_tasks.h"

/* Cada etapa abaixo existe porque precisa acontecer no momento de inicializacao. */
static void load_configuration(StartupContext *context) {
    context->configuration_loaded = 1;
}

static void initialize_logger(StartupContext *context) {
    context->logger_initialized = 1;
}

static void connect_database(StartupContext *context) {
    context->database_connected = 1;
}

static void warm_cache(StartupContext *context) {
    context->cache_warmed = 1;
}

/* Reune tarefas disparadas no mesmo instante do ciclo de vida da aplicacao. */
void run_startup_tasks(StartupContext *context) {
    load_configuration(context);
    initialize_logger(context);
    connect_database(context);
    warm_cache(context);
}

void print_startup_report(const StartupContext *context) {
    printf("\n=== COESAO TEMPORAL: TAREFAS DE INICIALIZACAO ===\n");
    printf("Servico: %s\n", context->service_name);
    printf("Ambiente: %s\n", context->environment);
    printf("Configuracao carregada: %s\n", context->configuration_loaded ? "Sim" : "Nao");
    printf("Logger iniciado: %s\n", context->logger_initialized ? "Sim" : "Nao");
    printf("Banco conectado: %s\n", context->database_connected ? "Sim" : "Nao");
    printf("Cache aquecido: %s\n", context->cache_warmed ? "Sim" : "Nao");
}
