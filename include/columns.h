#ifndef COLUMNS_H
#define COLUMNS_H

#include <gtkmm.h>

class ModelColumns : public Gtk::TreeModelColumnRecord {
public:
    ModelColumns() {
        add(m_id); 
        add(m_name); 
        add(m_color); 
        add(m_type); 
        add(m_mana_cost); 
        add(m_quantity);
    }

    Gtk::TreeModelColumn<int> m_id;
    Gtk::TreeModelColumn<Glib::ustring> m_name;
    Gtk::TreeModelColumn<Glib::ustring> m_color;
    Gtk::TreeModelColumn<Glib::ustring> m_type;
    Gtk::TreeModelColumn<Glib::ustring> m_mana_cost;
    Gtk::TreeModelColumn<int> m_quantity;
    Gtk::TreeModelColumn<Glib::RefPtr<Gtk::Button>> m_remove_button;

};

#endif // COLUMNS_H
