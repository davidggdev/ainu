/**
 * Ainu monitoring service.
 *
 * @file lib/core/monitor/monitor.cpp
 * @author David (dev@davidggdev.es)
 * @brief Monitor
 * @version 0.1
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */

/** @brief Librarys */
#include "monitor.hpp"
#include "../utils/utils.hpp"
#include <sys/sysinfo.h>

/** @brief Namespaces */
using namespace Ainu;
using namespace std;

void Monitor::init()
{
    cout << "Monitor init method!" << endl;

    Ainu::Utils utils;

    for (;;)
    {
        cout << "Monitor Tick" << endl;
        utils.writeFile("c.json", this->get_uptime());
        sleep(10);
    }
}

string Monitor::get_uptime()
{
    struct sysinfo s_info;
    int error = sysinfo(&s_info);
    if (error != 0)
    {
        printf("code error = %d\n", error);
    }
    long sec = s_info.uptime, hr, min;
    hr = sec / (60 * 60);
    sec %= 60 * 60;
    min = sec / 60;
    sec %= 60; 
    return "[{\"uptime\" : {\"hours\" : \"" + to_string(hr) + "\",\"minutes\" : \"" + to_string(min) + "\",\"secs\" : \"" + to_string(sec) + "\",}}]";
}
