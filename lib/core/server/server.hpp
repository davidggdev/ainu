/**
 * Ainu monitoring service.
 *
 * @file lib/core/server/server.hpp
 * @author David (dev@davidggdev.es)
 * @brief Server
 * @version 0.2
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */
#ifndef SERVER_HPP
#define SERVER_HPP

/** @brief Librarys */
#include "../../startup.hpp"

/** @brief Namespace class */
namespace Ainu
{
    /** @brief Monitor */
    class Server
    {
    public:   
        void init(string verbose);
        void startServer();   
    };
}
#endif