#include <gtest/gtest.h>
#include "../src/arbol/ArbolExpresion.h"
#include "../src/parsers/ProcesadorOperacion.h"
#include <string>
#include <sstream>

TEST(ArbolExpresionTest, SePuedeConstruirYEvaluarExpresionSimple)
{
    ProcesadorOperacion procesador;
    std::string expresion = "5+3";
    std::vector<std::string> tokens_posfijos = procesador.convertirAPosfijo(expresion);
    ArbolExpresion arbol;

    arbol.construirArbol(tokens_posfijos);
    double resultadoActual = arbol.evaluar();

    ASSERT_DOUBLE_EQ(resultadoActual, 8.0);
}

TEST(ArbolExpresionTest, SePuedeConstruirYEvaluarExpresionConPrecedencia)
{
    ProcesadorOperacion procesador;
    std::string expresion = "3+4*2";
    std::vector<std::string> tokens_posfijos = procesador.convertirAPosfijo(expresion);
    ArbolExpresion arbol;

    arbol.construirArbol(tokens_posfijos);
    double resultadoActual = arbol.evaluar();

    ASSERT_DOUBLE_EQ(resultadoActual, 11.0);
}

TEST(ArbolExpresionTest, RecorridoInordenEsCorrecto)
{
    ProcesadorOperacion procesador;
    std::string expresion = "3*4+2";
    std::vector<std::string> tokens_posfijos = procesador.convertirAPosfijo(expresion);
    ArbolExpresion arbol;
    arbol.construirArbol(tokens_posfijos);

    // Obtener la salida estandar (capturar)
    // Inspiracion: https://baulderasec.wordpress.com/programando-2/programacion-c-por-la-practica/capitulo-viii/redireccion-de-la-entrada-y-salida/
    std::stringstream buffer;
    std::streambuf *old_cout = std::cout.rdbuf(buffer.rdbuf());

    arbol.recorrerInorden();

    std::cout.rdbuf(old_cout); // Retomar la salida
    ASSERT_EQ(buffer.str(), "3 * 4 + 2 \n");
}