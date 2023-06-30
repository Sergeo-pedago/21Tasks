#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

class ExampleModel
{
    private:
        double data;
    public:
        ExampleModel():data(0){};
        void add(double a);
        void mult(double a);
        void reset();
        double getData();
};

#endif