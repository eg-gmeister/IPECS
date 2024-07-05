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

