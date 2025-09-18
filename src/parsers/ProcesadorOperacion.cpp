#include "ProcesadorOperacion.h"
#include "../utilidades/Utilidades.h"

std::vector<std::string> ProcesadorOperacion::tokenizar(const std::string &entrada)
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

std::vector<std::string> ProcesadorOperacion::convertirAPosfijo(const std::string &expresion)
{
    std::vector<std::string> tokens_infijos = tokenizar(expresion);

    std::vector<std::string> tokens_posfijos;
    std::stack<char> operadores;

    for (const auto &token : tokens_infijos)
    {
        if (!Utilidades::esOperador(token[0]))
        {
            tokens_posfijos.push_back(token);
        }
        else
        {
            char op_actual = token[0];
            while (!operadores.empty() && Utilidades::obtenerPrecedencia(operadores.top()) >= Utilidades::obtenerPrecedencia(op_actual))
            {
                tokens_posfijos.push_back(std::string(1, operadores.top()));
                operadores.pop();
            }
            operadores.push(op_actual);
        }
    }
    while (!operadores.empty()) // Vaciar la pila
    {
        tokens_posfijos.push_back(std::string(1, operadores.top()));
        operadores.pop();
    }
    return tokens_posfijos;
}