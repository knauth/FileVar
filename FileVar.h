#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
namespace fs=filesystem;

/*
Created 21:15 17/17/2020
@author: knauth
*/
#ifndef _FileVar_
#define _FileVar_

class FileVar{
private:
    string type;
    fs::path my_path;
    fs::path root_dir;
    fs::path get_good_path();

public:    
    FileVar();
    FileVar(int, fs::path);
    FileVar(string, fs::path);
    FileVar(fs::path);
    
    ~FileVar();
    
    bool delete_var();
    
    string get_string();
    int get_int();
    fs::path get_path();
    
    friend ostream& operator<< (ostream&, FileVar&);
};


#endif

