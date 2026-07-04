/*
Background 

Your trading system sends orders to multiple exchanges. 

Each exchange requires a slightly different order message format, 
but internally your trading system constructs orders using the same. 

logical fields:
- Symbol
- Side (Buy/Sell)
- Quantity
- Price
- Order type
- Optional fields such as post-only, reduce-only, and iceberg quality.

Order(std::string, bool isBuy, int, double, OrderType::, isPostOnly=false, amHandsome = true);


Constructing orders directly using constructors has led to several problems : 
    - constructors with too many parameters
    - optional fields becoming confusing
    - incorrect parameter ordering bugs

Example of the current problematic code:

Order order("AAPL",
            true, 
            100,
            186.25,
            OrderType::Limit,
            false, //What is this?
            true);

Developers frequently mix up parameters of fields. 

What's the solution here: Builder

Requirements 
Design and implement an OrderBuilder that allows traders to construct orders in a readable way. For 
example:

std::expected<T, E>
std::optional<Order>
Order order = OrderBuilder("AAPL")
             .buy()
             .quantity(100)
             .postOnly(true)
             .build();

Mandatory parameters goes in constructor , optional parameters are in the follow up function calls.
Since postOnly and buy are contradictory, build is expected to check and throw exceptions or 
std::expected or std::optional.
*/

class Order
{
public:

private:

};

class OrderBuilder
{

};