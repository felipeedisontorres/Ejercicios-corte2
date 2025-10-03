#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    long reversed = 0, original = x;
    while(x != 0){
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return reversed == original;
}

int main(){
    int numero = 121;
    cout << (isPalindrome(numero) ? "Es palindromo" : "No es palindromo") << endl;
    return 0;
}
