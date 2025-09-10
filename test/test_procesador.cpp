#include <gtest/gtest.h>
#include "../src/ProcesadorOperacion.h"
#include <vector>

TEST(ProcesadorTest, SePuedeTokenizarEntradaDeDosNumeros)
{
    ProcesadorOperacion procesador;
    std::string entrada = "12+34";
    std::vector<int> resultadoEsperado = {12, 34};

    std::vector<int> resultadoActual = procesador.procesar(entrada);

    ASSERT_EQ(resultadoActual, resultadoEsperado);
}

TEST(ProcesadorTest, SePuedeTokenizarEntradaDeMuchosNumeros)
{
    ProcesadorOperacion procesador;
    std::string entrada = "1+2+3+4+5+6";
    std::vector<int> resultadoEsperado = {1, 2, 3, 4, 5, 6};

    std::vector<int> resultadoActual = procesador.procesar(entrada);

    ASSERT_EQ(resultadoActual, resultadoEsperado);
}