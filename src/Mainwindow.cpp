#include "Mainwindow.hpp"

#include <factorial.hpp>

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>

Mainwindow::Mainwindow(QWidget *parent)
    : QWidget(parent)
{
    auto input = new QLineEdit;
    auto calculateButton = new QPushButton(tr("&Calculate"));
    auto label = new QLabel;

    connect(calculateButton, &QPushButton::clicked, [=]() {
        const auto n = input->text().toUInt();
        auto f = factorial(n);
        label->setText(QString::number(f));
    });

    auto hlayout = new QHBoxLayout;
    hlayout->addWidget(input);
    hlayout->addWidget(calculateButton);

    auto layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addLayout(hlayout);

    this->setLayout(layout);
}
