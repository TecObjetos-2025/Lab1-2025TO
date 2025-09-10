#include "AdministradorOperaciones.h"
#include "ProcesadorOperacion.h"
#include "Suma.h"
#include <vector>

double AdministradorOperaciones::calcular(const std::string &expresion)
{
    ProcesadorOperacion procesador;
    std::vector<int> numeros = procesador.procesar(expresion);

    Suma suma;
    int resultado = 0;
    for (int numero : numeros)
    {
        resultado = suma.sumar(resultado, numero);
    }

    return static_cast<double>(resultado);
}