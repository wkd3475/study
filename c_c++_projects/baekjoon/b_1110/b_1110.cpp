#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    while(1) {
        int a, b, temp = n;
        if(n < 10) {
            a = 0;
            b = temp;
        }
        else {
            a = temp / 10;
            b = temp%10;
        }
    }
}