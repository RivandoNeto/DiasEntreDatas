#include <iostream>
#include "Data.h"
#include <stdlib.h>

using namespace std;

Data::Data()
{ }

Data::~Data()
{ }

int Data::bissexto(int ano)
{
    int qtd;
    if (ano%4) // nao divisivel por 4
    {
        qtd = 0;
    }

    else // divisivel por 4
    {
        if (ano%100) // nao divisivel por 100
        {
            qtd = 1;
        }
        else
        {
            if (! (ano%200)) // divisivel por 200
            {
                qtd = 1;
            }
            else // nao divisivel por 200
            {
                qtd = 0;
            }
        }
    }

    return qtd;
}

void Data::lerDatas(Data *dt1, Data *dt2)
{
    do
    {
        cout << "Digite o dia: ";
        cin >> dt1->dia;

        if (dt1->dia > 31 || dt1->dia < 1)
        {
            cout << "Dia invalido. Tente novamente!" << endl;
        }
    }
    while (dt1->dia > 31 || dt1->dia < 1);

    do
    {
        cout << "Digite o mes: ";
        cin >> dt1->mes;

        if (dt1->mes > 12 || dt1->mes < 1)
        {
            cout << "Mes invalido. Tente novamente!" << endl;
        }
    }
    while (dt1->mes > 12 || dt1->mes < 1);

    cout << "Digite o ano: ";
    cin >> dt1->ano;

    int qtdDiasMes;
    qtdDiasMes = diasMes(dt1->mes, dt1->ano);

    if (dt1->dia > qtdDiasMes)
    {
        do
        {
            cout << "O mes nao tem essa qtd de dias." << endl;
            cout << "Digite o dia: ";
            cin >> dt1->dia;
        }
        while (dt1->dia > qtdDiasMes);
    }

    cout << "Primeira data: ";
    if (dt1->dia < 10)
    {
        cout << "0";
    }
    cout << dt1->dia << "/";
    if (dt1->mes < 10)
    {
        cout << "0";
    }
    cout << dt1->mes << "/" << dt1->ano << endl << endl;


    do
    {
        cout << "Digite o dia: ";
        cin >> dt2->dia;

        if (dt2->dia > 31 || dt2->dia < 1)
        {
            cout << "Dia invalido. Tente novamente!" << endl;
        }
    }
    while (dt2->dia > 31 || dt2->dia < 1);

    do
    {
        cout << "Digite o mes: ";
        cin >> dt2->mes;

        if (dt2->mes > 12 || dt2->mes < 1)
        {
            cout << "Mes invalido. Tente novamente!" << endl;
        }
    }
    while (dt2->mes > 12 || dt2->mes < 1);

    cout << "Digite o ano: ";
    cin >> dt2->ano;

    qtdDiasMes = diasMes(dt2->mes, dt2->ano);

    if (dt2->dia > qtdDiasMes)
    {
        do
        {
            cout << "O mes nao tem essa qtd de dias." << endl;
            cout << "Digite o dia: ";
            cin >> dt2->dia;
        }
        while (dt2->dia > qtdDiasMes);
    }

    cout << "Segunda data: ";
    if (dt2->dia < 10)
    {
        cout << "0";
    }
    cout << dt2->dia << "/";
    if (dt2->mes < 10)
    {
        cout << "0";
    }
    cout << dt2->mes << "/" << dt2->ano << endl << endl;

    int aux;
    if (! (dt2->ano > dt1->ano) ) // o ano 2 nao eh depois do ano 1 
    {
        if (dt2->ano < dt1->ano)
        {
            aux = dt1->mes;
            dt1->mes = dt2->mes;
            dt2->mes = aux;

            aux = dt1->dia;
            dt1->dia = dt2->dia;
            dt2->dia = aux;

            aux = dt1->ano;
            dt1->ano = dt2->ano;
            dt2->ano = aux;
        }
        else
        {
            if (! (dt2->mes > dt1->mes) ) // o mes 2 nao eh depois do mes 1
            {
                if (dt2->mes < dt1->mes)
                {
                    aux = dt1->mes;
                    dt1->mes = dt2->mes;
                    dt2->mes = aux;

                    aux = dt1->dia;
                    dt1->dia = dt2->dia;
                    dt2->dia = aux;

                    aux = dt1->ano;
                    dt1->ano = dt2->ano;
                    dt2->ano = aux;
                }
                else if (dt2->dia < dt1->dia)
                {
                    aux = dt1->mes;
                    dt1->mes = dt2->mes;
                    dt2->mes = aux;

                    aux = dt1->dia;
                    dt1->dia = dt2->dia;
                    dt2->dia = aux;

                    aux = dt1->ano;
                    dt1->ano = dt2->ano;
                    dt2->ano = aux;
                }
            }
        }
    }

    cout << "Periodo de ";
    if (dt1->dia < 10)
    {
        cout << "0";
    }
    cout << dt1->dia << "/";
    if (dt1->mes < 10)
    {
        cout << "0";
    }
    cout << dt1->mes << "/" << dt1->ano << " ate ";
    if (dt2->dia < 10)
    {
        cout << "0";
    }
    cout << dt2->dia << "/";
    if (dt2->mes < 10)
    {
        cout << "0";
    }
    cout << dt2->mes << "/" << dt2->ano << "." << endl << endl;

}

int Data::diasMes(int mes, int ano)
{
    int qtd;
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            qtd = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            qtd = 30;
            break;
        case 2:
            qtd = 28 + bissexto(ano);
            break;
        default:
            qtd = 30;
    }

    return qtd;
}

int Data::calculaDias(Data dt1, Data dt2)
{

    int qtd = 0;
    int dia, mes, ano;

    dia = dt1.dia;
    mes = dt1.mes;
    ano = dt1.ano;

    if (dia < dt2.dia)
    {
        qtd += (dt2.dia - dia);
        dia = dt2.dia;
    }

    else if (dia > dt2.dia)
    {
        qtd += (diasMes(mes, ano) - dia + 1);
        dia = 1;
        if (mes == 12)
        {
            mes = 1;
            ano++;
        }
        else
        {
            mes++;
        }

        qtd += (dt2.dia - dia);
        dia = dt2.dia;
    }

    if (mes < dt2.mes)
    {
        while (mes != dt2.mes)
        {
            qtd += diasMes(mes, ano);
            mes++;
        }
    }
    else if (mes > dt2.mes)
    {
        while (mes != dt2.mes)
        {
            qtd += diasMes(mes, ano);
            if (mes != 12)
            {
                mes++;
            }
            else
            {
                mes = 1;
                ano++;
            }
        }
    }

    if (ano != dt2.ano)
    {
        while (ano != dt2.ano)
        {
            if (mes > 2 || (dia == 29 && mes == 2))
            {
                ano++;
                qtd += 365 + bissexto(ano);
            }
            else
            {
                qtd += 365 + bissexto(ano);
                ano++;
            }
        }
    }

    return qtd;
}
