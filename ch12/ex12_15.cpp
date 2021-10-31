/* Created by vleo on 21/10/31
 * Copyright(c)2021 vleo. All rights reserved.
 * 
 * ex12_10 
 * "word counter" practice
 */ 

#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::cin; using std::cout; using std::endl;
using std::shared_ptr;

struct connection
{
    string ip;
    int port;
    connection(string ip_, int port_) : ip(ip_), port(port_) {}
};
struct destination
{
    string ip;
    int port;
    destination(string ip_, int port_) : ip(ip_), port(port_) {}
};

connection connect(destination* pDest)
{
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port)) ;
    cout << "creating conneciton(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection conn)
{
    cout << "connection close(" << conn.ip << ":" << conn.port << ")" << endl;
}


void f(destination& d)
{
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, [](connection* pConn){ disconnect(*pConn);} );
    cout << "connecting now(" << p.use_count() << ")" << endl;
}




int main()
{
    destination dest("127.0.0.1",8080);
    f(dest);
    return 0;
}



