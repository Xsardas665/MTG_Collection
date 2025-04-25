#include <gtkmm.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.test");
    Gtk::Window window;
    window.set_title("Test GTKmm");
    window.set_default_size(300, 200);
    return app->run(window);
}
