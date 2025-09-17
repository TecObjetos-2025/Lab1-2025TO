#include "AdministradorOperaciones.h"
#include "../parsers/ProcesadorOperacion.h"
#include "../factories/OperacionFactory.h"
#include "../operaciones/Operacion.h"
#include <vector>
#include <stdexcept>
#include <stack>

int precedencia(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

double AdministradorOperaciones::calcular(const std::string &expresion)
{
    ProcesadorOperacion procesador;
    std::vector<std::string> tokens_infijos = procesador.procesar(expresion);

    std::vector<std::string> tokens_posfijos;
    std::stack<char> operadores;

    // Conversion Infijo a Posfijo

    for (const auto &token : tokens_infijos)
    {
        if (isdigit(token[0]))
        {
            tokens_posfijos.push_back(token);
        }
        else
        {
            char op_actual = token[0];
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(op_actual))
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

    std::stack<double> valores;
    for (const auto &token : tokens_posfijos)
    {
        if (isdigit(token[0]))
        {
            valores.push(std::stod(token));
        }
        else
        {
            if (valores.size() < 2)
            {
                throw std::invalid_argument("Error(1): La expresion no esta bien formada");
            }
            double numero2 = valores.top();
            valores.pop();
            double numero1 = valores.top();
            valores.pop();

            Operacion *operacion = OperacionFactory::crearOperacion(token[0]);
            double resultado = operacion->ejecutar(numero1, numero2);
            delete operacion;

            valores.push(resultado);
        }
    }

    if (valores.size() != 1)
    {
        throw std::invalid_argument("Error(2): La expresion no esta bien formada");
    }

    return valores.top();
}
