#include <gtest/gtest.h>
#include "../src/operaciones/Suma.h"

TEST(SumaTest, sumarDosNumerosPositivos)
{
    Suma calculadora;
    int numero1 = 5;
    int numero2 = 3;
    int resultadoEsperado = 8;

    int resultadoActual = calculadora.ejecutar(numero1, numero2);

    ASSERT_EQ(resultadoActual, resultadoEsperado);
}

TEST(SumaTest, PuedeSumarCadenaSencilla)
{
    Suma calculadora;
    int numero1 = 12;
    int numero2 = 34;

    ASSERT_EQ(calculadora.ejecutar(numero1, numero2), 46);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}