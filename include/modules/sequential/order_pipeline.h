#ifndef ORDER_PIPELINE_H
#define ORDER_PIPELINE_H

#include "models/sales_order.h"

void initialize_processed_order(const SalesOrder *input_order, ProcessedOrder *processed_order);
void calculate_gross_total(ProcessedOrder *processed_order);
void calculate_discount(ProcessedOrder *processed_order, float discount_percentage);
void calculate_net_total(ProcessedOrder *processed_order);
void define_order_status(ProcessedOrder *processed_order);
void process_order(const SalesOrder *input_order, ProcessedOrder *processed_order);
void print_processed_order(const ProcessedOrder *processed_order);

#endif
