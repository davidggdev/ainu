/**
 * Ainu monitoring service.
 *
 * @file lib/core/utils/utils.cpp
 * @author David (dev@davidggdev.es)
 * @brief Utils
 * @version 0.2
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
    outfile.open(name, std::ios_base::trunc);
    outfile << content;
}

Json::Value Utils::json2Object(string filePath)
{
    Json::Value output;

    try
    {
          
    ifstream fileBuffer;
    fileBuffer.open(filePath);
    fileBuffer >> output;
    fileBuffer.close();
   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    
   return output;
}

bool Utils::obj2Json(Json::Value v, string filePath)
{
    try
    {
        std::ofstream outfile;
        outfile.open(filePath, std::ios_base::trunc);
        outfile << v;
        outfile.close();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    return false;
}

bool Utils::appendObj2Json(Json::Value v, string filePath)
{
    try
    {
        std::ofstream outfile;
        outfile.open(filePath, std::ios_base::app);
        outfile << "[";
        outfile << v ;
        outfile << "],";
        outfile.close();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    return false;
}

 