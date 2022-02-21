#include "tools.h"
#include<stdexcept>
#include<iostream>
using namespace std;

Bil::Bil(int b_type) : Tools()
{
    try {
     set_type(b_type);
    } catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}
string Bil::get_type()
{
   return "bil " + to_string(static_cast<int>(type));
}

Das::Das(int d_type)
{
    try {
     set_type(d_type);
    } catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

string Das::get_type()
{
    return "das " + to_string(static_cast<int>(type));
}

Shen_kesh::Shen_kesh(int sh_type)
{
    try {
     set_type(sh_type);
    } catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

string Shen_kesh::get_type()
{
    return "shen kesh " + to_string(static_cast<int>(type));
}

Sam_pash::Sam_pash(int s_type)
{
    try {
     set_type(s_type);
    } catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

string Sam_pash::get_type()
{
    return "sam pash " + to_string(static_cast<int>(type));
}

Loole::Loole(int l_type)
{
    try
    {
     set_type(l_type);
    }
    catch (invalid_argument &w)
    {
        cerr << w.what() << endl;
    }
}

string Loole::get_type()
{
   return "loole " + to_string(static_cast<int>(type));
}

void Bil::set_type(int b_type)
{
    if(b_type != 1 && b_type != 2)
    {
        throw invalid_argument("there is only 2 type of bil");
    }

    work_time = 0;
    if(b_type == 1)
    {
        type = BIL_KOOCHAK;
        work_time = 3;
    }
    else
    {
        type = BIL_BOZORG;
        work_time = 7;
    }
}

void Das::set_type(int d_type)
{
    if(d_type != 1 && d_type != 2)
    {
        throw invalid_argument("there is only 2 type of das");
    }

    work_time = 0;
    if(d_type == 1)
    {
        type = DAS_KOOCHAK;
        work_time = 2;
    }
    else
    {
        type = DAS_BOZORG;
        work_time = 5;
    }
}

void Shen_kesh::set_type(int sh_type)
{
    if(sh_type != 1 && sh_type != 2)
    {
        throw invalid_argument("there is only 2 type of shen kesh");
    }

    work_time = 0;
    if(sh_type == 1)
    {
        type = SHEN_KESH_KOOCHAK;
        work_time = 3;
    }
    else
    {
        type =SHEN_KESH_BOZORG;
        work_time = 7;
    }
}

void Sam_pash::set_type(int s_type)
{
    if(s_type != 1 && s_type != 2)
    {
        throw invalid_argument("there is only 2 type of sam pash");
    }

    work_time = 0;
    if(s_type == 1)
    {
        type = SAM_PASH_KOOCHAK;
        work_time = 2;
    }
    else
    {
        type = SAM_PASH_BOZORG;
        work_time = 5;
    }
}

void Loole::set_type(int l_type)
{
    if(l_type != 1 && l_type != 2)
    {
        throw invalid_argument("there is only 2 type of loole");
    }

    work_time = 0;
    if(l_type == 1)
    {
        type = LOOLE_KOOCHAK;
        work_time = 2;
    }
    else
    {
        type = LOOLE_BOZORG;
        work_time = 5;
    }
}

int Tools::get_use_time()
{
    return use_time;
}

int Tools::get_work_time()
{
    return work_time;
}
