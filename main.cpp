#include <iostream>
#include "db_config/DatabaseConfig.h"

int main() {
    DatabaseConfig db;
    if (db.connect()) {
        std::cout << "Operación en la base de datos completada con éxito." << std::endl;
    } else {
        std::cerr << "No se pudo conectar a la base de datos." << std::endl;
    }

    db.disconnect();  // Cierra la conexión manualmente, aunque el destructor también la cerrará
    return 0;
}
