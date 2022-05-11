#pragma once

#include <string>

struct Agent {

    // number of the examples
    double num_of_exam = 0;

    // number of correct answers by user
    double num_of_corr = 0;

    // whether enable large number operands
    bool enable_large_num = false;

    // whether enable mul and div
    bool enable_advanced_op = false;

    // // trick way to save wrong questions
    // string error_message = "";

};

Agent hello_info();