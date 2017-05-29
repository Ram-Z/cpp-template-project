#pragma once

#include <cstdint>

uint32_t factorial(uint32_t n)
{
    uint32_t f = 1;
    for (uint32_t i = 1; i <= n; ++i)
        f *= i;
    return f;
}
