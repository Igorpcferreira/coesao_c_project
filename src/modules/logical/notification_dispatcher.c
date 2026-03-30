#include <stdio.h>

#include "modules/logical/notification_dispatcher.h"

/* Cada funcao trata uma variacao da mesma categoria logica: envio de notificacao. */
static void send_email(const Notification *notification) {
    printf("E-MAIL enviado para %s: %s\n", notification->recipient, notification->message);
}

static void send_sms(const Notification *notification) {
    printf("SMS enviado para %s: %s\n", notification->recipient, notification->message);
}

static void send_push(const Notification *notification) {
    printf("PUSH enviado para %s: %s\n", notification->recipient, notification->message);
}

const char *describe_channel(NotificationChannel channel) {
    switch (channel) {
        case CHANNEL_EMAIL:
            return "E-mail";
        case CHANNEL_SMS:
            return "SMS";
        case CHANNEL_PUSH:
            return "Push";
        default:
            return "Desconhecido";
    }
}

/*
 * O modulo e logicamente coeso porque todas as opcoes pertencem ao mesmo grupo conceitual.
 * A funcao executada muda conforme o canal informado.
 */
void dispatch_notification(NotificationChannel channel, const Notification *notification) {
    printf("\n=== COESAO LOGICA: DISPARO DE NOTIFICACAO ===\n");
    printf("Canal selecionado: %s\n", describe_channel(channel));

    switch (channel) {
        case CHANNEL_EMAIL:
            send_email(notification);
            break;
        case CHANNEL_SMS:
            send_sms(notification);
            break;
        case CHANNEL_PUSH:
            send_push(notification);
            break;
        default:
            printf("Canal invalido.\n");
            break;
    }
}
