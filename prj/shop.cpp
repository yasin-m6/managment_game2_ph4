#include "shop.h"
#include<iostream>
using namespace std;

void Shop::reset_shop()
{
    cerr << "hello" << endl;
    tools_name.at(0) = "bil_1";
    tools_name.at(1) = "bil_2";
    tools_name.at(2) = "shen_kesh_1";
    tools_name.at(3) = "shen_kesh_2";
    tools_name.at(4) = "sam_pash_1";
    tools_name.at(5) = "sam_pash_2";
    tools_name.at(6) = "loole_1";
    tools_name.at(7) = "loole_2";
    tools_name.at(8) = "das_1";
    tools_name.at(9) = "das_2";

    tools_price.at(0) = 10;
    tools_price.at(1) = 15;
    tools_price.at(2) = 8;
    tools_price.at(3) = 13;
    tools_price.at(4) = 6;
    tools_price.at(5) = 10;
    tools_price.at(6) = 7;
    tools_price.at(7) = 11;
    tools_price.at(8) = 8;
    tools_price.at(9) = 11;

    seeds_name.at(0) = "goje";
    seeds_name.at(1) = "kahoo";
    seeds_name.at(2) = "kalam";
    seeds_name.at(3) = "havij";
    seeds_name.at(4) = "gandom";

    seeds_price.at(0) = 2;
    seeds_price.at(1) = 3;
    seeds_price.at(2) = 4;
    seeds_price.at(3) = 5;
    seeds_price.at(4) = 6;

    vegs_price.at(0) = 5;
    vegs_price.at(1) = 5;
    vegs_price.at(2) = 7;
    vegs_price.at(3) = 9;
    vegs_price.at(4) = 11;

}

int Shop::get_seeds_price(string name)
{
    int address = find_seeds(name);

    if(address >= 0 && address < seeds_name.size())
    {
        return seeds_price[address];
    }
    return -1;
}

int Shop::get_vegs_price(string name)
{
    int address = find_seeds(name);

    if(address >= 0 && address < seeds_name.size())
    {
        return vegs_price[address];
    }
    return -1;
}

int Shop::get_tools_price(string name)
{
    for(size_t i = 0 ; i < tools_name.size() ; i++)
    {
        if(tools_name[i] == name)
        {
            return tools_price[i];
        }
    }
    return -1;
}

int Shop::find_seeds(string name)
{
    for(size_t i = 0 ; i < seeds_name.size() ; i++)
    {
        if(seeds_name[i] == name)
        {
            return i;
        }
    }
}
