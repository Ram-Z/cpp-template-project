#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include <QApplication>

#include <algorithm>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int result = Catch::Session().run(argc, argv);

    return result > 0xff ? 0xff : result;
}
