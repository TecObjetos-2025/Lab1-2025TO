#include <gtest/gtest.h>
#include "../src/ProcesadorOperacion.h"
#include <vector>

TEST(ProcesadorTest, SePuedeTokenizarEntradaDeDosNumeros)
{
    ProcesadorOperacion procesador;
    std::string entrada = "12+34";
    std::vector<std::string> resultadoEsperado = {"12", "+", "34"};

    std::vector<std::string> resultadoActual = procesador.procesar(entrada);

    ASSERT_EQ(resultadoActual, resultadoEsperado);
}

TEST(ProcesadorTest, SePuedeTokenizarEntradaDeMuchosNumeros)
{
    ProcesadorOperacion procesador;
    std::string entrada = "1+2+3+4+5+6";
    std::vector<std::string> resultadoEsperado = {"1", "+", "2", "+", "3", "+", "4", "+", "5", "+", "6"};

    std::vector<std::string> resultadoActual = procesador.procesar(entrada);

    ASSERT_EQ(resultadoActual, resultadoEsperado);
}