//
// Created by David M Muñoz García on 01/11/24.
//

#ifndef DATABASECONFIG_H
#define DATABASECONFIG_H

#pragma once

#include <libpq-fe.h>
#include <string>

class DatabaseConfig {
public:
    DatabaseConfig();
    ~DatabaseConfig();

    bool connect();
    void disconnect();
    PGconn* getConnection() const;

private:
    PGconn* conn;
    bool isConnected;
};


#endif //DATABASECONFIG_H
