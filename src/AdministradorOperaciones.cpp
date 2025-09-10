#include "AdministradorOperaciones.h"
#include "ProcesadorOperacion.h"
#include "Suma.h"
#include <vector>

double AdministradorOperaciones::calcular(const std::string &entrada)
{
    ProcesadorOperacion procesador;
    std::vector<int> numeros = procesador.procesar(entrada);

    Suma suma;
    int resultado = 0;
    for (int numero : numeros)
    {
        resultado = suma.sumar(resultado, numero);
    }
}