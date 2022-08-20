#include "Data.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void)
{
    system("cls");
    Data dt1, dt2, o;

    o.lerDatas(&dt1, &dt2);

    int qtd;
    qtd = o.calculaDias(dt1, dt2);

    cout << "Passaram-se " << qtd << " dia(s) entre as datas.\n\n";
    int ano, mes, dia;

    ano = qtd/365;
    mes = (qtd%365)/30;
    dia = (qtd%365)%30;

    cout << "Equivalente a cerca de " << ano << " ano(s), " << mes << " mes(es) e " << dia << " dia(s)." << endl << endl;
    getchar();
    getchar();

    return 0;
}
