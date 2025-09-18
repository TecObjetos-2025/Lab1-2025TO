#include "Utilidades.h"
#include <cctype>

namespace Utilidades
{

    int obtenerPrecedencia(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    bool esOperador(char op)
    {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

};