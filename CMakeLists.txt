cmake_minimum_required(VERSION 3.10)
project(CalculadoraTDD)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añade Google Test como un subdirectorio
add_subdirectory(googletest)

# Añade el directorio donde se encuentran los archivos de cabecera de tu proyecto
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(calculadora_app src/main.cpp src/Suma.cpp src/ProcesadorOperacion.cpp src/OperacionFactory.cpp src/AdministradorOperaciones.cpp src/Resta.cpp src/Multiplicacion.cpp src/Division.cpp)

# Declara el ejecutable de pruebas
add_executable(test_runner test/test_suma.cpp test/test_procesador.cpp test/test_administrador.cpp src/Suma.cpp src/OperacionFactory.cpp src/AdministradorOperaciones.cpp src/ProcesadorOperacion.cpp
 src/Resta.cpp src/Multiplicacion.cpp src/Division.cpp)

# Enlaza el ejecutable de pruebas con las bibliotecas de Google Test
# 'gtest_main' es un alias que crea CMake para la biblioteca de pruebas
target_link_libraries(test_runner gtest_main)