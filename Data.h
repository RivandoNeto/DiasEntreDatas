#include <iostream>

class Data
{
    public:
        Data();
        ~Data();

        int dia;
        int mes;
        int ano;
        
        void lerDatas(Data *dt1, Data *dt2); // para realizar a leitura das datas
        int calculaDias(Data dt1, Data dt2); // para calcular e retornar a quantidade de dias
        int diasMes(int mes, int ano); // para retornar a quantidade de dias do mes
        int bissexto(int ano); // para retornar se o ano eh bissexto
};
