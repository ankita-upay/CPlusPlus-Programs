/*
Program name   : Displaying Permutations
Program Author : Ankita Upadhyay
Z-ID           : z1836412
Date Started   : November,27th 2017
Date completed : December,6th 2017
*/
/* Source File : prog11.h */
 #include "/home/cs689/progs/17f/p11/prog11.h" // including already created header file prog11.h
/*
 Function Name :genPerm
 Function Desc :generates all permutations of the
string str and inserts them on the returned set using the following recursive
strategy, which is different than the strategy presented in the textbook:
(a) Removes the first character from str and store it in the variable c.
(b) Generates the set containing all permutations of the remaining characters.
(c) Forms a new set by inserting c in every possible position in each of those
permutations.
 Return Type   : :set < string, cmp >
*/
set <string, cmp> genPerm(const string &str) {

    set <string, cmp> c;

    if (str.empty ()) {
        c.insert ("");
    } else {
        for (unsigned i = 0; i < str.length (); i++) {
            char ch = str[i];
            string rest = str.substr (0, i) + str.substr (i + 1);
            for (string s:genPerm (rest)) {
                c.insert (s + ch);

            }
        }
    }
    return c;
};
/*
 Function Name :genSub
 Function Desc :generates all substrings of the string
str and for each of those substrings generates all permutations by calling the
routine genPerm ( ) and inserts them on the returned set.
 Return Type   : :set < string, cmp >
*/
set <string, cmp> genSub(const string &str3) {
    set <string, cmp> result3;
    set <string, cmp> result1;
    set <string, cmp> result2;
    result3 = genPerm (str3);
    for (set<string, cmp>::iterator it = result3.begin (); it != result3.end (); ++it) {
        string str2 = *it;

        string res = "";
        int n = str2.length ();
        for (int len = 1; len <= n; len++) {

            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                string resstr = "";
                for (int k = i; k <= j; k++) {
                    resstr += str2[k];
                }
                result1 = (genPerm (resstr));
                for (set<string, cmp>::iterator it = result1.begin (); it != result1.end (); ++it) {
                    string str1 = *it;
                    result2.insert (str1);
                }
            }
        }
    }
    return result2;
}
/*Main Function*/
int main() {
    int size = 5;
    string str;
    getline (cin, str);
    set <string, cmp> result;
    result = genSub (str);
    print (result, size);
    return 0;
}
/*
 Function Name :Print
 Function Desc :prints the contents of
the set s on stdout by allocating sz spaces for each printed item. For the output,
do not include the empty string when you’re displaying all permutations, and to
eliminate the empty string, you can start with the iterator ++s.cbegin ( ) for the set
s. The maximum number of elements can be printed on a single line is LSIZE = 10
 Return Type   : void
*/

void print(const set <string, cmp> &s, const unsigned &sz) {
    int i = 1;

    for (set<string, cmp>::iterator it = s.cbegin (); it != s.cend (); ++it) {
        cout << left << setw (sz);
        cout << *it << " ";
        if ((i % LSIZE) == 0)
            cout << endl;
        i++;
    }
    cout << endl;
}
