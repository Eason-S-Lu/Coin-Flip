#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <random>
#include<cmath>

using namespace std;

//0 is head 1 is tail

int prob (){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution_1(0, 1);
    int prob = distribution_1(gen);
    //cout << "Debug" << prob << endl;
    return (prob);
}

int coinflip (){
    int money;
    int tailscount;
    money = 0;
    tailscount = 0;
    while (true){
        if (prob() == 0){
            money = pow(2,tailscount);
            break;
        }
        else{
            tailscount++;
        }
    }
    return money;
}
int main(){
    cout << "Number of tries" << endl;
    int tries;
    cin >> tries;
    int totalmoney = 0;
    for (int i = 1; i <= tries; i++){
        totalmoney += coinflip();
    }
    cout <<"total"<< totalmoney << endl;
    double ev;
    ev = totalmoney / tries;
    cout <<"ev"<< ev << endl;
    return 0;
} 