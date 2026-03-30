#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#define MAX_RECIPIENT_LENGTH 80
#define MAX_MESSAGE_LENGTH 180

typedef enum {
    CHANNEL_EMAIL = 1,
    CHANNEL_SMS = 2,
    CHANNEL_PUSH = 3
} NotificationChannel;

typedef struct {
    char recipient[MAX_RECIPIENT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Notification;

#endif
