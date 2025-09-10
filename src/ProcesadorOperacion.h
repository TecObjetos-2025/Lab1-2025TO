#ifndef PROCESADOROPERACION_H
#define PROCESADOROPERACION_H

#include <string>
#include <vector>

class ProcesadorOperacion
{
public:
    /*
     * Tomar una cadena y devolver un vector de enteros
     */
    std::vector<int> procesar(const std::string &entrada);
};

#endif