# Ainu
 
 Application to monitor web servers, mysql connections, processor statistics, 
 memory, etc. The software is divided into two distinct parts which 
 are the server and the monitor. 

 Server is in charge of raising in an ip:port a tpc service with http response 
 to consult the data collected by the monitor.The monitor on its side is in 
 charge of collecting all the information coming from the server and saving it 
 for future consultation. 
  
## Dependencies

- jsoncpp
- The best implementation to handle json types on c++ is in [jsoncpp](https://github.com/open-source-parsers/jsoncpp). Serialize an deseralize to array objects to handle data, load
file configurations, etc...