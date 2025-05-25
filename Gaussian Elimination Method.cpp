//Dinar Perseüs
//Gaussian Elimination Method
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;
    double a[n][n], b[n], x[n];
    cout << "Enter the coefficients of the equations (row-wise):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    // Forward elimination
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i][i] == 0) {
                cout << "Matrix is singular or nearly singular." << endl;
                return 1;
            }
            double factor = a[j][i] / a[i][i];
            for(int k = i; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }
    // Back substitution
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--) {
        x[i] = b[i];
        for(int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    cout << "The solution is:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

}
