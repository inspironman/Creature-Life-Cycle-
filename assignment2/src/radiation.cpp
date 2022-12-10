#include "radiation.h"
#include "creature.h"

using namespace std;

// implementation of class Alpha
Alpha* Alpha::_instance = nullptr;
Alpha* Alpha::instance()
{
    if(_instance == nullptr) {
        _instance = new Alpha();
    }
    return _instance;
}
void Alpha::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

radiation* Alpha::influence(Wombleroot *p)
{
    p->changePower(2);
    return this;
}

radiation* Alpha::influence(Wittenroot *p)
{
    p->changePower(-3);
    return this;
}

radiation* Alpha::influence(Woreroot *p)
{
    p->changePower(1);
    return this;
}

// implementation of class Delta
Delta* Delta::_instance = nullptr;
Delta* Delta::instance()
{
    if(_instance == nullptr) {
        _instance = new Delta();
    }
    return _instance;
}
void Delta::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

radiation* Delta::influence(Wombleroot *p)
{
    p->changePower(-2);
    return this;
}

radiation* Delta::influence(Wittenroot *p)
{
    p->changePower(4);
    return this;
}

radiation* Delta::influence(Woreroot *p)
{
    p->changePower(1);
    return this;
}

// implementation of class No_radiation
No_radiation* No_radiation::_instance = nullptr;
No_radiation* No_radiation::instance()
{
    if(_instance == nullptr) {
        _instance = new No_radiation();
    }
    return _instance;
}
void No_radiation::destroy()
{
	if ( nullptr!=_instance )
	{
		delete _instance;
		_instance = nullptr;
	}
}

radiation* No_radiation::influence(Wombleroot *p)
{
    p->changePower(-1);
    return this;
}

radiation* No_radiation::influence(Wittenroot *p)
{
    p->changePower(-1);
    return this;
}

radiation* No_radiation::influence(Woreroot *p)
{
    p->changePower(-1);
    return this;
}
