#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tamanhoArray;
    long long soma, somaTmp;
    
    cin >> tamanhoArray >> soma;
    
    int pos1 = 0, pos2 = tamanhoArray - 1;
    
    vector<pair<long long, int>> valores(tamanhoArray);

    for (int i = 0; i < tamanhoArray; ++i) {
        cin >> valores[i].first; // armazena o valor na primeira parte do pair
        valores[i].second = i + 1; // armazena a posição original do número na segunda parte do pair
    }
    
    sort(valores.begin(), valores.end()); // ordena os valores em ordem crescente
    
    while (pos1 < pos2) { // pos1 comeca no primeiro elemento, pos2 comeca no ultimo elemento
        somaTmp = valores[pos1].first + valores[pos2].first;
        
        if (somaTmp == soma) { // valores somados dao resultado desejado 
            cout << valores[pos1].second << " " << valores[pos2].second << endl;
            return 0; // imprime as posicoes e encerra o programa
        } else if (somaTmp > soma) {
            --pos2; // soma temporaria maior q valor desejado -> soma com o proximo valor menor
        } else {
            ++pos1; // soma temporaria menor q valor desejado -> soma com o proximo valor maior
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}
