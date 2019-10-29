#include <iostream>
#include <vector>
#include <math.h>       /* sqrt, ceil */

using namespace std;

struct Node{
    int value;
    bool prime;

    Node(int val){
        value = val;
        prime = false;      
    }
    Node(int val, bool is){
        value = val;
        prime = is;
    }
};


class sieve{
  private:
    vector<Node*> numbers;
    vector<int> primes;
    int size;

  public:
// constructor
    sieve(){
        size = 0;
    }
    sieve(int n){
        sieve(2, n);
    }
    sieve(int start, int n){
        size = 0;
        // numbers.resize(n-start);
        Node* new_node;
        for (int i = start; i <= n; i++){
            numbers.push_back(new_node);
        } 
    }
// modifiers
    void push_back(int val){
        Node* new_node = new Node(val);
        numbers.push_back(new_node);
    }
// methods
    void calculate(){

    }

    void print_numbers(){
        for (Node* current : numbers){
            cout << current->value << ":" << current->prime << ", ";
        }
    }


};

int main(){
    sieve data;
    data.push_back(10);
    data.print_numbers();
    return 0;
}