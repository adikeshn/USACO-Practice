#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N, K, max, min; fin >> N >> K;
    vector<int> bales(N);
    for (int x = 0; x<N; x++){
        fin >> bales[x];
    }
    max = *max_element(bales.begin(), bales.end());
    min = *min_element(bales.begin(), bales.end());
    int answer = (max - min) / (K*2);
    answer++;
    sort(bales.begin(), bales.end());
    for (int x = answer-1; x >= 0; x--){
        int currentDistance = 0, currentCount = 0;
        for (int y = 0; y<N; y++){
            if (bales[y] > currentDistance){
                currentCount++;
                currentDistance = (x*2) + (bales[y]);
            }
            if (currentCount > K){
                currentCount = -1;
                break;
            }
        }
        if (currentCount != -1 && x < answer){
            answer = x;
        }
    }
    fout << answer << endl;
}