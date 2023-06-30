#include "consoleView.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void ConsoleView::displayMenu()
{
    std::cout << "=========" << std::endl;
    std::cout << " M E N U " << std::endl;
    std::cout << "=========" << std::endl;
    std::cout << "1. Add a number" << std::endl;
    std::cout << "2. Subtract a number" << std::endl;
    std::cout << "3. Multiplicate a number" << std::endl;
    std::cout << "4. Divide a number" << std::endl;
    std::cout << "5. Reset a number" << std::endl;
    std::cout << "0. Quit" << std::endl << std::endl;
}

int ConsoleView::performChoice()
{
    int choice;
    std::cout << "Input a menu item digit: ";
    std::cin >> choice;
    return choice;
} 

double ConsoleView::performNumericInput()
{    
    double number;
    std::cout << "Input a decimal number: ";
    std::cin >> number;
    return number;
} 

void ConsoleView::startEventLoop()
{
    while (true) 
    {
        double result;
        displayMenu();
        switch ((Choice)performChoice())
        {
        case SUM:
            result = controller->add(performNumericInput());
            break;
        
        case SUB:
            result = controller->sub(performNumericInput());
            break;

        case MUL:
            result = controller->mult(performNumericInput());
            break;

        case DIV:
            result = controller->div(performNumericInput());
            break;

        case RES:
            controller->reset();
            result = 0.0;
            break;

        case EXIT:
            exit(1);

        default:
            std::cout << "Wrong menu item number!";
            continue;
        }

        std::cout << "Current result is: " << result << std::endl;
    }
}