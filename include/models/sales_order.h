#ifndef SALES_ORDER_H
#define SALES_ORDER_H

#define MAX_CUSTOMER_NAME_LENGTH 100
#define MAX_PRODUCT_NAME_LENGTH 100

typedef struct {
    char customer_name[MAX_CUSTOMER_NAME_LENGTH];
    char product_name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float unit_price;
    float discount_percentage;
} SalesOrder;

typedef struct {
    char customer_name[MAX_CUSTOMER_NAME_LENGTH];
    char product_name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
    float unit_price;
    float gross_total;
    float discount_amount;
    float net_total;
    char status[40];
} ProcessedOrder;

#endif
