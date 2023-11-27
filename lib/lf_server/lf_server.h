#include <WebServer.h>

#define HTTP_REST_PORT 80 // define port

class LfServer : WebServer
{
public:
    LfServer(uint16_t port);
    void begin();
};