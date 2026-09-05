#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long qtdAmigos = 0;
    long long qtdConvidados = 0;

    cin >> qtdAmigos >> qtdConvidados;

    vector<long long> amigos(qtdAmigos);
    vector<long long> convidados(qtdAmigos);

    for (long long i = 0; i < qtdConvidados; ++i) {
        long long amigo = 0;
        long long convidado = 0;
        cin >> amigo >> convidado;

        amigos[amigo-1] = amigo;
        convidados[amigo-1] = convidado;
    }

    vector<long long> chegadaAmigo(qtdAmigos);
    vector<long long> tempoAmigos(qtdAmigos);


    for (long long amigo : amigos) {
        if (amigo != 0) {
            string resposta;
            long long i = amigo - 1;
            long long chegada = 0;
            long long tempo = 0;

            cin >> resposta;

            if (resposta == "D") {
                chegadaAmigo[i] = 0;
                tempoAmigos[i] = 0;
                amigos[i] = 0;
                convidados[i] = 0;
            } else if (resposta == "A") {
                cin >> chegadaAmigo[i] >> tempoAmigos[i];
            } else if (resposta == "T") {
                long long indiceAmigo = 0;
                cin >> indiceAmigo;
                chegadaAmigo[i] = chegadaAmigo[indiceAmigo-1];
                tempoAmigos[i] = tempoAmigos[indiceAmigo-1];
            } else {
                chegadaAmigo[i] = 0;
                tempoAmigos[i] = 0;
            }
        }
    }

    vector<long long> intervaloAmigos(qtdAmigos);

    for (int i = 0; i < qtdAmigos; ++i) intervaloAmigos[i] = chegadaAmigo[i] + tempoAmigos[i];

    erase_if(chegadaAmigo, [](long long x) { return x == 0; });
    erase_if(tempoAmigos, [](long long x) { return x == 0; });
    erase_if(convidados, [](long long x) { return x == 0; });
    erase_if(amigos, [](long long x) { return x == 0; });
    erase_if(intervaloAmigos, [](long long x) { return x == 0; });
    erase_if(intervaloAmigos, [](long long x) { return x == 0; });

    cout << "aaaa" << endl;
    return 0;
}