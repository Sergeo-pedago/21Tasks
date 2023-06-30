#include "exampleController.h"

double ExampleController::add(double a)
{
    model->add(a);
    return model->getData();
}

double ExampleController::sub(double a)
{
    model->add(-a);
    return model->getData();
}

double ExampleController::mult(double a)
{
    model->mult(a);
    return model->getData();
}

double ExampleController::div(double a)
{
    model->mult(1.0/a);
    return model->getData();
}

void ExampleController::reset(){
    model->reset();
}