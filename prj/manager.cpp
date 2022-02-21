#include "manager.h"
#include<iostream>
#include<ctime>
#include<stdexcept>
using namespace std;

Manager::Manager(QObject *parent) : QObject(parent)
{
    my_farm.set_type(0);
    theShop.reset_shop();
}

bool Manager::buyTools(QString name, int type)
{
    string t_name = (name.toStdString()).append(static_cast<string>("_"));
    t_name = t_name.append(to_string(type));

    int price = theShop.get_tools_price(t_name);



    try
    {
        me.add_sub_money(-1*price);
    }
    catch(invalid_argument &w)
    {
        cerr << w.what() << endl;
        return false;
    }
    me.buy_tools(name.toStdString() , type);
    return true;
}


bool Manager::buySeeds(QString s_name)
{
    int price = theShop.get_seeds_price(s_name.toStdString());

    try
    {
        me.add_sub_money(-1*price);
    }
    catch(invalid_argument &w)
    {
        cerr << w.what() << endl;
        return false;
    }
    me.buy_seed(s_name.toStdString());
}

void Manager::sellProducts(QString )
{

}

int Manager::get_seeds_price(QString name)
{
    return theShop.get_seeds_price(name.toStdString());
}

int Manager::get_tools_price(QString name)
{
    return theShop.get_tools_price(name.toStdString());
}

int Manager::getWaterTime()
{
    return my_farm.get_water_time();
}

int Manager::getCropTime()
{
    return my_farm.get_crop_time();
}

int Manager::get_crop_spoiled()
{
    return my_farm.get_spoiled_crop_time();
}
int Manager::get_water_spoiled()
{
    return my_farm.get_spoiled_water_time();
}

bool Manager::checkWaterTime()
{
    return my_farm.check_water_time();
}

bool Manager::checkCropTime()
{
    return my_farm.check_crop_time();
}

int Manager::water_timer()
{
    cerr << my_farm.get_water_timer() << endl;
    return my_farm.get_water_timer();
}

int Manager::crop_timer()
{
    return my_farm.get_crop_timer();
}

int Manager::spoiled_water_timer()
{
    return my_farm.get_spoiled_water_timer();
}

int Manager::spoiled_crop_timer()
{
    return my_farm.get_spoiled_crop_timer();
}

void Manager::plantSeed(int type)
{
    try
    {
       my_farm.set_type(type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::plowFarm()
{
    try
    {
       my_farm.set_type(6);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::cropProduct()
{
    try
    {
       my_farm.set_type(0);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::spoiled_product()
{
    try
    {
       my_farm.set_type(0);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

void Manager::waterVeg()
{
    my_farm.water();
}



int Manager::get_farm_type()
{
    return my_farm.get_type();
}

QString Manager::getToolsType(QString name)
{
    string t_name = me.get_tools_type(name.toStdString());
    return QString::fromStdString(t_name);
}

bool Manager::checkAvalableTools(QString name)
{
    if(me.check_avalable_tools(name.toStdString()) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Manager::print()
{
    me.print();
}
