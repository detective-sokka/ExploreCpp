#include "Builder.h"
#include <optional>

OrderBuilder& OrderBuilder::buy()
{
    mOrder.mOrderSide = Side::BUY;
    return *this;
}

OrderBuilder& OrderBuilder::sell()
{
    mOrder.mOrderSide = Side::SELL;
    return *this;
}

OrderBuilder& OrderBuilder::quantity(int quantity)
{
    mOrder.mQuantity = quantity;
    return *this;
}

OrderBuilder& OrderBuilder::postOnly(bool postOnly)
{
    mOrder.mPostOnly = postOnly;
    return *this;
}

std::optional<Order> OrderBuilder::build()
{
    if (!mOrder.mOrderSide)
    {
        return std::nullopt;
    }
    else if (mOrder.mPostOnly && mOrder.mOrderSide == Side::BUY)
    {
        return std::nullopt;
    }

    if (mOrder.mQuantity <= 0)
    {
        return std::nullopt;
    }

    return mOrder;
}

