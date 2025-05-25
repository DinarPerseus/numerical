//Dinar Perseüs
//Gaussian Elimination Method with Partial Pivoting
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
    // Forward elimination with partial pivoting
    for(int i = 0; i < n - 1; i++) {
        // Pivoting
        int maxRow = i;
        for(int k = i + 1; k < n; k++) {
            if(abs(a[k][i]) > abs(a[maxRow][i])) {
                maxRow = k;
            }
        }
        if(maxRow != i) {
            // Swap the rows
            for(int j = 0; j < n; j++) {
                swap(a[maxRow][j], a[i][j]);
            }
            swap(b[maxRow], b[i]);
        }
        
        // Elimination
        for(int j = i + 1; j < n; j++) {
            double factor = a[j][i] / a[i][i];
            for(int k = i; k < n; k++) {
                a[j][k] -= factor * a[i][k];
            }
            b[j] -= factor * b[i];
        }
    }
    // Back substitution
    for(int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for(int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    // Output the solution
    cout << "The solution is:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }


}
