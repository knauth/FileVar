#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include "FileVar.h"
using namespace std;
namespace fs = std::filesystem;

/*
Created 21:15 17/17/2020
@author: cknau
*/

FileVar::FileVar(){
    cout << "Type Needed!" << endl;
}

FileVar::FileVar(int i, fs::path in_path){
    type = "int";
    root_dir = in_path;
    fs::path good_path = get_good_path();
    
    my_path = good_path += ".int";
        
    ofstream file(my_path.string());
    
    file << to_string(i) << endl;
    
    file.close();
}

FileVar::FileVar(string s, fs::path in_path){
    type = "string";
    root_dir = in_path;
    fs::path good_path = get_good_path();
    
    my_path = good_path += ".string";
        
    ofstream file(my_path.string());
    
    file << s << endl;
    
    file.close();
}

fs::path FileVar::get_good_path(){
    vector<fs::path> paths;
    for(auto& p: fs::directory_iterator(root_dir)){
        paths.push_back(p.path().stem());
    }
    
    sort(paths.begin(), paths.end());
        
    string last;
    
    if(paths.empty()){
        last = "-1";
    }
    else{
        last = paths.back().stem();
    }
        
    return root_dir /= to_string(stoi(last) + 1);
}

FileVar::~FileVar(){}

bool FileVar::delete_var(){
    return fs::remove(my_path);
}

ostream& operator<< (ostream& out, FileVar& fv){return out;}
