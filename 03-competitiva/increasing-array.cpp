#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long movimientos = 0;
    long long anterior;

    cin >> anterior;

    for (int i = 1; i < n; i++)
    {
        long long actual;
        cin >> actual;

        if (actual < anterior)
        {
            movimientos += (anterior - actual);
        }
        else
        {
            anterior = actual;
        }
    }

    cout << movimientos << endl;

    return 0;
}
