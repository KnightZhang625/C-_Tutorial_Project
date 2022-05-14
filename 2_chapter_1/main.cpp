#include <iostream>
#include <cstdio>

void welcome_info() {
    // this is the standard IO from c.
    printf("Welcome to the calculator.\n");
}

namespace tools {
    float input_1() {
        float x;

        std::cout << "Enter 1st number: ";
        std::cin >> x;
        std::cout << std::endl;

        return x;
    }

    float input_2() {
        float y;

        std::cout << "Enter 2nd Number: ";
        std::cin >> y;
        std::cout << std::endl;

        return y;
    }

}

namespace calculator {
    float add(float x, float y){
        return x + y;
    }

    float subtract(float x, float y){
        return x - y;
    }
}

namespace res_output {
    void out_add(float res){
       printf("Add Result: %f \n", res);
    }

    void  out_sub(float res){
        printf("Subtract Result: %f \n", res);
    }
}

int main() {

    // welcome
    welcome_info();

    // get the user input
    float num1;
    float num2;

    num1 = tools::input_1();
    num2 = tools::input_2();

    // calculate
    float add_res;
    float sub_res;
    namespace cal = calculator;
    add_res = cal::add(num1, num2);
    sub_res = cal::subtract(num1, num2);

    // display the results
    using namespace res_output;
    out_add(add_res);
    out_sub(sub_res);

    int x;
    std::cout << "Press Enter to exist...";
    std::cin >> x;
    return 0;
}
