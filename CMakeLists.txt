cmake_minimum_required(VERSION 3.10)
project(CalculadoraTDD)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añade Google Test como un subdirectorio
add_subdirectory(googletest)

# Añade el directorio donde se encuentran los archivos de cabecera de tu proyecto
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# ==============================================================================
# FUENTES DEL PROYECTO ORGANIZADOS POR MÓDULOS
# ==============================================================================

# Fuentes del módulo core (componentes principales)
set(CORE_SOURCES
    src/core/main.cpp
    src/core/AdministradorOperaciones.cpp
)

# Fuentes del módulo operaciones (implementaciones aritméticas)
set(OPERACIONES_SOURCES
    src/operaciones/Suma.cpp
    src/operaciones/Resta.cpp
    src/operaciones/Multiplicacion.cpp
    src/operaciones/Division.cpp
)

# Fuentes del módulo factories (creación de objetos)
set(FACTORIES_SOURCES
    src/factories/OperacionFactory.cpp
)

# Fuentes del módulo parsers (procesamiento de entrada)
set(PARSERS_SOURCES
    src/parsers/ProcesadorOperacion.cpp
)

# Fuentes del módulo core (componentes principales)
set(ARBOL_SOURCES
    src/arbol/Nodo.cpp
)

# Combinar todas las fuentes
set(ALL_SOURCES 
    ${CORE_SOURCES}
    ${OPERACIONES_SOURCES}
    ${FACTORIES_SOURCES}
    ${PARSERS_SOURCES}
    ${ARBOL_SOURCES}
)

# ==============================================================================
# EJECUTABLES DEL PROYECTO
# ==============================================================================

# Aplicación principal
add_executable(calculadora_app ${ALL_SOURCES})

# Ejecutable de pruebas (incluye todas las fuentes + archivos de test)
add_executable(test_runner 
    test/test_suma.cpp 
    test/test_procesador.cpp 
    test/test_administrador.cpp 
    ${ALL_SOURCES})

# ==============================================================================
# CONFIGURACIÓN DE ENLACE
# ==============================================================================

# Enlaza el ejecutable de pruebas con las bibliotecas de Google Test
# 'gtest_main' es un alias que crea CMake para la biblioteca de pruebas
target_link_libraries(test_runner gtest_main)

# ==============================================================================
# CONFIGURACIONES ADICIONALES
# ==============================================================================

# Configuraciones de compilación opcionales
# set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
# set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")