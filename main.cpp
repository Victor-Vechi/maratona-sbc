#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qtdOperacoes = 0;

    cin >> qtdOperacoes;

    vector<long double> Cn(qtdOperacoes);
    vector<long double> Vn(qtdOperacoes);

    long long c = 0;
    long long v = 0;

    for (int i = 0; i < qtdOperacoes; i++) {
        long long compra = 0;
        long long venda = 0;

        cin >> compra >> venda;

        c += compra;
        v += venda;

        Cn[i] = c;
        Vn[i] = v;

    }

    int qtdConsultas = 0;
    cin >> qtdConsultas;

    vector<int> consultas(qtdConsultas);

    for (int i = 0; i < qtdConsultas; i++) {
        cin >> consultas[i];
    }

    for (int i = 0; i < qtdConsultas; i++) {

        long double result = (Cn[consultas[i]-1] - Vn[consultas[i]-1]) / (Cn[consultas[i]-1] + Vn[consultas[i]-1]);

        if (result > 0) cout << "COMPRA" << endl;
        else if (result < 0) cout << "VENDA" << endl;
        else cout << "NEUTRO" << endl;
    }

    return 0;
}