#ifndef _NOKTA_
#define _NOKTA_
#include "Nokta.h"
// rastgele deger atayan constructor
Nokta::Nokta(){
    x = (rand() % 150);
    y = (rand() % 50);
    
    this->set_x(x);
    this->set_y(y);
};

// parametreli constructor
Nokta::Nokta(int x, int y){
    this->set_x(x);
    this->set_y(y);
};

// x setter
void Nokta::set_x(int x){
    if(x <= 150 && x >= 0){
        this->x = x;
    }
    else{
        cout << "X degeri 0,150 araliginda degil ! Bu yuzden 0 ataniyor." << endl;
        this->x = 0;
    }
};
// x getter
int Nokta::get_x(){
    return this->x;
};

// y setter
void Nokta::set_y(int y){
    if(y <= 50 && y >= 0){
        this->y = y;
    }
    else{
        cout << "Y degeri 0,50 araliginda degil ! Bu yuzden 0 ataniyor." << endl;
        this->y = 0;
    }
};

// y getter
int Nokta::get_y(){
    return this->y;
};

// noktanin x ve y koordinatlarini ekrana yazdirir
void Nokta::koordinatlariGoster(){
    cout << "X: " << this->get_x() << endl << "Y: " << this->get_y() << endl;
};

// noktanin x,y degerinin 0,0 olup olmadigina bakar
bool Nokta::orijindeMi(){
    return (this->get_x() == 0) && (this->get_y() == 0) ;
};

// noktanin orijine uzakligini hesaplar
float Nokta::orijineUzakligiBul(){
    return sqrt(pow(this->get_x(), 2) + pow(this->get_y(), 2));
};

// noktanin x,y degeri girilen noktaya uzakligini hesaplar
float Nokta::noktayaUzakligiBul(int x, int y){
    return sqrt((pow((this->get_x() - x), 2) + pow((this->get_y() - y), 2)));
};
#endif
