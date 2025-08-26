#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int size;
    long long sum, tmpSum;
    
    cin >> size >> sum;
    cin.ignore();
    
    int pos1 = 0, pos2 = size - 1;
    
    vector<pair<long long, int>> values(size);

    for (int i = 0; i < size; ++i) {
        cin >> values[i].first;
        values[i].second = i + 1;
    }
    
    sort(values.begin(), values.end());
    
    while (pos1 < pos2) {
        tmpSum = values[pos1].first + values[pos2].first;
        
        if (tmpSum == sum) {
            cout << values[pos1].second << " " << values[pos2].second << endl;
            return 0;
        } else if (tmpSum > sum) {
            --pos2;
        } else {
            ++pos1;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
}
