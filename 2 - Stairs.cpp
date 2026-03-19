#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    
    if (n == 0) {
        return 0;
    }
    
    int a = 1, b =1;
    
    for (int i = 2; i <= n; i++) {
        b = a + b;
        a = b - a;
    }
    
    cout << "Number of distinct ways: " << b;
    
    return 0;
}