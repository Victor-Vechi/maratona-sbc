#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct No {
    long long int indice;
    long long int convites;
    No* esquerda;
    No* direita;

};


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


    for (long long i = 0; i < qtdAmigos; ++i) {
        char resposta = ' ';
        long long chegada = 0;
        long long tempo = 0;

        cin >> resposta >> chegada >> tempo;

        if (resposta == 'A') {
            chegadaAmigo[i] = chegada;
            tempoAmigos[i] = tempo;
        } else if (resposta == 'D') {
            chegadaAmigo[i] = -1;
            tempoAmigos[i] = -1;
        } else {
            long long indiceAmigo = chegada;
            chegadaAmigo[i] = chegadaAmigo[indiceAmigo-1];
            tempoAmigos[i] = tempoAmigos[indiceAmigo-1];
        }
    }

    cout << "aaaa" << endl;
    return 0;
}