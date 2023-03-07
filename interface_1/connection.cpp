#include "connection.h"

Connection::Connection(){}
bool Connection::createconnection()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("donataires");
    db.setUserName("raouf");
    db.setPassword("raouf");
    if(db.open())test=true;
    return test;

}
void Connection::closeConnection(){db.close();}
