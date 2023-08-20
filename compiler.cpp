#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

static int var_assign_count = 0;
static int heap_assign_count = 0;

int main()
{
    ifstream source_in("source.txt");

    string source_str;

    ////Compiler

    map<string, int> var_name_map;
    map<string, int> heap_name_map;

    int vars[100];
    int heap_memory[100];
    vector<string> var_str;
    string heap_str[100];




    //Output System
    int integerOut;
    string strOut="";
    float fltOut;

    while (getline(source_in, source_str))
    {
        if (source_str[0] == '*')
        {
            // if Integer declared and initiated;
            if (source_str[1] == '~')
            {

                if (source_str[2] == 'i') // Integer
                {
                    if (source_str[3] == '~')
                    {
                        int _c = 4;
                        string name_Holder = "";
                        while (source_str[_c] != '=')
                        {
                            name_Holder += source_str[_c];
                            _c++;
                        }
                        var_name_map[name_Holder] = var_assign_count;
                        var_assign_count++;

                        _c++;
                        // Putting value in var
                        string value_Holder_str = "";
                        while (source_str[_c] != ';')
                        {
                            value_Holder_str += source_str[_c];
                            _c++;
                        }

                        // Converting String to Int
                        int value_to_int = stoi(value_Holder_str);

                        // Assigning Value to corresponding mapped var also Converting to int
                        vars[var_name_map[name_Holder]] = value_to_int;
                        cout << vars[var_name_map[name_Holder]]; //Disble this to show only the Result
                    }
                    else
                    {
                        cout << "Syntax Error: Hyphen(-) required";
                    }
                }
            }
            else if (source_str[1] == '/')
            {
                // Start --- sequence check
                switch (source_str[2])
                {
                case 'm':
                    if (source_str[3] == '~')
                    {
                        // assigning arithmetic variable i.e. the var which will hold the value of the operation
                        int _c = 4;
                        string arth_var="";
                        
                        while(source_str[_c]!='='){
                            arth_var+=source_str[_c];
                            _c++;
                        }

                        heap_name_map[arth_var]=heap_assign_count;
                        heap_str[heap_name_map[arth_var]]=arth_var;
                        heap_assign_count++;
                        heap_memory[heap_name_map[arth_var]]=0;
                        // cout<<heap_str[heap_name_map[arth_var]];
                        
                        //Arithmetic Operation
                        _c++;

                        string operation_var="";
                        while (source_str[_c])
                        {

                            switch (source_str[_c])
                            {
                            case '+':
                                heap_memory[heap_name_map[arth_var]]+=vars[var_name_map[operation_var]];
                                operation_var="";
                                

                            //Shift this to make it more efficient(*********)
                            case '~':
                                _c++;
                                if(source_str[_c]=='/'){

                                    heap_memory[heap_name_map[arth_var]]+=vars[var_name_map[operation_var]];
                                    operation_var="";

                                    integerOut=heap_memory[heap_name_map[arth_var]];
                                    _c++;
                                    if(source_str[_c++]=='p'){
                                        cout<<integerOut;
                                    }
                                }

                            default:
                                operation_var+=source_str[_c];                                                                
                            }
                            _c++;
                        }
                        
                        
                    }
                    else
                    {
                        cout << "Syntax Error: Tilde(~) required";
                    }
                    break;

                default:
                    break;
                }
            }
        }
        
        else
        {
            // If line not started with * (ast)
            cout << "~Syntax Error: * required";
            source_in.close();
            return -1;
        }

        cout<<endl;
    }

    ////Closing and Exitting;
    source_in.close();
    return 0;
}