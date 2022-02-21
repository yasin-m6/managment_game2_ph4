#ifndef SHOP_H
#define SHOP_H

#include<array>
#include<string>

class Shop
{
public:

    void reset_shop();
    int get_seeds_price(std::string);
    int get_vegs_price(std::string);
    int get_tools_price(std::string);

private:
    std::array<std::string , 10> tools_name;
    std::array<std::string , 5> seeds_name;

    std::array<int , 10> tools_price;
    std::array<int , 5> seeds_price;

    std::array<int , 5> vegs_price;

    int find_seeds(std::string);
};

#endif // SHOP_H
