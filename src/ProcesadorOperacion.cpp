#include "ProcesadorOperacion.h"

std::vector<std::string> ProcesadorOperacion::procesar(const std::string &entrada)
{
    std::vector<std::string> tokens;
    std::string numero_actual = "";

    for (char caracter : entrada)
    {
        if (isdigit(caracter))
        {
            numero_actual += caracter;
        }
        else
        {
            // Si se encuentra un NO digito
            if (!numero_actual.empty())
            {
                tokens.push_back(numero_actual);
                numero_actual.clear();
            }

            if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/')
            {
                tokens.push_back(std::string(1, caracter));
            }
        }
    }

    // Guardar el ultimo numero de la cadena
    if (!numero_actual.empty())
    {
        tokens.push_back(numero_actual);
    }

    return tokens;
}