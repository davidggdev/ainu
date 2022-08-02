# @file Makefile
# @author David (dev@davidggdev.es)
# @brief Makefile configuration
# @version 0.2
# @date 2022-07-31
# @license GPL
# @license https://opensource.org/licenses/gpl-license.php GNU Public License 

# Application 
APP_MAIN = ainu.cpp
APP_BIN = bin/ainu

# Librarys
MONITOR_FLAG = lib/core/monitor/monitor.cpp
SERVER_FLAG = lib/core/server/server.cpp
UTILS_FLAG = lib/core/utils/utils.cpp

# Librarys compiled
PTHREAD = -pthread
JSONFLAG= -ljsoncpp 
all:
	g++ -o $(APP_BIN) $(APP_MAIN) $(MONITOR_FLAG) $(SERVER_FLAG) $(UTILS_FLAG) $(PTHREAD) $(JSONFLAG)