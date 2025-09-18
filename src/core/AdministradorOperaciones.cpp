#include "AdministradorOperaciones.h"
#include "../parsers/ProcesadorOperacion.h"
#include "../factories/OperacionFactory.h"
#include "../operaciones/Operacion.h"
#include "../arbol/ArbolExpresion.h"
#include <vector>
#include <stdexcept>
#include <stack>

double AdministradorOperaciones::calcular(const std::string &expresion)
{
    // Convertir de infijo a postfijo
    ProcesadorOperacion procesador;
    std::vector<std::string> tokens_posfijos = procesador.convertirAPosfijo(expresion);

    // Construir el arbol
    ArbolExpresion arbol;
    arbol.construirArbol(tokens_posfijos);

    return arbol.evaluar();
}
