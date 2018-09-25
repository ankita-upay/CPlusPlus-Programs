/*Program name  : Caesar Cipher Updated
Program Author : Ankita Upadhyay
Z-ID           : z1836412
Date Started   : September,15th 2017
Date completed : September,25th 2017
 */
/*Source File : prog3.h */

#include "prog3.h"//including the user-defined header file

/*Main Program*/
int main() {
    string shift;//declaring a string type variable shift
    ifstream shift_key (
            Shift_key_file); // declaring a ifstream type variable shift key which open the identifier Shift_key_file
    /*if the ifstream message object is in a bad state or unable to open the data file we output an error message to stderr*/
    if (!shift_key.is_open ()) {
        cerr << "Error in Opening the file which contains shift and key values." << endl;
        exit (EXIT_FAILURE);

    } else {
        /*if the ifstream message object is in a good state then while loop is processed */
        while (shift_key.good ()) {

            getline (shift_key, shift);//getting the regular shift value from prog3.d1 file
            try {
                shift_value = stoi (shift);//coverting string shift value to integer shift_value
            }
            catch (const invalid_argument &e) {
                cout << "";
            }
            cout << "shift = " << shift_value << endl; // displaying shift_value
            getline (shift_key, key);//getting the key value from prog3.d1 file
            cout << "Key = ";
            string printkey = "\"" + key + "\"";
            cout << printkey;
            cout << "\n" << endl;
            process_infile (shift_value, key);//calling the sub-routine process_infile
        }
    }
    shift_key.close ();//closing the Shift_key_file
}

/* Function Name : process_infile
Return type   : void
Function Use : This opens the second data file, and if it is unsuccessful, it displays an error message on stderr
and exits the program with the exit value EXIT_FAILURE. It prints out the shift and key values on stdout passed as
arguments and gets the text input from the data file. To process each input line in the data file, it calls the
encodeCaesarCipher () function .It prints out the encrypted text returned by this function on stdout.
Finally, it closes the data file.
    */
void process_infile(const int &shift, const string &key) {

    string finaltextmessage = "";//declaring & defining a string finaltextmessage
    string encodedmsg = "";//declaring & defining a string encodedmsg
    ifstream message (data_file);// declaring a ifstream type variable message which open the identifier Data_file
    /*if the ifstream message object is in a bad state or unable to open the data file we output an error message to stderr*/
    if (!message.is_open ()) {
        cerr << "Error in Opening the Data file." << endl;
        exit (EXIT_FAILURE);
    } else {
        /*if the ifstream message object is in a good state then while loop is processed */
        while (message.good ()) {
            getline (message, text_message);//getting the message from prog3.d2 file
            finaltextmessage += text_message.append (
                    "\n");//appending the data as getline can read only one line at a time
            string encoded_message = encodeCaesarCipher (text_message, shift,
                                                         key);// calling sub-routine encodeCaesarCipher
            encodedmsg += encoded_message;//appending the final encrypted message
        }

        cout << encodedmsg << endl;//displaying the final encrypted message

    }

}

/* Function Name : encodeCaesarCipher
 *    Return type   : string
 *       Function Use : This function returns a
 *       new string formed by shifting every letter in str forward the number of letters
 *       indicated by shift and key, cycling back to the beginning of the alphabet if
 *       necessary.
 *        */
string encodeCaesarCipher(string str, const int &shift, const string &key) {
    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//declaring and defining a string variable alphabets for storing regular alphabets
    char letters[26];//declaring a character letters array for size 26
    strcpy (letters,
            alphabets.c_str ());//converting string alphabets to character letters using cstring function strcpy
    char chkey[26];//declaring a character  chkey array for size 26
    int key_ascii_value = 0;// declaring & defining an integer variable key_ascii_value and assigning it value 0
    int alphabet_ascii_value = 0;// declaring & defining an integer variable alphabet_ascii_value and assigning it value 0
    int total_shift_value[26];//declaring an integer array total_shift_value of size 26
    int difference_in_ascii_value[26];//declaring an integer array difference_in_ascii_value of size 26
    int second_shift_value[26];//declaring an integer array second_shift_value of size 26
    int final_shift_value[26];//declaring an integer array final_shift_value of size 26

    /*starting a for while loop from 1 to 26 to find the second shift value using following calculation
     *     (( Ascii value of original english alphabets - Ascii value of of each character in key ) +regular shift value ) % 26 */

    for (unsigned int i = 0; i < alphabets.length (); i++) {

        alphabet_ascii_value = alphabets[i];//assigning ascii value of alphabets character to the integer variable alphabet_ascii_value
        key_ascii_value = key[i];//assigning ascii value of key character to the integer variable key_ascii_value
        difference_in_ascii_value[i] = alphabet_ascii_value -
                                       key_ascii_value;// subtracting both the ascii value and storing it in new integer array difference_in_ascii_value
        second_shift_value[i] = difference_in_ascii_value[i] +
                                shift;//adding regular shift value to the difference_in_ascii_value and storing it in second_shift_value
        total_shift_value[i] = second_shift_value[i] % 26;//finding mod value of the shift values greater than 26
        /*if-else condition to check for negative values */
        if (total_shift_value[i] < 0)
            /*if the value is negative we add it with 26 to get a positive shift value*/
            final_shift_value[i] = (total_shift_value[i] + 26);
        else
            /*if the value is positive we leave it as it is*/
            final_shift_value[i] = total_shift_value[i];
        /*if-else condition to check if the value is more than the value of last ascii value that is for 'Z' ie 90*/
        if ((letters[i] + final_shift_value[i]) > 90)
            /*if the value is greater we do the following*/
            chkey[i] = 65 + ((letters[i] + final_shift_value[i]) - 90) - 1;
        else
            /*else we just add the final_shift_value to the character*/
            chkey[i] = letters[i] + final_shift_value[i];
        /*Removing garbage value from the character array*/
        chkey[i + 1] = '\0';
    }

    string final_key (chkey);// converting a character array to string final_key
    string final_enc = "";//defining and declaring a string variable final_enc
    string message = str;//assigning the string message read from the prog3.d2 file to a new string variable message
    /*starting a for loop to replace each character in the message string with the new key string calculated*/
    for (unsigned int i = 0; i < message.length (); i++) {
        char c = message[i];//storing each character in message to a defined character c
        int index = new_position (c, shift,
                                  key);//defining an integer index which stores the return value from the sub-routine new-position
        /*if-else loop to check for -ve index*/
        if (index != -1) {
            if (isupper (message[i])) {
                final_enc += final_key[index];//replacing each upper character with the final key and appending
            } else {
                final_enc += tolower (
                        final_key[index]);//replacing each lower character with the final key and appending
            }
        } else {
            final_enc += message[i];//leaving rest all other characters as it is  and appending
        }

    }
    return final_enc;//returing the final encrypted message

}

/* Function Name : new_position
 *    Return type   : int
 *       Function Use : This function returnsthe new position of character c after shifting
 *          for the shift value & the second shift value obtained from the key
 *           */

int new_position(const char &c, const int &shift, const string &key) {
    int shifttemp = shift;
    string keytemp = key;

    if (shifttemp == shift) {}

    string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//defining and declaring a string variable alphabets
    long index = alphabets.find (
            toupper (c));//finding each character in the alphabet and storing its position in long type variable index
    int temp = index; //assigning index to an integer variable named temp
    return temp;//returning the value temp
}
