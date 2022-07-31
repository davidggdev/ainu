/**
 * Ainu monitoring service. 
 * 
 * @file lib/core/monitor/monitor.hpp
 * @author David (dev@davidggdev.es)
 * @brief Monitor
 * @version 0.1
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License 
 */
#ifndef MONITOR_HPP
#define MONITOR_HPP

/** @brief Librarys */
#include "../../startup.hpp"

/** @brief Namespace class */
namespace Ainu
{
    /** @brief Monitor */
    class Monitor
    {
    public: 
        void init(); 
        string get_uptime();
    };
}
#endif