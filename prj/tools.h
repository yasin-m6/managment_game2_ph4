#ifndef TOOLS_H
#define TOOLS_H

#include<string>

enum DAS_TYPE{DAS_KOOCHAK = 1 , DAS_BOZORG};
enum BIL_TYPE{BIL_KOOCHAK = 1 , BIL_BOZORG};
enum SHEN_KESH_TYPE{SHEN_KESH_KOOCHAK = 1 , SHEN_KESH_BOZORG};
enum SAM_PASH_TYPE{SAM_PASH_KOOCHAK = 1 , SAM_PASH_BOZORG};
enum LOOLE_TYPE{LOOLE_KOOCHAK = 1 , LOOLE_BOZORG};

class Tools
{
public:
    int get_use_time();
    int get_work_time();

protected:
    int use_time;
    int work_time;
};

class Bil : public Tools
{
private:
    BIL_TYPE type;
public:
    Bil(int);
    std::string get_type();
    void set_type(int);

};

class Das : public Tools
{
private:
    DAS_TYPE type;
public:
    Das(int);
    std::string get_type();
    void set_type(int);

};

class Shen_kesh : public Tools
{
private:
    SHEN_KESH_TYPE type;
public:
    Shen_kesh(int);
    std::string get_type();
    void set_type(int);

};

class Sam_pash : public Tools
{
private:
    SAM_PASH_TYPE type;
public:
    Sam_pash(int);
    std::string get_type();
    void set_type(int);

};

class Loole : public Tools
{
private:
    LOOLE_TYPE type;
public:
    Loole(int);
    std::string get_type();
    void set_type(int);

};

#endif // TOOLS_H
