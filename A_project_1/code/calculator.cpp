// Main Function

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "own_header.h"

using namespace std;

int return_mod_num(const bool& enable_large_num)
{
    if (enable_large_num)
    {
        return 100;
    }
    else
    {
        return 10;
    }
}

int random_generate_num(const bool& enable_large_num)
{
    int mod_num = return_mod_num(enable_large_num);
    
    int num = rand() % mod_num + 1;

    return num;
}

int random_generate_op(const bool& enable_advanced_op)
{
    int op_sign;

    if (enable_advanced_op)
    {
        op_sign = rand() % 4 + 1;
    }
    else
    {
        op_sign = rand() % 2 + 1;
    }

    return op_sign;
}

int generate_question(const bool& enable_large_num, const bool& enable_advanced_op, string &p)
{
    int num1 = random_generate_num(enable_large_num);
    int num2 = random_generate_num(enable_large_num);
    
    int op_sign = random_generate_op(enable_advanced_op);

    double res;
    string question;
    if (op_sign == 1)
    {   
        question = to_string(num1) + " + " + to_string(num2);
        cout << question << endl;
        res = num1 + num2;
    }
    else if (op_sign == 2)
    {   
        question = to_string(num1) + " - " + to_string(num2);
        cout << question << endl;
        res = num1 - num2;
    }
    else if (op_sign == 3)
    {   
        question = to_string(num1) + " * " + to_string(num2);
        cout << question << endl;
        res = num1 * num2;
    }
    else if (op_sign == 4)
    {   
        question = to_string(num1) + " / " + to_string(num2);
        cout << question << endl;
        res = num1 / num2;
    }
    else
    {
        return 1;
    }

    cout << "Type your answer ..." << endl;
    
    // *p = question;
    p = question;

    return res;

}

int main()
{   
    srand((unsigned)time(NULL));

    // agent
    Agent agent = hello_info();

    // save error questions
    string err_ques = "";

    for (int i = 0; i < agent.num_of_exam; i++)
    {   
        cout << "Start question " << i << ":\n" << endl;
        
        // p point to current question
        // I don't know how to allocate bigger size for the place pointed by *p,
        // if I didn't make *p point to a very long temp, in 88th line: *p = question,
        // would cause bus error, I suspect it is the size of question is larger than the
        // place pointed by *p.
        // string temp = "This is a test This is a test This is a test This is a test This is a test This is a test This is a test";
        // string *p = &temp;

        // fix
        string temp = "";
        string &p = temp;

        // random generate a question
        double res = generate_question(agent.enable_large_num, agent.enable_advanced_op, p);

        // get user input
        double user_guess;
        cin >> user_guess;

        if (res == user_guess)
        {
            agent.num_of_corr++;
        }
        else
        {
            // string question = *p;
            string question = p;
            err_ques += "The " + to_string(i) + "th: " + question + " = " + to_string(res) + "\n"
                + "\tYour Answer: " + to_string(user_guess) + "\n";
        }
        
        cout << "Correct: " << res << " Guess: " << user_guess << endl;
        cout << "Current Correct: " << agent.num_of_corr << endl;
    }

    double correct_rate = agent.num_of_corr / agent.num_of_exam * 100;
    cout << "Wrong Answer Question:\n" << err_ques << endl;
    cout << "Correct Rate: " << correct_rate << "%" << endl;

    return 0;
}