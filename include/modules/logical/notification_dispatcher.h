#ifndef NOTIFICATION_DISPATCHER_H
#define NOTIFICATION_DISPATCHER_H

#include "models/notification.h"

void dispatch_notification(NotificationChannel channel, const Notification *notification);
const char *describe_channel(NotificationChannel channel);

#endif
