#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PrefixTree.h"
#include "SlowniikT9.h"
#include <QDir>
#include <iostream>
#include <fstream>
#include "vector"

QString num_combination = "";
SlownikT9 slownik("../T9_dictionary/words.txt");


std::vector<std::string>current_words;
int current_id = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // all push buttons
    QPushButton *buttonsToLetters[10];
    QPushButton *otherButtons[2];
    otherButtons[0] = MainWindow::findChild<QPushButton *>("button_star");
    otherButtons[1] = MainWindow::findChild<QPushButton *>("button_hash");
    for(int i = 0; i < 2; i++){
        connect(otherButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    for(int i=1; i<9; ++i){
        QString butName = "button_" + QString::number(i+1);
        buttonsToLetters[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(buttonsToLetters[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString buttonval = button->text();
    QString buttonname = button->objectName();

    if(buttonname == "button_star"){
        if(!current_words.empty() && current_id<(int)current_words.size()-1){
            ui->Display->setText(QString::fromStdString(current_words[current_id]));
            current_id++;
        }else{
            current_id = 0;
        }
    }else if(buttonname == "button_hash"){
        int nums[num_combination.length()];
        for(int i = 0; i<num_combination.length(); i++) {
            nums[i] = num_combination[i].unicode() - '0';
        }
        current_words = get_words(nums, num_combination.length(), slownik);
        if(!current_words.empty()){
            std::sort(current_words.begin(), current_words.end(), []
                (const std::string& first, const std::string& second){
                    return first.size() < second.size();
                });
        }

        current_id = 0;
        if(!current_words.empty()){
            ui->Display->setText(QString::fromStdString(current_words[current_id]));
            current_id++;
            num_combination = "";
        }else {
           ui->Display->setText("...");
           num_combination = "";
        }
    }else{
        ui->Display->setText("");
        num_combination += buttonval[0];
    }
}
