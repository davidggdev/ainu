/**
 * Ainu monitoring service.
 *
 * @file lib/core/utils/utils.cpp
 * @author David (dev@davidggdev.es)
 * @brief Utils
 * @version 0.1
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */

/** @brief Librarys */
#include "utils.hpp"

/** @brief Namespaces */
using namespace Ainu;
using namespace std;

string Utils::loadFile(string filePath)
{
    ifstream t(filePath);
    string bufferResult((std::istreambuf_iterator<char>(t)),
                             std::istreambuf_iterator<char>());
    return bufferResult;
}

void Utils::writeFile(const std::string &name, const std::string &content)
{
    std::ofstream outfile;
    outfile.open(name, std::ios_base::app);
    outfile << content;
}