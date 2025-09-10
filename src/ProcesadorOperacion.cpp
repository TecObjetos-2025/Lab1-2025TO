#include "ProcesadorOperacion.h"

std::vector<int> ProcesadorOperacion::procesar(const std::string &entrada)
{
    std::vector<int> tokens;
    std::string numero_actual = "";

    for (char caracter : entrada)
    {
        if (isdigit(caracter))
        {
            numero_actual += caracter;
        }
        else if (caracter == '+' && !numero_actual.empty())
        {
            tokens.push_back(std::stoi(numero_actual));
            numero_actual.clear();
        }
    }

    // Guardar el ultimo numero de la cadena
    if (!numero_actual.empty())
    {
        tokens.push_back(std::stoi(numero_actual));
    }

    return tokens;
}