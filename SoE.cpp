#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 0; i < n + 1; ++i)
        if (v[i] == true)
            for (int j = 2*i; j < n + 1; j += i)
                v[j] = false;


    for (int i = 0; i < n + 1; ++i)
        if (v[i] == true) cout << i << "  ";

    return 0;
}