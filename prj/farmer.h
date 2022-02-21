#ifndef FARMER_H
#define FARMER_H

#include<vector>
#include<string>
#include"vegtebale.h"
#include"tools.h"


class Farmer
{
public:
    Farmer(int = 100);
    void add_sub_money(int);
    bool check_enough_money(int);

    void plow();//
    void plant(std::string);
    void crop();//

    void sell_product(std::string);//
    void buy_seed(std::string);
    void buy_tools(std::string , int);

    bool check_avalable_seeds(std::string);
    bool check_avalable_products(std::string);
    bool check_avalable_tools(std::string);


    int get_seed_number(std::string);
    int get_product_number(std::string);

    std::string get_tools_type(std::string);

    void print();
private:
    std::string farmers_name;
    int coin;

    std::vector<std::string> product;
    std::vector<int> product_number;

    std::vector<std::string> seed;
    std::vector<int> seed_number;

    std::vector<std::string> tools_name;
    std::vector<int> tools_type;

    std::vector<Bil> my_bil;
    std::vector<Das> my_das;
    std::vector<Shen_kesh> my_shen_kesh;
    std::vector<Sam_pash> my_sam_pash;
    std::vector<Loole> my_loole;

    int get_seed_address(std::string);
    int get_product_address(std::string);
    int get_tools_address(std::string);
};

#endif // FARMER_H
