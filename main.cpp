#include <iostream>

int isEmpty(int* top){

    return !top;

};

int main(){

    int* top = nullptr;

    std::cout<< isEmpty(top)<<std::endl;
    std::cout<< !isEmpty(top)<<std::endl;

};