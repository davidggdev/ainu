/**
 * Ainu monitoring service.
 *
 * @file lib/core/utils/utils.hpp
 * @author David (dev@davidggdev.es)
 * @brief Utils
 * @version 0.2
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
        struct sysinfo systemInfo;
        static string loadFile(string filePath); 
        void writeFile(const std::string &name, const std::string &content);
        static Json::Value json2Object(string filePath);
        static bool obj2Json(Json::Value v, string filePath);
        static bool appendObj2Json(Json::Value v, string filePath);
    };
}
#endif