#include <gtest/gtest.h>
#include "../src/AdministradorOperaciones.h"

TEST(AdministradorOperacionesTest, SePuedeCalcularResta)
{
    AdministradorOperaciones administrador;
    std::string entrada = "50-15";
    double resultadoEsperado = 35.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}

TEST(AdministradorOperacionesTest, SePuedeCalcularMultiplicacion)
{
    AdministradorOperaciones administrador;
    std::string entrada = "10*5";
    double resultadoEsperado = 50.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}

TEST(AdministradorOperacionesTest, SePuedeCalcularDivision)
{
    AdministradorOperaciones administrador;
    std::string entrada = "100/4";
    double resultadoEsperado = 25.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}

TEST(AdministradorOperacionesTest, ManejarDivisionPorCero)
{
    AdministradorOperaciones administrador;
    std::string entrada = "10/0";

    ASSERT_THROW(administrador.calcular(entrada), std::runtime_error);
}

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

TEST(AdministradorOperacionesTest, SePuedeEvaluarConPrecedencia)
{
    AdministradorOperaciones administrador;
    std::string entrada = "3+4*2";
    double resultadoEsperado = 11.0;

    double resultadoActual = administrador.calcular(entrada);

    ASSERT_DOUBLE_EQ(resultadoActual, resultadoEsperado);
}