#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "vegtebale.h"
#include "shop.h"
#include"farmer.h"
#include<QString>

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private:
    Vegtebale my_farm;
    Shop theShop;
    Farmer me;

signals:

public slots:

    bool buyTools(QString , int);
    bool buySeeds(QString);
    void sellProducts(QString);

    int get_seeds_price(QString);
    int get_tools_price(QString);

    int getWaterTime();
    int getCropTime();

    int get_crop_spoiled();
    int get_water_spoiled();

    bool checkWaterTime();
    bool checkCropTime();



    int water_timer();
    int crop_timer();
    int spoiled_water_timer();
    int spoiled_crop_timer();

    void plantSeed(int);
    void plowFarm();
    void cropProduct();
    void spoiled_product();
    void waterVeg();

    int get_farm_type();

    QString getToolsType(QString);
    bool checkAvalableTools(QString);

    void print();

};

#endif // MANAGER_H
