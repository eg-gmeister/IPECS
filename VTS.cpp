#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

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
};





int main() {
    IPECC IPECS; // Creates variable for the Class that holds IPECS and STIBS
    IPECS_EXTRA_FUNCTIONS IEF; // Creates variable for the Class that holds TrueIndex and Print functions

    int input = 100; //IPECS input
    string inputhold; // This string is for holding the IPECS created key to hold the initial integer
    string inputholdarray[5]; // this is for STIBS backup (Duplicates inputhold 5 times (Variable required, Backups isnt))
    string inputbackupkey; // this is for STIBS file saving (variable is required but file saving isnt)

    //FYI backups, file saving and nullifying are all handled by the last parameter in the IPECS function

    inputhold = IPECS.IPECS(input, input, inputholdarray, inputbackupkey, true);

/*  IPECS basically works by taking an input (first parameter) and converting it to a string (return value) 
    which is in an encoded form that can be unpackaged by UNIPECS (seperate function),
    IPECS will erase that same input (second parameter) if the last parameter is true and run STIBS,
    STIBS will then take the encoded string version of the input and duplicate it 5 times into an array (third parameter)
    and also copy it 10 times into a file.
    If you do not want to copy the key into a file go into the IPECS function and change the last parameter where STIBS is called to false,
    or you can make the last parameter in the called IPECS function false.
    STIBS is use to make sure that if you change a variable that CAN hold the key for this integer you can still have it,
    if you lose the integer (last parameter deletes it), encoded string (UNIPECS last parameter deletes it), backup key and array values somehow,
    you will not be able to access that number or the file that holds the key for that number unless you go back in your code and fix it
*/
     
    IEF.print(inputhold); 
    IEF.printD(input); //should print 0 

/*  print, printD and any other functions in that class are unrelated to IPECS

    the print function print strings and adds a new line by default,
    if you add a false in a second parameter it will not add a new line.
    printD does the same but instead it prints integers (D is derived from %d in C)

    Fprint is floats
    Dprint is doubles
    Cprint is chars
*/

    //Since STIBS was ran and it saved a file with the key and saved the key to an array we should be able to print the same thing as print(inputhold); like this:
/*
    print(inputholdarray[0]);
    print(inputholdarray[1]);
    print(inputholdarray[2]);
    print(inputholdarray[3]);
    print(inputholdarray[4]);

    or

    print(IPECS.OPENSTIBS(inputbackupkey))

    or just 

    print(inputbackupkey)

    OPENSTIBS and the saved Array can help if the original string was lost or overwritten
*/

    input = IPECS.UNIPECS(inputhold, inputhold, true);
/*
    Similar the IPECS function UNIPECS erases (last parameter) the inputted string (second parameter)
    and returns the original input. This erasing with IPECS is done so variables can be reused to hold
    multiple numbers over time. if you want the string to not be erased change the last parameter to false.

    you can also use the Saved Array in place of the string if you want to save the string
    (assign the same number to multiple variables using this key), you can do this up to 5 times with IPECS ran once (ran normally (with STIBS, all booleans true))

    To use OPENSTIBS you must assign the OPENSTIBS value to a string


*/

    IEF.printD(input); // should print original value
    IEF.print(inputhold); // should print NULL
    

/* 
    sidenote:

    in the IPECC class there is are two protected functions:
    NULLIFY_STRING 
    &
    NULLIFY_INT

    these are what set the original inputs to 0 & NULL in IPECS,

    If you want to use these functions you can move them to public OR create a derived class that utilizes these functions


    TUTORIAL IPECS VERSION : 2.1

*/
    return 0;
}

