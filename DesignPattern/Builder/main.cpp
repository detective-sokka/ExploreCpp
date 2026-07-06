#include "Builder.h"
#include <iostream>

int main()
{
    auto order = OrderBuilder("AAPL")
        .buy()
        .quantity(100)
        .build();

    if (order)
        std::cout << "Order built: " << order->mSecurity << " qty=" << order->mQuantity << '\n';
    else
        std::cout << "Order invalid\n";

    // post-only buy should fail
    auto bad = OrderBuilder("TSLA")
        .buy()
        .quantity(50)
        .postOnly(true)
        .build();

    std::cout << (bad ? "Order built\n" : "Post-only buy correctly rejected\n");

    return 0;
}
