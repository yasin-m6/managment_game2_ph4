#include "vegtebale.h"
#include<stdexcept>
#include<iostream>
using namespace std;

void Vegtebale::set_type(int veg_type)
{
    if(veg_type > 6 || veg_type < 0)
    {
        throw invalid_argument("Error in using veg_type!!!");
    }

    if(veg_type == 0)
    {
       type = MT;
       crop();
    }
    else if(veg_type == 6)
    {
        type = PLOW;
    }
    else
    {
        switch (veg_type)
        {
            case 1:
                type = GOJE;
            break;
            case 2:
                type = KAHOO;
            break;
            case 3:
                type = KALAM;
            break;
            case 4:
                type = HAVIJ;
            break;
            case 5:
                type = GANDOM;
            break;
        }
        plant();
    }

}

void Vegtebale::plant()
{
    switch (type)
    {
        case GOJE:
            crop_time = 40;
            water_time = 18;
            spoiled_crop_time = 10;
            spoiled_water_time = 5;
        break;
        case KAHOO:
            crop_time = 40;
            water_time = 18;
            spoiled_crop_time = 10;
            spoiled_water_time = 5;
        break;
        case KALAM:
            crop_time = 40;
            water_time = 18;
            spoiled_crop_time = 10;
            spoiled_water_time = 5;
        break;
        case HAVIJ:
            crop_time = 40;
            water_time = 18;
            spoiled_crop_time = 10;
            spoiled_water_time = 5;
        break;
        case GANDOM:
            crop_time = 40;
            water_time = 18;
            spoiled_crop_time = 10;
            spoiled_water_time = 5;
        break;
    }

    plant_time = time(0);
    water_day = plant_time;
}

void Vegtebale::crop()
{
    crop_time = 0;
    water_time = 0;
    spoiled_crop_time = 0;
    spoiled_water_time = 0;
    plant_time = 0;
    water_day = 0;
}

void Vegtebale::water()
{
    water_day = time(0);
}

bool Vegtebale::check_water_time()
{
    if(difftime(time(0) , water_day) >= water_time)
    {
        spoiled_water_day = water_day + water_time;
        return true;
    }
    else
    {
        return false;
    }
}

bool Vegtebale::check_crop_time()
{
    if( difftime(time(0) , plant_time) >= crop_time)
    {
        crop_day = plant_time + crop_time;
        return true;
    }
    else
    {
        return false;
    }
}

int Vegtebale::get_water_time()
{
    return water_time - static_cast<int>(difftime(time(0) , water_day));
}

int Vegtebale::get_crop_time()
{
    return crop_time - static_cast<int>(difftime(time(0) , plant_time));
}

int Vegtebale::get_spoiled_crop_time()
{
    return spoiled_crop_time - static_cast<int>(difftime(time(0) , crop_day));
}

int Vegtebale::get_water_timer()
{
    cerr << water_time << endl;
    return water_time;
}
int Vegtebale::get_crop_timer()
{
    return crop_time;
}

int Vegtebale::get_spoiled_water_timer()
{
    return spoiled_water_time;
}
int Vegtebale::get_spoiled_crop_timer()
{
    return spoiled_crop_time;
}

int Vegtebale::get_type()
{
    return static_cast<int>(type);
}

int Vegtebale::get_spoiled_water_time()
{
    return spoiled_water_time - static_cast<int>(difftime(time(0) , spoiled_water_day));
}
