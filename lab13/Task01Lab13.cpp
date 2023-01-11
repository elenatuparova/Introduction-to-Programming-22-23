#include <iostream>
#include <cmath>
typedef int (*next)(int);
typedef double (*typeOfFunc)(double);

int multiplyBy2(int n){
    return n * 2;
}
int incrementBy1(int n){
    return n + 1;
}
double actFunc(int n, char action, typeOfFunc type, next nextI){
    double sum = 0;
    for(int i  = 1; i <= n; i = nextI(i)){ //found the problem with chatGPT
    //I wrote nextI(i) and I don't increment anything, so endless loop
        if(action == '+'){
            sum += type(i);
        }
        if(action == '.'){
            sum *= type(i);
        }
    }
    return sum;
}
int main()
{
    std::cout << actFunc(16, '+', sqrt, incrementBy1) << std::endl;
    std::cout << actFunc(16, '+', sin, incrementBy1) << std::endl;
    

    return 0;
}
