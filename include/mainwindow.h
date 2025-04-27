#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include "database.h"
#include "columns.h"

class MainWindow : public Gtk::Window {
private:
    Database database; // Database object for interacting with the database
    ModelColumns m_columns; // Use ModelColumns class here
    Gtk::Box m_box;    // Main container for the window
    Gtk::TreeView m_treeView; // TreeView for displaying cards
    Gtk::Button m_loadButton; // Button for loading cards from the database
    Gtk::Button m_addButton;  // Button for adding a new card to the database
    Gtk::Entry m_nameEntry, m_colorEntry, m_typeEntry, m_manaCostEntry, m_quantityEntry; // Form for entering card details
    Gtk::Label m_statusLabel;  // Label for showing status messages

    void on_load_button_click(); // Callback method for loading cards
    void on_add_button_click();  // Callback method for adding a new card

    void update_tree_view(); // Method to refresh the TreeView with card data

public:
    MainWindow(); // Constructor to initialize the main window
    virtual ~MainWindow(); // Destructor
};

#endif
