#ifndef EXAMPLECONTROLLER_H
#define EXAMPLECONTROLLER_H

#include "exampleModel.h"

class ExampleController 
{
    private:
        ExampleModel *model;
    public:
        ExampleController(ExampleModel *m):model(m) {};
        double add(double a);
        double sub(double a);
        double mult(double a);
        double div(double a);
        void reset();
};

#endif