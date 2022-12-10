#pragma once

#include <string>
#include "radiation.h"

// class of the abstract Plants
class Plants{
protected:
    std::string _name;
    int _power;
    Plants (const std::string &str, int e = 0) :_name(str), _power(e) {}
public:
    std::string name() const { return _name; }
    virtual bool alive() const { return _power > 0; }
    void changePower(int e) { _power += e; }
    int getPower() const {return _power; }
    virtual int getAlpha() const { return 0;}
    virtual int getDelta() const { return 0;}
    virtual void influence(radiation* &rad) = 0;
    virtual ~Plants () {}
};

// class of Wombleroot
class Wombleroot : public Plants {
public:
    Wombleroot(const std::string &str, int e = 0) : Plants(str, e){}
    int getAlpha() const override
    {return 10;}
    void influence(radiation* &rad) override {
        rad = rad->influence(this);
    }
    bool alive() const override{ return _power > 0 && _power < 10;}
};

// class of Dune Wittenroot
class Wittenroot : public Plants {
public:
    Wittenroot(const std::string &str, int e = 0) : Plants(str, e){}
    int getDelta() const override
    {
        if(_power < 5)
        {return 4;}
        if(5 <= _power && 10 >= _power)
        {return 1;}
        else
        { return 0;}
    }
    void influence(radiation* &rad) override {
        rad = rad->influence(this);
    }
};

// class of Woreroot
class Woreroot : public Plants {
public:
    Woreroot(const std::string &str, int e = 0) : Plants(str, e){}
    void influence(radiation* &rad) override{
        rad = rad->influence(this);
    }
};



