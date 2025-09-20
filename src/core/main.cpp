#include <iostream>
#include <string>
#include "../parsers/ProcesadorOperacion.h"
#include "../arbol/ArbolExpresion.h"
#include "../utilidades/Utilidades.h"
#include "../factories/OperacionFactory.h"
#include "../operaciones/Operacion.h"
#include <stack>
#include <vector>

void mostrarEvaluacionPasoAPaso(const std::vector<std::string> &tokens)
{
    std::stack<double> pila_pasos;

    for (const auto &token : tokens)
    {
        if (!Utilidades::esOperador(token[0]))
        {
            pila_pasos.push(std::stod(token));
        }
        else
        {
            double numero2 = pila_pasos.top();
            pila_pasos.pop();
            double numero1 = pila_pasos.top();
            pila_pasos.pop();

            Operacion *operacion = OperacionFactory::crearOperacion(token[0]);
            double resultado = operacion->ejecutar(numero1, numero2);
            delete operacion;

            pila_pasos.push(resultado);

            std::cout << "Paso: " << numero1 << " " << token << " " << numero2 << " = " << resultado << std::endl;
        }
    }

    std::cout << "Resultado final: " << pila_pasos.top() << std::endl;
}

int main()
{
    std::string expresion = "12+4*3";
    ProcesadorOperacion procesador;

    // Aplicar la misma logica que en la clase Arbol de Expresion y Procesador de Operaciones

    std::vector<std::string> tokens_posfijos = procesador.convertirAPosfijo(expresion);

    mostrarEvaluacionPasoAPaso(tokens_posfijos);

    // Verificacion con metodo evaluar
    ArbolExpresion arbol;
    arbol.construirArbol(tokens_posfijos);
    double resultado_arbol = arbol.evaluar();
    std::cout << "Resultado de la evaluacion del arbol: " << resultado_arbol << std::endl;

    return 0;
}