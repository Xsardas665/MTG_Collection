#include "../include/mainwindow.h"
#include <iostream>

MainWindow::MainWindow()
    : m_box(Gtk::ORIENTATION_VERTICAL), m_loadButton("Load Cards"), m_addButton("Add Card") {
    set_title("MTG Collection");
    set_default_size(800, 600);
    set_border_width(10);

    // Layout setup
    add(m_box);

    // TreeView to display cards
    m_treeView.set_size_request(600, 400);
    m_box.pack_start(m_treeView);

    // Form for adding a new card
    Gtk::Box* formBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5));
    m_box.pack_start(*formBox);

    formBox->pack_start(m_nameEntry);
    formBox->pack_start(m_colorEntry);
    formBox->pack_start(m_typeEntry);
    formBox->pack_start(m_manaCostEntry);
    formBox->pack_start(m_quantityEntry);

    m_nameEntry.set_placeholder_text("Name");
    // Buttons for actions
    Gtk::Box* buttonBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 5));
    m_box.pack_start(*buttonBox);

    buttonBox->pack_start(m_loadButton);
    buttonBox->pack_start(m_addButton);

    // Status label
    m_box.pack_start(m_statusLabel);

    // Connect signals to button click events
    m_loadButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_load_button_click));
    m_addButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_add_button_click));

    m_treeView.append_column("ID", m_columns.m_id);
    m_treeView.append_column("Name", m_columns.m_name);
    m_treeView.append_column("Color", m_columns.m_color);
    m_treeView.append_column("Type", m_columns.m_type);
    m_treeView.append_column("Mana Cost", m_columns.m_mana_cost);
    m_treeView.append_column("Quantity", m_columns.m_quantity);

    // Initial update of the TreeView
    update_tree_view();

    show_all_children();
}

MainWindow::~MainWindow() {}

void MainWindow::on_load_button_click() {
    // Load all cards from the database and update the TreeView
    update_tree_view();
}

void MainWindow::on_add_button_click() {
    // Get input data from the form
    std::string name = m_nameEntry.get_text();
    std::string color = m_colorEntry.get_text();
    std::string type = m_typeEntry.get_text();
    std::string manaCost = m_manaCostEntry.get_text();
    int quantity = std::stoi(m_quantityEntry.get_text());

    // Create a new Card object
    Card newCard(name, color, type, manaCost, quantity);

    // Add the card to the database
    if (database.addCard(newCard)) {
        m_statusLabel.set_text("Card added successfully.");
    } else {
        m_statusLabel.set_text("Failed to add card.");
    }

    // Clear the form inputs
    m_nameEntry.set_text("");
    m_colorEntry.set_text("");
    m_typeEntry.set_text("");
    m_manaCostEntry.set_text("");
    m_quantityEntry.set_text("");

    // Refresh the TreeView with the updated list of cards
    update_tree_view();
}

void MainWindow::update_tree_view() {
    // Get all cards from the database
    std::vector<Card> cards = database.getAllCards();

    // Create a model for the TreeView
    Glib::RefPtr<Gtk::ListStore> model = Gtk::ListStore::create(m_columns);
    m_treeView.set_model(model);

    // Add each card to the TreeView model
    for (const Card& card : cards) {
        std::cout << "Adding card: " << card.name << std::endl;
        Gtk::TreeModel::Row row = *(model->append());
        row[m_columns.m_id] = card.id;
        row[m_columns.m_name] = card.name;
        row[m_columns.m_color] = card.color;
        row[m_columns.m_type] = card.type;
        row[m_columns.m_mana_cost] = card.manaCost;
        row[m_columns.m_quantity] = card.quantity;
        std::cout << "Card added: " << row[m_columns.m_name] << std::endl;
    }
    m_treeView.queue_draw();

}
