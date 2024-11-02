//
// Created by David M Muñoz García on 01/11/24.
//

#include "DatabaseConfig.h"
#include <iostream>

// Constructor de DatabaseConfig
DatabaseConfig::DatabaseConfig() : conn(nullptr), isConnected(false) {}

// Destructor que cierra la conexión si está abierta
DatabaseConfig::~DatabaseConfig() {
    disconnect();
}

// Método para conectar a la base de datos
bool DatabaseConfig::connect() {
    // Información de conexión: reemplaza los valores con tus credenciales
    std::string connInfo = "host=localhost port=5432 dbname=mydatabase user=myuser password=mypassword";

    // Conecta a la base de datos
    conn = PQconnectdb(connInfo.c_str());

    // Verifica si la conexión fue exitosa
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "Error de conexión: " << PQerrorMessage(conn) << std::endl;
        disconnect();
        return false;
    }

    isConnected = true;
    std::cout << "Conexión exitosa a la base de datos." << std::endl;
    return true;
}

// Método para desconectar la base de datos
void DatabaseConfig::disconnect() {
    if (isConnected && conn != nullptr) {
        PQfinish(conn);
        conn = nullptr;
        isConnected = false;
    }
}

// Obtiene la conexión actual
PGconn* DatabaseConfig::getConnection() const {
    return conn;
}