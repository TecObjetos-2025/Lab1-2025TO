#include <gtest/gtest.h>
#include "../src/AdministradorOperaciones.h"

TEST(AdministradorOperacionesTest, SePuedeCalcularSumaDeDosNumeros)
{
    AdministradorOperaciones administrador;
    std::string entrada = "12+34";
    double resultadoEsperado = 46.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}

TEST(AdministradorOperacionesTest, SePuedeCalcularSumaDeMuchosNumeros)
{
    AdministradorOperaciones administrador;
    std::string entrada = "1+2+3+4+5+6";
    double resultadoEsperado = 21.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}