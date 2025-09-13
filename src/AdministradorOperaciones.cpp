#include "AdministradorOperaciones.h"
#include "ProcesadorOperacion.h"
#include "OperacionFactory.h"
#include "Operacion.h"
#include <vector>
#include <stdexcept>

double AdministradorOperaciones::calcular(const std::string &expresion)
{
    ProcesadorOperacion procesador;
    auto tokens = procesador.procesar(expresion);

    if (tokens.size() != 3)
    {
        throw std::invalid_argument("Error: Formato de expresion no valida");
    }

    try
    {
        double numero1 = std::stod(tokens[0]);
        char operador = tokens[1][0];
        double numero2 = std::stod(tokens[2]);

        Operacion *operacion = OperacionFactory::crearOperacion(operador);

        double resultado = operacion->ejecutar(numero1, numero2);

        delete operacion; // Liberar memoria

        return resultado;
    }
    catch (const std::invalid_argument &e)
    {
        throw std::invalid_argument("Error de conversion o formato: " + std::string(e.what()));
    }
}