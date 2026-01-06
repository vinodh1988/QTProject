#ifndef OPERATIONS_H
#define OPERATIONS_H
#include<thread>
#include<functional>
#include<chrono>

auto add = [](int a, int b) {
    return a+b;
}; //on the spot function creation

int minus(int a, int b) {
    return a-b;
}

auto sub = minus; //without lambda

void tentimeCaller(std::function<void(void)> callback) {
    for(int i=0;i<10;i++){
        std::this_thread::sleep_for(std::chrono::seconds(2));
        callback();
    }
}
//callback is a parameter of type function
#endif // OPERATIONS_H
