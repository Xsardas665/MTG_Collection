#include <gtkmm.h>
#include "mainwindow.h"

int main(int argc, char* argv[]) {
    Gtk::Main kit(argc, argv);

    // Create the main window
    MainWindow window;
    Gtk::Main::run(window); // Start the GTK main loop

    return 0;
}
