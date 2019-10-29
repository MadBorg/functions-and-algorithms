#include<iostream>
#include <string>
#include<time.h>
#include<vector>

using namespace std;

class MiddleSquared{
  private:
    int _state; // seed
    int random;
    vector<int> randoms;

    int next_number(int current){
        current = current^2;
        string digits = to_string(current).substr(2, 5); // // https://stackoverflow.com/questions/10084335/c-integer
        cout << "digits: " << digits << ", current: " << current << endl;
        return stoi(digits); // http://www.cplusplus.com/reference/string/stoi/
    }
  public:
   // constructors
    MiddleSquared(){
        _state = time(nullptr);
    }
    MiddleSquared(int seed){
        _state = seed;
    }

   // operators
    vector<int> operator()(int n){
        vector<int> randoms;
        randoms.resize(n+1);
        for (int i; i<=n; i++){
            _state = next_number(_state);
            randoms[i] = _state;
        }
        return randoms;
    }
    int operator()(){
        _state = next_number(_state);
        random = _state;
        return random;
    }
   // methods
    void print(){
        if (random){
            cout << random << endl;
        } else if (randoms.size()){
            cout << "[";
            for (int i = 0; i < randoms.size(); i++){
                cout << randoms[i] << ", ";
            }
            cout << randoms[-1] << "]" << endl;
        } // error
    }


};

int main(){
   // random
   MiddleSquared random;
   int tmp = random();
   // cout << "random: " << tmp;
   random.print();


   // randoms
   MiddleSquared randoms;
   vector<int> tmps = random(10);
   randoms.print();
   
}