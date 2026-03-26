#include <stdio.h>
#include <string.h>

#include "modules/sequential/order_pipeline.h"

/*
 * Modulo com coesao sequencial:
 * cada etapa depende do resultado calculado na etapa anterior.
 */

void initialize_processed_order(const SalesOrder *input_order, ProcessedOrder *processed_order) {
    /* Prepara a estrutura de saída com base no pedido recebido. */
    if (input_order == NULL || processed_order == NULL) {
        return;
    }

    strcpy(processed_order->customer_name, input_order->customer_name);
    strcpy(processed_order->product_name, input_order->product_name);
    processed_order->quantity = input_order->quantity;
    processed_order->unit_price = input_order->unit_price;
    processed_order->gross_total = 0.0f;
    processed_order->discount_amount = 0.0f;
    processed_order->net_total = 0.0f;
    strcpy(processed_order->status, "Em processamento");
}

void calculate_gross_total(ProcessedOrder *processed_order) {
    /* Primeira etapa financeira do pipeline. */
    if (processed_order == NULL) {
        return;
    }

    processed_order->gross_total = processed_order->quantity * processed_order->unit_price;
}

void calculate_discount(ProcessedOrder *processed_order, float discount_percentage) {
    /* O desconto usa diretamente o total bruto calculado antes. */
    if (processed_order == NULL) {
        return;
    }

    processed_order->discount_amount = processed_order->gross_total * (discount_percentage / 100.0f);
}

void calculate_net_total(ProcessedOrder *processed_order) {
    /* O total líquido depende do bruto e do desconto. */
    if (processed_order == NULL) {
        return;
    }

    processed_order->net_total = processed_order->gross_total - processed_order->discount_amount;
}

void define_order_status(ProcessedOrder *processed_order) {
    /* A decisão final depende do total líquido gerado no fluxo. */
    if (processed_order == NULL) {
        return;
    }

    if (processed_order->net_total >= 500.0f) {
        strcpy(processed_order->status, "Aprovado com prioridade");
        return;
    }

    if (processed_order->net_total > 0.0f) {
        strcpy(processed_order->status, "Aprovado");
        return;
    }

    strcpy(processed_order->status, "Invalido");
}

void process_order(const SalesOrder *input_order, ProcessedOrder *processed_order) {
    /* Orquestra todas as etapas em ordem sequencial. */
    if (input_order == NULL || processed_order == NULL) {
        return;
    }

    initialize_processed_order(input_order, processed_order);
    calculate_gross_total(processed_order);
    calculate_discount(processed_order, input_order->discount_percentage);
    calculate_net_total(processed_order);
    define_order_status(processed_order);
}

void print_processed_order(const ProcessedOrder *processed_order) {
    /* Mostra o resultado consolidado do pipeline. */
    if (processed_order == NULL) {
        printf("Nao foi possivel exibir o pedido processado.\n");
        return;
    }

    printf("\n=== RESULTADO DO PROCESSAMENTO SEQUENCIAL ===\n");
    printf("Cliente: %s\n", processed_order->customer_name);
    printf("Produto: %s\n", processed_order->product_name);
    printf("Quantidade: %d\n", processed_order->quantity);
    printf("Preco unitario: R$ %.2f\n", processed_order->unit_price);
    printf("Total bruto: R$ %.2f\n", processed_order->gross_total);
    printf("Desconto: R$ %.2f\n", processed_order->discount_amount);
    printf("Total liquido: R$ %.2f\n", processed_order->net_total);
    printf("Status: %s\n", processed_order->status);
}
