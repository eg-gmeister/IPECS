# IPECS

adds a cool and unnecessary system to C++ for integers

IPECS really is just some Code that has a useless and unrelated name, and really is hard to classify as something.

it boils down to a class that adds the ability to save integers as encoded strings, and then save those encoded strings to an array and a file.

but you can really just say that it converts an integer into a string and copies that string so you can hold more values with that string (and integer)

a more in depth tutorial is in the other file VTS.cpp and really explains it a lot more than i do here.

it took me a while to make since im a beginner with c++ and because I didnt really have a plan with this.



if you already understand how to use IPECS then copy the code into your code

----------------------------------------

    
    class IPECC {
    
    
    
    protected:
    
        void NULLIFY_INT(int &input) {
            input = 0;
    
        }
    
        void NULLIFY_STRING(string &input) {
            input = "NULL";
    
        }
        int intLength(int integer) {
            int returnVal = 0;
    
            while (integer != 0) {
                integer /= 10;
    
                returnVal++;
            }
            return returnVal;
        }
    
    public:
    
        //--------IPECS--------//
    
        string IPECS(int USERINPUT, int &nullifyinput, string array[5],string &key1, bool doNull = true) {
            
            try {
                if (USERINPUT == nullifyinput) {
                    USERINPUT += 64 << 5;
                    int INPUTLENGTH = intLength(USERINPUT);
                    string sINPUT = to_string(USERINPUT);
                    sINPUT = "0" + sINPUT + "0";
                    sINPUT = "1IPECS" + sINPUT + "0eel";
    
                    if (doNull == true) {
            
                        NULLIFY_INT(nullifyinput);
                        STIBS(array, sINPUT, key1, true);
                    }
                    else {
                        nullifyinput = nullifyinput;
                    }
    
    
                    return sINPUT;        
                }
                else {
                    throw 1;
                    
                }
            } catch(...) {
    
                time_t timestamp;
                time(&timestamp);
    
                ofstream logfile("log.txt");
    
                logfile << ctime(&timestamp) << " : error: inputs must be equal" << "\n" ;
                cout << "error \n";
    
                return "NULL";
            }
    
        }
    
        int UNIPECS(string input, string &nullifyinput, bool nullstring = true) {
    
            try {
                if (input == nullifyinput) {
                    input.erase(input.length() - 5, 5);
                    input.erase(input.length() - input.length(), 7);
                    int INTINPUT = stoi(input, 0, 10);
                    INTINPUT -= 64 << 5;
    
                    if (nullstring == true) {
                        NULLIFY_STRING(nullifyinput);
                    }
                    else {
                        nullifyinput = nullifyinput;
                    }
    
                    return INTINPUT;
                } 
                else {
    
                    throw 2;
                }
            }
            catch(...) {
    
                time_t timestamp;
                time(&timestamp);
    
                ofstream logfile("log.txt");
    
                logfile << ctime(&timestamp) << " : error : inputs must be equal" << "\n";
                cout << "error \n";
    
                return 0;
            }
            
        
        }
    
        void VOIDIPECS(string &update, int input, string array[5], string buk, bool nullint = true) {
            update = IPECS(input, input, array, buk, nullint);
        }
    
        void VOIDUNIPECS(int &update, string input, bool nullstring = true) {
            update = UNIPECS(input, input, nullstring);
        }
    
        //--------STIBS---------//
    
        void STIBS(string Array[5], string key, string &key1, bool file) {
           
            int i = 0;
            while (i < 5) {
                Array[i] = key;
                i++;
            }
    
            if (file == true) {
                key1 = "64" + key + "64";
                ofstream file(key1 + "ipecbackup.txt");
    
                for (int i = 0; i < 1; i++) {
                    file << key;
                    break;
                }
                file.close();
            }
        }
    
        string OPENSTIBS(string key1) {
    
            string out;
            ifstream file(key1 + "ipecbackup.txt");
    
            while (getline(file, out)) {
                out = out;
            }
    
            file.close();
    
            return out;
        }
    
    };


----------------------------------------------

there is another class (mentioned in VTS.cpp) that adds some more functions:

----------------------------------------------

        class IPECS_EXTRA_FUNCTIONS {
    
    public:
    
        int trueIndex(int index) {
            int trueindex = index - 1;
            return trueindex;
        }
    
        void print(string input, bool newline = true) {
            if (newline == false) {
                cout << input;
            }
            else {
                cout << input << "\n";
            }
        
        }
    
        void printD(int input, bool newline = true) {
            if (newline == false) {
                cout << input;
            }
            else {
                cout << input << "\n";
            }
        }
    
        void Fprint(float input, bool newline = true) {
            if (newline == false) {
                cout << input;
            }
            else {
                cout << input << "\n";
            }
        }
    
        void Dprint(double input, bool newline = true) {
            if (newline == false) {
                cout << input;
            }
            else {
                cout << input << "\n";
            }
        }
    
        void Cprint(char input, bool newline = true) {
            if (newline == false) {
                cout << input;
            }
            else {
                cout << input << "\n";
            }
        }
    };


-----------------------------------

Function Descriptions 

__________________________________


IPECS_EXTRA_FUNCTIONS:

    print(string, bool); | prints a string with a new line (unless bool is false)

    printD(int, bool); | print an integer with a new line (unless bool is false)

    Fprint(float, bool); | print a float with a new line (unless bool is false)

    Dprint(double, bool); | print a double with a new line (unless bool is false)

    Cprint(char, bool); | print a character with a new line (unless bool is false)

    trueIndex(int); | subtracts 1 from input and returns that value (for array and string index)

------------------------------------

IPECC:

    IPECS(int, int, string array, string, bool); | converts an integer into a string , *nullifies that integer later if bool is true*, encodes it into something different, saves that string to an array which should have a specific size of 5 (if bool is true), saves the same string to a file 10 times (if bool is true), and then returns said string.

    UNIPECS(string, string, bool); | converts the encoded string back into an integer, *nullifies that string later if bool is true*, and then returns the integer

    STIBS(string array, string, string, bool); | is used for saving the encoded string to an array and to a file, mostly used by IPECS, description more in-depth in VTS.cpp

    OPENSTIBS(string); | opens the file that holds the encoded string and returns that encoded string

    VOIDIPECS(string, int, string array, string, bool); | Runs similar to IPECS but does not give a return value, instead the first parameter is the string you want to assign the value to and the second parameter takes the place of the original two parameters in the IPECS function (which is called here)

    VOIDUNIPECS(int, string, bool); | Runs similar to UNIPECS but does not give a return value, instead the first parameter is the integer you want to assign the value to and the second parameter takes the place of the original two parameters in the UNIPECS function (which is called here)

    NULLIFY_INT(int); | sets int to 0, is a protected function

    NULLIFY_STRING(string); | sets string to NULL, is a protected function

---------------------------------

Includes:

________________________________

    #include <iostream>

    #include <string>

    #include <cstdlib>

    #include <fstream>

    #include <ctime>
