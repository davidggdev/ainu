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
#include <iostream>

using namespace std;

int main()
{
    cout << "hi!" << endl;
    return 0;
}