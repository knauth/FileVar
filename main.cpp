#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include "FileVar.h"

using namespace std;
namespace fs = filesystem;

int main(){
    fs::path curr_path = fs::current_path();
    fs::path ext_path = "test";
    fs::path use_path = curr_path /= ext_path;
    
    cout << use_path << endl;
        
    FileVar fv1(3, use_path);
    FileVar fv2("heyWorld", use_path);
    
    cout << fv1 << endl;
    cout << fv2 << endl;
    
    cout << fv1.get_int() << endl;
    cout << fv2.get_string() << endl;
    
    fv1.delete_var();
//     fv2.delete_var();
    
    fs::path path_2 = fv2.get_path();
    
    cout << path_2 << endl;
    
    FileVar fv3(path_2);
    cout << fv3 << endl;
    
    fv2.delete_var();
    
    return 0;
}
