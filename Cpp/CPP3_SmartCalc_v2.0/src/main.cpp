#include "consoleView.h"

int main() {
    ExampleModel model;
    ExampleController controller(&model);
    ConsoleView view(&controller);
    view.startEventLoop();
    return 1;
}