/**
 * Ainu monitoring service.
 *
 * @file lib/core/monitor/monitor.cpp
 * @author David (dev@davidggdev.es)
 * @brief Monitor
 * @version 0.2
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */

/** @brief Librarys */
#include "monitor.hpp"
#include "../utils/utils.hpp"

/** @brief Namespaces */
using namespace Ainu;
using namespace std;

void Monitor::init(string verbose)
{ 
   if(verbose.compare("-v")== 0){
     cout << "Monitor init!" << endl;
   }

    for (;;)
    { 
        if(verbose.compare("-v")== 0){
            cout << "Monitor Tick" << endl; 
            if(Utils::appendObj2Json(this->getMemoryGroup(), "settings_save.json")){
                cout << "Memory check [X]" << endl;
            }
            if(Utils::appendObj2Json(this->getMysqlGroup(), "settings_save.json")){
                cout << "Mysql check [X]" << endl;
            } 
        } 
        sleep(10);
    }
}

Json::Value Monitor::getMemoryGroup()
{
    Json::Value sysinfoData;
    try
    {
        struct sysinfo s_info;
        int error = sysinfo(&s_info);
        if (error != 0)
            throw std::runtime_error(to_string(error));

        long sec = s_info.uptime, hr, min;
        hr = sec / (60 * 60);
        sec %= 60 * 60;
        min = sec / 60;
        sec %= 60;

        sysinfoData["memory"]["uptime"] = to_string(hr) + ":" + to_string(min) + ":" + to_string(sec);
        sysinfoData["memory"]["totalram"] = to_string(s_info.totalram);
        sysinfoData["memory"]["freeram"] = to_string(s_info.freeram);
        sysinfoData["memory"]["sharedram"] = to_string(s_info.sharedram);
        sysinfoData["memory"]["bufferram"] = to_string(s_info.bufferram);
        sysinfoData["memory"]["totalswap"] = to_string(s_info.totalswap);
        sysinfoData["memory"]["freeswap"] = to_string(s_info.freeswap);
        sysinfoData["memory"]["procs"] = to_string(s_info.procs);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }

    return sysinfoData;
}

Json::Value Monitor::getMysqlGroup()
{
    Json::Value mysqlData;
    try
    {
        mysqlData["server"] = "Monotema";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return mysqlData;
}