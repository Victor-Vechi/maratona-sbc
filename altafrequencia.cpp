#include <cmath>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Cn = 0;
    long long Vn = 0;



    int qtdOperacoes = 0;

    cin >> qtdOperacoes;

    int c[qtdOperacoes];
    int v[qtdOperacoes];

    for (int i = 0; i < qtdOperacoes; i++) {
        cin >> c[i] >> v[i];
    }

    int qtdConsultas = 0;
    int consultas[qtdConsultas];
    cin >> qtdConsultas;
    for (int i = 0; i < qtdConsultas; i++) {
        cin >> consultas[i];
    }

    for (int i = 0; i < qtdConsultas; i++) {
        for (int j = 0; j < consultas[i]; j++) {
            Cn += c[j];
            Vn += v[j];
        }

        double result = (Cn - Vn) / (Cn + Vn);

        if (result > 0) {
            cout << "COMPRA" << endl;
        } else if (result < 0) {
            cout << "VENDA" << endl;
        } else {
            cout << "NEUTRO" << endl;
        }
    }


    return 0;
}