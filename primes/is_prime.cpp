#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int is_prime(int x){
    if (x <= 1){
        return false;
    }
    if (x%2==0 || x%3==0 || x%5==0){ // if x is simple
        if(x==2 || x==3 || x==5){return true;}
        return false;
    }

    // only prime if x can be written as x = 6*k +- 1
    if ((x+1) % 6 == 0 || (x-1) % 6 == 0){
        int end = ceil(sqrt(x));
        int i = 1;
        // only check if x is divisible by potential primes
        int higher =  6*i + 1;
        int lower = 6*i - 1;
        // cout << "end: " << end << endl;
        while (higher <= end){
            // cout << "lower, higher:  " << lower << ", " << higher << endl; 
            // cout << "lower \% x, higher \% x: " << x % higher << ", " << x % lower << endl; 
            if(x % lower == 0 || x % higher == 0){
                return false;
            }
            // cout << "i = " << i << endl;
            i++;
            higher =  6*i + 1;
            lower = 6*i - 1;
        }
        return true;
        
    } else{
         return false;
    }
}

int main(){
    vector<int> primes;
    int n = 10000000;
    // primes.resize(n);
    for (int i = 0; i<n; i++){
        if (is_prime(i)){
            primes.push_back(i);
        }
    } 
    // sum of all primes under n
    int s = 0;
    for ( int val : primes ){
        s += val;
    }
    cout << s << endl;

}

