// This file controls display to the terminal

#include <iostream>
#include <string>
#include "own_header.h"

using namespace std;

Agent hello_info()
{   

    Agent agent;

    string user_enable_large_num;
    string user_enable_advanced_op;

    cout << "How many question you want ? " << endl;
    cin >> agent.num_of_exam;

    cout << "Do you wanna large number operands ? yes or no " << endl;
    cin >> user_enable_large_num;
    if (user_enable_large_num == "yes")
    {
        agent.enable_large_num = true;
    }

    string yes = "yes";
    cout << "Do you wanna advanced opearators ? yes or no " << endl;
    cin >> user_enable_advanced_op;
    if (user_enable_advanced_op == yes)
    {
        agent.enable_advanced_op = true;
    }  

    cout << "Number of examples: " << agent.num_of_exam <<
        " Enable large number: " << agent.enable_large_num <<
        " Enable advanced operators: " << agent.enable_advanced_op << endl;

    return agent;
}