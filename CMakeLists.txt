cmake_minimum_required(VERSION 3.29)
project(DbInventory)

set(CMAKE_CXX_STANDARD 17)

# Define el ejecutable antes de enlazar las bibliotecas
add_executable(DbInventory main.cpp
        db_config/DatabaseConfig.cpp
        db_config/DatabaseConfig.h)

# Agrega la ejecución y enlazado con PostgreSQL
find_package(PostgreSQL REQUIRED)

# Incluye los encabezados y bibliotecas de PostgreSQL
include_directories(${PostgreSQL_INCLUDE_DIRS})
target_link_libraries(DbInventory PRIVATE ${PostgreSQL_LIBRARIES})
