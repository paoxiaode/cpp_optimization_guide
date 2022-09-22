#include <iostream>
#include "src/function.hpp"
#include "src/random.hpp"
#include "../timer/timer.hpp"

int main(){
    std::string input = strRand(1000000);
    int counter = 100;
    stopwatch::Stopwatch timer;
    // timer.start();
    // for (int i = 0; i < counter ; i++){
    //     remove_ctrl(input);
    // }
    // printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/10);
    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_mutating(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);
    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_reserve(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);

    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_ref_args(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);

    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_ref_args_it(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);

    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_block(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);

    timer.start();
    for (int i = 0; i < counter ; i++){
        remove_ctrl_block_append(input);
    }
    printf("time elapse %ld \n", timer.elapsed<stopwatch::nanoseconds>()/counter);
 
 
}