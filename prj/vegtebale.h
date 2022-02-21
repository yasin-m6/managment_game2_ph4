#ifndef VEGTEBALE_H
#define VEGTEBALE_H

enum VEG{MT , GOJE , KAHOO , KALAM , HAVIJ , GANDOM , PLOW};

#include<ctime>

class Vegtebale
{
    friend class Farmer;
public:
    void set_type(int);

    void plant();
    void crop();
    void water();

    bool check_water_time();
    bool check_crop_time();

    int get_water_time();
    int get_crop_time();

    int get_spoiled_water_time();
    int get_spoiled_crop_time();

    int get_water_timer();
    int get_crop_timer();
    int get_spoiled_water_timer();
    int get_spoiled_crop_timer();

    int get_type();
private:
    int crop_time;
    int water_time;

    int spoiled_water_time;
    int spoiled_crop_time;

    time_t plant_time;
    time_t water_day;

    time_t crop_day;
    time_t spoiled_water_day;

    VEG type;
};

#endif // VEGTEBALE_H
