/**
 * Ainu monitoring service. 
 * 
 * @file lib/core/utils/utils.hpp
 * @author David (dev@davidggdev.es)
 * @brief Utils
 * @version 0.1
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License 
 */
#ifndef UTILS_HPP
#define UTILS_HPP

/** @brief Librarys */ 
#include "../../startup.hpp"

/** @brief Namespace class */
namespace Ainu
{
    /** @brief Monitor */
    class Utils
    {
    public:   
        static string loadFile(string filePath);  
        void writeFile(const std::string& name, const std::string& content);
    };
}
#endif