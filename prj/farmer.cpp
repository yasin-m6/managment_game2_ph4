#include "farmer.h"
#include<iostream>
#include<stdexcept>
using namespace std;

Farmer::Farmer(int money)
{
    coin = money;
}

void Farmer::add_sub_money(int price)
{
    cerr << "price : " << price << endl;
    if(check_enough_money(price) == true)
    {
        coin += price;
    }
    else
    {
        throw invalid_argument("money is not enough");
    }
    cerr << coin << endl;
}

bool Farmer::check_enough_money(int price)
{
    if(coin + price >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Farmer::plant(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return ;
    }

    if(address > -1)
    {
        if(seed_number[address] > 1)
        {
            seed_number[address]--;
        }
        else
        {
            seed.erase(seed.begin() + address);
            seed_number.erase(seed_number.begin() + address);
        }
    }

    if(my_bil.at(0).get_use_time() == 1)
    {
        int address = get_tools_address("bil");
        my_bil.pop_back();
        if(address != -1)
        {
            tools_name.erase(tools_name.begin() + address);
            tools_type.erase(tools_type.begin() + address);
        }
    }
    else
    {

    }

    if(my_sam_pash.at(0).get_use_time() == 1)
    {
        int address = get_tools_address("sam_pash");
        my_sam_pash.pop_back();
        if(address != -1)
        {
            tools_name.erase(tools_name.begin() + address);
            tools_type.erase(tools_type.begin() + address);
        }
    }
    else
    {

    }
}

void Farmer::buy_seed(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return ;
    }


    if(address > -1)
    {
        seed_number[address]++;
    }
    else
    {
        seed.push_back(type);
        seed_number.push_back(1);
    }
}

void Farmer::buy_tools(string name , int t_type)
{
    int find = -1;
    for(size_t i = 0 ; i < tools_name.size() ; i++)
    {
        if(tools_name[i] == name)
        {
            find = i;
        }
    }

    if(find != -1)
    {
        tools_type[find] = t_type;

        if(name == "bil")
        {
            my_bil.at(0).set_type(t_type);
        }
        else if(name == "das")
        {
            my_das.at(0).set_type(t_type);
        }
        else if(name == "sam_pash")
        {
            my_sam_pash.at(0).set_type(t_type);
        }
        else if(name == "shen_kesh")
        {
            my_shen_kesh.at(0).set_type(t_type);
        }
        else
        {
            my_loole.at(0).set_type(t_type);
        }
    }
    else
    {
        tools_name.push_back(name);
        tools_type.push_back(t_type);

        if(name == "bil")
        {
            my_bil.push_back(Bil(t_type));
        }
        else if(name == "das")
        {
            my_das.push_back(Das(t_type));
        }
        else if(name == "sam_pash")
        {
            my_sam_pash.push_back(Sam_pash(t_type));
        }
        else if(name == "shen_kesh")
        {
            my_shen_kesh.push_back(Shen_kesh(t_type));
        }
        else
        {
            my_loole.push_back(Loole(t_type));
        }
    }
}

bool Farmer::check_avalable_tools(string name)
{

    if(get_tools_address(name) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Farmer::get_seed_number(string type)
{
    int address;

    try
    {
        address = get_seed_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return 0;
    }



    if(address > -1)
    {
        return seed_number[address];
    }
    else
    {
        return 0;
    }
}

int Farmer::get_product_number(string type)
{
    int address;

    try
    {
        address = get_product_address(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
        return 0;
    }



    if(address > -1)
    {
        return product_number[address];
    }
    else
    {
        return 0;
    }
}

string Farmer::get_tools_type(string name)
{
    if(name == "bil")
    {
        return my_bil.at(0).get_type();
    }
    else if(name == "das")
    {
        return my_das.at(0).get_type();
    }
    else if(name == "shen_kesh")
    {
        return my_shen_kesh.at(0).get_type();
    }
    else if(name == "sam_pash")
    {
        return my_sam_pash.at(0).get_type();
    }
    else
    {
        return my_loole.at(0).get_type();
    }
}

void Farmer::print()
{
    cerr << "tools : " << endl;
    for(size_t i = 0 ; i < tools_name.size() ; i++)
    {
        cerr << tools_name[i] << " " << tools_type[i] << endl;
    }

    cerr << "seeds : " << endl;
    for(size_t i = 0 ; i < seed.size() ; i++)
    {
        cerr << seed[i] << " " << seed_number[i] << endl;
    }

    cerr << "coin : " << coin << endl;
}

int Farmer::get_seed_address(string type)
{
    if(type != "goje" && type != "kahoo" && type != "kalam" && type != "havij" && type != "gandom")
    {
        throw invalid_argument("seed type is wrong!!!!");
    }

    for(size_t i = 0 ; i < seed.size() ; i++)
    {
        if(seed[i] == type)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int Farmer::get_product_address(string type)
{
    if(type != "goje" && type != "kahoo" && type != "kalam" && type != "havij" && type != "gandom")
    {
        throw invalid_argument("product type is wrong!!!!");
    }

    for(size_t i = 0 ; i < product.size() ; i++)
    {
        if(product[i] == type)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

int Farmer::get_tools_address(string name)
{
    if(name != "bil" && name != "das" && name != "shen_kesh" && name != "sam_pash" && name != "loole")
    {
        throw invalid_argument("tools name is wrong!!!!");
    }

    for(size_t i = 0 ; i < tools_name.size() ; i++)
    {
        if(tools_name[i] == name)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
