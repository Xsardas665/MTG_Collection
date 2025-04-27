#include "mainwindow.h"
#include <fstream>
#include <iostream>

MainWindow::MainWindow() :
    mainBox(Gtk::ORIENTATION_VERTICAL), addButton("Dodaj"), saveButton("Zapisz") {

    set_title("MTG Katalog");
    set_default_size(600, 400);

    // Layout główny
    add(mainBox);

    // Pola formularza
    formBox.set_spacing(5);
    formBox.pack_start(nameEntry);
    nameEntry.set_placeholder_text("Nazwa");

    formBox.pack_start(colorEntry);
    colorEntry.set_placeholder_text("Kolor");

    formBox.pack_start(typeEntry);
    typeEntry.set_placeholder_text("Typ");

    formBox.pack_start(manaEntry);
    manaEntry.set_placeholder_text("Koszt many");

    quantitySpin.set_range(0, 100);
    quantitySpin.set_increments(1, 5);
    formBox.pack_start(quantitySpin);

    formBox.pack_start(addButton);
    formBox.pack_start(saveButton);

    mainBox.pack_start(formBox, Gtk::PACK_SHRINK);

    // Tabela (TreeView)
    listStore = Gtk::ListStore::create(columns);
    treeView.set_model(listStore);
    treeView.append_column("Nazwa", columns.col_name);
    treeView.append_column("Kolor", columns.col_color);
    treeView.append_column("Typ", columns.col_type);
    treeView.append_column("Mana", columns.col_manaCost);
    treeView.append_column("Ilość", columns.col_quantity);

    mainBox.pack_start(treeView);

    // Obsługa przycisków
    addButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_add_button_clicked));
    saveButton.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_save_button_clicked));

    show_all_children();
}

MainWindow::~MainWindow() {}

void MainWindow::on_add_button_clicked() {
    std::string name = nameEntry.get_text();
    std::string color = colorEntry.get_text();
    std::string type = typeEntry.get_text();
    std::string mana = manaEntry.get_text();
    int quantity = quantitySpin.get_value_as_int();

    Card card(name, color, type, mana, quantity);
    cards.push_back(card);

    auto row = *(listStore->append());
    row[columns.col_name] = name;
    row[columns.col_color] = color;
    row[columns.col_type] = type;
    row[columns.col_manaCost] = mana;
    row[columns.col_quantity] = quantity;

    // Czyść formularz
    nameEntry.set_text("");
    colorEntry.set_text("");
    typeEntry.set_text("");
    manaEntry.set_text("");
    quantitySpin.set_value(0);
}

void MainWindow::on_save_button_clicked() {
    std::ofstream file("cards.csv");
    if (!file) {
        std::cerr << "Błąd zapisu pliku." << std::endl;
        return;
    }

    for (const auto& card : cards) {
        file << card.name << "," << card.color << "," << card.type << ","
             << card.manaCost << "," << card.quantity << "\n";
    }

    file.close();
}
