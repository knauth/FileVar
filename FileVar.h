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
@author: cknau
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
    
    ~FileVar();
    
    bool delete_var();
    
    string get_content_string();
    int get_content_int();
    
    friend ostream& operator<< (ostream&, FileVar&);
};


#endif

