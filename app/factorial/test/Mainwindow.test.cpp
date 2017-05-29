#include <catch.hpp>
#include <QTest>

#include "Mainwindow.hpp"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <iostream>

namespace Catch {
template<>
struct StringMaker<QString>
{
    static std::string convert(QString const &a)
    {
        return ("\"" + a + "\"").toStdString();
    }
};
} // namespace Catch

SCENARIO("Input is read, calculated and displayed")
{
    GIVEN("a Mainwindow")
    {
        Mainwindow m;
        auto *input  = m.findChild<QLineEdit *>();
        auto *button = m.findChild<QPushButton *>();
        auto *label  = m.findChild<QLabel *>();
        REQUIRE(input != nullptr);
        REQUIRE(button != nullptr);
        REQUIRE(label != nullptr);

        WHEN("the input is set")
        {
            QTest::keyClicks(input, "2");
            AND_WHEN("the 'calculate' button is pressed")
            {
                QTest::mouseClick(button, Qt::LeftButton);
                THEN("the label show the results")
                {
                    REQUIRE(label->text() == "2");
                }
            }
        }
    }
}
