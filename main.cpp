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
    curr_path /= ext_path;
        
    FileVar fv1(3, curr_path);
    FileVar fv2("heyWorld", curr_path);
    
    cout << fv1 << endl;
    cout << fv2 << endl;
    
    cout << fv1.get_content_int() << endl;
    cout << fv2.get_content_string() << endl;
    
    fv1.delete_var();
    fv2.delete_var();
    
    return 0;
}
