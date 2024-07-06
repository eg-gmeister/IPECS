# IPECS

adds a cool and unnecessary system to C++ for integers

IPECS really is just some Code that has a useless and unrelated name, and really is hard to classify as something.

it boils down to a class that adds the ability to save integers as encoded strings, and then save those encoded strings to an array and a file (10 times).

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
            int returnVal;
    
            while (integer != 0) {
                integer /= 10;
    
                returnVal++;
            }
            return returnVal;
        }
    
    public:

        //--------IPECS--------//

        string IPECS(int USERINPUT, int &nullifyinput, string array[5],string &key1, bool doNull = true) {
            //Integer Processing, Encoding, and Conversion System
            try {
                if (USERINPUT == nullifyinput) {
                            USERINPUT += 1571 << 5;
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
                    throw("error: inputs must be equal");
                }
            } catch(string error) {
                cout << error;
            }
    
        }
    
        int UNIPECS(string input, string &nullifyinput, bool nullstring = true) {
    
            try {
                if (input == nullifyinput) {
                    input.erase(input.length() - 5, 5);
                    input.erase(input.length() - input.length(), 7);
                    int INTINPUT = stoi(input, 0, 10);
                    INTINPUT -= 1571 << 5;
    
                    if (nullstring == true) {
                        NULLIFY_STRING(nullifyinput);
                    }
                    else {
                        nullifyinput = nullifyinput;
                    }
    
                    return INTINPUT;
                } 
                else {
    
                    throw("error: required inputs must be equal");
                }
            }
            catch(string error) {
                cout << error;
                return 0;
            }
            
        
        }

        //--------STIBS---------//
    
        void STIBS(string Array[5], string key, string &key1, bool file) {
            // String Transport and Integer Backup System
            int i = 0;
            while (i < 5) {
                Array[i] = key;
                i++;
            }
    
            if (file == true) {
                key1 = "1571" + key + "1571";
                ofstream file(key1 + "ipecbackup.txt");
    
                for (int i = 0; i < 10; i++) {
                    if (i == 9) {
                        file << key;
                        break;
                    }
                    file << key << "\n";
    
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

lastly, in VTS.cpp I mentioned there was three other functions in the EXTRA_FUNCTIONS class but they arent there at the moment,
they are there in the code above though.

IPECS_EXTRA_FUNCTIONS:

    print(string, bool); | prints a string with a new line (unless bool is false)

    printD(int, bool); | print an integer with a new line (unless bool is false)

    Fprint(float, bool); | print a float with a new line (unless bool is false)

    Dprint(double, bool); | print a double with a new line (unless bool is false)

    Cprint(char, bool); | print a character with a new line (unless bool is false)

    trueIndex(int); | subtracts 1 from input and returns that value (for array and string index)

IPECC:

    IPECS(int, int, string array, string, bool); | converts an integer into a string , *nullifies that integer later if bool is true*, encodes it into something different, saves that string to an array which should have a specific size of 5 (if bool is true), saves the same string to a file 10 times (if bool is true), and then returns said string.

    UNIPECS(string, string, bool); | converts the encoded string back into an integer, *nullifies that string later if bool is true*, and then returns the integer

    STIBS(string array, string, string, bool); | is used for saving the encoded string to an array and to a file, mostly used by IPECS, description more in-depth in VTS.cpp

    OPENSTIBS(string); | opens the file that holds the encoded string and returns that encoded string

    NULLIFY_INT(int); | sets int to 0, is a protected function

    NULLIFY_STRING(string); | sets string to NULL, is a protected function


