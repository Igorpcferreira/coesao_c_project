#ifndef STARTUP_TASKS_H
#define STARTUP_TASKS_H

#include "models/startup_context.h"

void run_startup_tasks(StartupContext *context);
void print_startup_report(const StartupContext *context);

#endif
