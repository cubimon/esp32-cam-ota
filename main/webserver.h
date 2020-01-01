#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "esp_http_server.h"

httpd_handle_t start_webserver();

void stop_webserver();

#endif
