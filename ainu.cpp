/**
 * Ainu monitoring service.
 *
 * Application to monitor web servers, mysql connections, processor statistics,
 * memory, etc. The software is divided into two distinct parts which
 * are the server and the monitor.
 * Server is in charge of raising in an ip:port a tpc service with http response
 * to consult the data collected by the monitor.The monitor on its side is in
 * charge of collecting all the information coming from the server and saving it
 * for future consultation.
 *
 * @file ainu.cpp
 * @author David (dev@davidggdev.es)
 * @brief Server monitoring service
 * @version 0.1
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */

/** @brief Librarys */
#include "lib/startup.hpp"

#include "lib/core/utils/utils.hpp"
#include "lib/core/server/server.hpp"
#include "lib/core/monitor/monitor.hpp"

/**
 * @brief Init microservice to Serve
 */
void initThreadServer()
{
    Ainu::Server AinuServer;
    AinuServer.init();
}

/**
 * @brief Init microservice to Serve
 */
void initThreadMonitor()
{
    Ainu::Monitor AinuMonitor;
    AinuMonitor.init();
}

/**
 * @brief Main
 *
 * @return int 0
 */
int main()
{  
    /**
     * Threads microservices
     */
    thread AinuServerThread(initThreadServer);
    thread AinuMonitorThread(initThreadMonitor);

    /**
     * @brief Prevent if AinuServerThread is free
     */
    if (AinuServerThread.joinable())
        AinuServerThread.join();

    /**
     * @brief Prevent if AinuMonitorThread is free
     */
    if (AinuMonitorThread.joinable())
        AinuMonitorThread.join();

    return 0;
}
