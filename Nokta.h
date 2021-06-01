#ifndef _NOKTA_H_
#define _NOKTA_H_
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Nokta{
private:
    int x,y;
public:
    Nokta();//Parametresiz kurucu fonksiyon
    Nokta(int x, int y);//Parametreli kurucu fonksiyon
    void 	set_x(int x);// setter x
    int 	get_x();//getter x
    void 	set_y(int y);// setter y
    int 	get_y();//getter y
    void 	koordinatlariGoster();// noktanin x,y degerini ekrana yazdiriyor
    bool 	orijindeMi();// Nokta orjinde mi=true degil mi=false geri donuyor
    float 	orijineUzakligiBul();// noktanin orijine uzakligini buluyor
    float 	noktayaUzakligiBul(int x, int y);// noktanin, girilen x,y koordinatlarindaki noktaya olan uzakligini buluyor
};
#include "Nokta.cpp"
#endif
