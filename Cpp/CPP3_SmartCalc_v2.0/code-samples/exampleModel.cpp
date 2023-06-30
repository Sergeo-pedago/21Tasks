#include "exampleModel.h"

void ExampleModel::add(double a) 
{
    data += a;
} 

void ExampleModel::mult(double a) 
{
    data *= a;
}

void ExampleModel::reset()
{
    data = 0;
}

double ExampleModel::getData()
{
    return data;
}