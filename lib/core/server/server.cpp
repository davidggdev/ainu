/**
 * Ainu monitoring service.
 *
 * @file lib/core/server/server.cpp
 * @author David (dev@davidggdev.es)
 * @brief Server
 * @version 0.2
 * @date 2022-07-31
 * @license GPL
 * @license https://opensource.org/licenses/gpl-license.php GNU Public License
 */

/** @brief Librarys */
#include "server.hpp"
#include "../utils/utils.hpp"
#include <string>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

/** @brief Namespaces */
using namespace Ainu;
using namespace std;

void Server::init(string verbose)
{
    this->startServer();
}

void Server::startServer()
{
    cout << "Server init!" << endl;

    // declare variables
    // the port number
    int port = 9090;

    // the integer to store the file descriptor number
    // which will represent a socket on which the server
    // will be listening
    int listenfd = -1;

    // the file descriptor representing the connection to the client
    int connfd = -1;

    // the number of bytes read
    int numRead = -1;

    // the buffer to store text
    char data[1024];

    // the structures representing the server and client
    // addresses respectively
    sockaddr_in serverAddr, cliAddr;

    // stores the size of the client's address
    socklen_t cliLen = sizeof(cliAddr);

    // create a socket that uses
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    // set the structure to all zeros
    memset(&serverAddr, 0, sizeof(serverAddr));

    // convert the port number to network representation
    serverAddr.sin_port = htons(port);

    // set the server family
    serverAddr.sin_family = AF_INET;

    // retrieve packets without having to know your IP address
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // associate the address with the socket
    if (bind(listenfd, (sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    // listen for connections on socket listenfd.
    if (listen(listenfd, 100) < 0)
    {
        perror("listen");
        exit(1);
    }

    cerr << "\nServer started!\n";

    // wait forever for connections to come
    while (true)
    {
        cerr << "\nWaiting for someone to connect..\n";

        // a structure to store the client address
        if ((connfd = accept(listenfd, (sockaddr *)&cliAddr, &cliLen)) < 0)
        {
            perror("accept");
            exit(1);
        }

        // receive whatever the client sends
        if ((numRead = read(connfd, data, sizeof(data))) < 0)
        {
            perror("read");
            exit(1);
        }

        // NULL terminate the received string
        data[numRead] = '\0';

        cerr << "\nRECEIVED: '" << data << "' from the client\n";
        // cerr<<"Bytes read: "<<numRead<<endl;

        // set the array to all zeros
        memset(&data, 0, sizeof(data));
 
        // message to send 
        string responseMonitoring = Utils::loadFile("settings_save.json");
        string message = "HTTP/1.1 200 OK\r\n\r\n" + responseMonitoring;

        // send the client a message
        if (write(connfd, message.c_str(), message.length()) < 0)
        {
            perror("write");
            exit(1);
        }

        // close the socket
        close(connfd);
    }
}
