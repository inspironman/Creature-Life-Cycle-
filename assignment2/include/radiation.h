#pragma once

#include <string>

class Wombleroot;
class Wittenroot;
class Woreroot;

// class of the abstract radiations
class radiation{
public:
    virtual radiation* influence(Wombleroot *p) = 0;
    virtual radiation* influence(Wittenroot *p) = 0;
    virtual radiation* influence(Woreroot   *p) = 0;
    virtual ~radiation() {}
};

// class of Alpha
class Alpha : public radiation
{
public:
    static Alpha* instance();
    radiation* influence(Wombleroot *p) override;
    radiation* influence(Wittenroot *p) override;
    radiation* influence(Woreroot   *p) override;
    static void destroy() ;
protected:
    Alpha(){}
private:
    static Alpha* _instance;
};

// class of Delta
class Delta : public radiation
{
public:
    static Delta* instance();
    radiation* influence(Wombleroot *p) override;
    radiation* influence(Wittenroot *p) override;
    radiation* influence(Woreroot   *p) override;
    static void destroy() ;
protected:
    Delta(){}
private:
    static Delta* _instance;
};

// class of No_radiation
class No_radiation : public radiation
{
public:
    static No_radiation* instance();
    radiation* influence(Wombleroot *p) override;
    radiation* influence(Wittenroot *p) override;
    radiation* influence(Woreroot   *p) override;
    static void destroy() ;
protected:
    No_radiation(){}
private:
    static No_radiation* _instance;
};
