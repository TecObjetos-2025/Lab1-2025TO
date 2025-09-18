#ifndef PROCESADOROPERACION_H
#define PROCESADOROPERACION_H

#include <string>
#include <vector>
#include <stack>

class ProcesadorOperacion
{
private:
    /*
     * Tomar una cadena y devolver un vector de strings
     */
    std::vector<std::string> tokenizar(const std::string &entrada);
    int obtenerPrecedencia(char op);
    bool esOperador(char op);

public:
    std::vector<std::string> convertirAPosfijo(const std::string &expresion);
};

#endif