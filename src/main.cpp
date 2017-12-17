#include "diagram/Structogram.hpp"
#include "ui/Window.hpp"

#include <iostream>
#include <memory>

#include <QApplication>


using namespace samb;

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Window window;
    window.show(); 

    Structogram st("Example");

    return app.exec();
}




