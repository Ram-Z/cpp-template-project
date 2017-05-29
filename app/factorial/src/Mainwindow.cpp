#include "Mainwindow.hpp"

#include <factorial/factorial.hpp>

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
{
    auto input      = new QLineEdit;
    auto calcButton = new QPushButton(tr("&Calculate"));
    auto label      = new QLabel;

    connect(calcButton, &QPushButton::clicked, [=]() {
        const auto n = input->text().toUInt();
        const auto f = factorial(n);
        label->setText(QString::number(f));
    });

    auto hlayout = new QHBoxLayout;
    hlayout->addWidget(input);
    hlayout->addWidget(calcButton);

    auto layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addLayout(hlayout);

    this->setLayout(layout);
}
