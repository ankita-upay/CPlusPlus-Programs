/*Program name  : The Date Class
 *  Program Author : Ankita Upadhyay
 *   Z-ID           : z1836412
 *   Date Started   : October,16th 2017
 *Date completed : October,23rd 2017
 *     */

/*Source File : Date.cc */

#include "Date.h"//including header file Date.h

/*Default constructor intializing value with as MONTH = “January”, DAY = 1, and YEAR = 2000*/
Date::Date()
{
    month = "January";
    day = 1;
    year = 2000;
}
Date::Date(const string& MONTH, const int& DAY)
{
    month = MONTH;
    day = DAY ;
    year = 2000;
}
/*public constructor that can be used to create a Date object for the month m, day d, and year y*/
Date::Date(const string& MONTH, const int& DAY, const int& YEAR)
{
    month = MONTH;
    day = DAY;
    year = YEAR;
    Month();
}


/*This public copy constructor that can be used to create a new Date object from the copy of the
   Date object d.*/
Date::Date ( const Date& d )
{
    month=d.month;
    day=d.day;
    year=d.year;
}

/*This is a public assignment operator that overwrites an existing Date object with the copy
     of the Date object d.*/

Date& Date::operator= ( const Date& d )
{
    month=d.month;
    day=d.day;
    year=d.year;
    return *this;

}

/*public function can be used to add n number of days to a Date object.*/

Date& Date:: addDay ( const int& n ) {
    // int y=1980, m=2, d=5 ;
int m;
    int count=0;
    string Month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};

    for (unsigned int i = 0; i < 12; i++) {
        if (month == Month_str[i]) { m=i;}}

    int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Leapmonthday[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int addyears;    //number of years to add

    int dd = n;    //number of days to add

    int lyear = year+(dd/365) ;

    for(int i=year;i<lyear;i++){
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
        {
            count++;
        }
        //cout<<"count"<<count<<endl;
    }
    //cout<<"count"<<count<<endl;
     dd=dd-count;

if(dd<0)
{
    addyears = dd / 365;
    int days_left = dd % 365;
//cout<<"daysleft"<<days_left<<endl;
    year += addyears;
   // cout<<"startyear"<<year<<endl;

    for (int i = days_left; i <0; i++) {
        //cout<<i;
        //cout<<"daysleft"<<days_left<<endl;
        if (isLeapYear()){
            if (day>1)
                day--;
            else if ((day ==1) && (m >0)) {
                day = Leapmonthday[m];
               m--;
            } else if ((day ==1) && (m == 0)) {
                day = 31;
                m = 11;
               // cout<<"year"<<year<<endl;
                year--;
            } else
                cout << " ";

        }
        else{
            if (day >1)
                day--;
            else if ((day ==1) && (m >0)) {
                day = monthdays[m];
                m--;
            } else if ((day == 1) && (m == 0)) {
                day = 31;
                m = 11;
               // cout<<"year"<<year<<endl;
                year=year-1;
            } else
                cout << " ";}
   //cout<<"day"<<day<<endl;
    }
    month=Month_str[m];
    //cout<<"year"<<year<<endl;
}

    else {
    addyears = dd / 365;
   int days_left = dd % 365;
   // cout<<"addyear"<<addyears<<endl;
//cout<<"daysleft"<<days_left<<endl;
    year += addyears;

    for (int i = 0; i < days_left; i++) {
     if (isLeapYear()){
         if (day < Leapmonthday[m])
             day++;
         else if ((day == Leapmonthday[m]) && (m < 11)) {
             day = 1;
             m++;
         } else if ((day == Leapmonthday[m]) && (m == 11)) {
             day = 1;
             month = 1;
           year++;
         } else
             cout << " ";

     }
        else{
        if (day < monthdays[m])
            day++;
        else if ((day == monthdays[m]) && (m < 11)) {
            day = 1;
            m++;
        } else if ((day == monthdays[m]) && (m == 11)) {
            day = 1;
            month = 1;
            year++;
        } else
            cout << " ";}
    }

    month=Month_str[m];}
    return *this;

}

Date& Date::addMonth(const int &n)
{ int m;
    string Month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};
    int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < 12; i++) {
        if (month == Month_str[i]) { m=i ;}}

    //cout<<"monthindex"<<m<<endl;

    int monthchange;
   // unsigned newmonth;
    int newmonth=m+n;
//cout<<"newmonth"<<newmonth<<endl;
   // cout<<newmonth;
    //int monthchange=0;
    int yearchange = newmonth/12;

//cout<<"yearchange"<<yearchange;


    if(n<0)
  {
      if(newmonth<-12) {monthchange=newmonth%12;

      }else{monthchange=newmonth;

    if(newmonth<0){year--;}

          }
  year=year-yearchange;
      if(monthchange<0) {
           monthchange = monthchange + 12;
          //monthchange = 12 - newmonthchange + m;
      }

  }
    else {
        if(newmonth>12) {monthchange=newmonth%12;}else{monthchange=newmonth;}
        //cout<<yearchange;
      //  monthchange=monthchange+m;
        year = year + yearchange;
    }

    // cout<<monthchange<<Month_str[monthchange]<<"re"<<endl;
      if(day>monthdays[monthchange])
      {
         if(monthchange==1&&day==29){ if(isLeapYear()) {month=Month_str[monthchange];}
         }
          else{
          day =1;
          month=Month_str[monthchange+1];}
      }
    else{
          month=Month_str[monthchange];
      }
return *this;
}

Date& Date::addYear(const int &n){
    string Month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};

    int j = year;
    year += n;
    if (year < 1 && j > 0)
    {

        year -= 1;
    }
    else if (year > 1 && j < 0)
    {
        year += 1;
    }
    else if (year == 0)
        year = 1;

    if (month == Month_str[1])
        if (day == 29 && isLeapYear() == 0)
        {
            month = Month_str[2];
            day = 1;
            return *this;
        }

    return *this;
}
/*public member functions can be used to set the month components
 *   of a Date object to the value m by a client program.*/
void Date::setMonth(const string& m)
{
    month = m;
    Month();
}

/*public member functions can be used to set the day components
 *    of a Date object to the value d by a client program.*/
void Date::setDay(const int &d)
{
    day = d;
}

/*public member functions can be used to set the year components
 *    of a Date object to the value y by a client program.*/
void Date::setYear(const int &y)
{
    year = y;
}


/*public member functions can be used to return the month components
 * of a Date object, to a client program.*/



string Date::getMonth() const
{
    return month;
}

int Date::monthIndex ()
{

    string Month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};

    for (unsigned int i = 0; i < Month_str->length(); i++) {
        if (month == Month_str[i]) {
          return i;
        }
    }


}
/*public member functions can be used to return the day components
 *  of a Date object, to a client program.*/
int Date::getDay() const
{
    return day;
}

/*public member functions can be used to return the year components
 *  of a Date object, to a client program.*/
int Date::getYear() const
{
    return year;
}

/*public member function can be used to convert the month component of a Date object by
 *     * changing its first letter to uppercase and the rest of its letters to lowercase, so
 *         * the month of a date can be entered as case insensitive.*/
string Date::Monthy(string month)
{
    string newMonth;
    for (unsigned int i = 0; i<month.size(); i++)
    {
        if (i == 0){
            newMonth += toupper(month.at(i));
        }
        else newMonth += tolower(month.at(i));
    }
    return newMonth;
}

/*public member function can be used to convert the month component of a Date object by
 *     * changing its first letter to uppercase and the rest of its letters to lowercase, so
 *         * the month of a date can be entered as case insensitive.*/
void Date::Month()
{
    string newMonth;
    for (unsigned int i = 0; i<month.size(); i++)// for loop starts from 0 to the month size
    {
        /*if-else condition to convert only first letter to uppercase and the rest of its
         *         letters to lowercase*/
        if (i == 0){
            newMonth += toupper(month.at(i));
        }
        else newMonth += tolower(month.at(i));
    }

    month = newMonth;//storing the new month string in our month
}

/*public member function checks a Date object, and if it’s a valid date, it returns true; otherwise, it returns false.*/
bool Date::isValidDate() const
{
    int days;// declaring a variable days to store number of days in a month
    days = daysInMonth(month);//calling member function daysinmonth and storing its value in days variable

    /*if-else condition to check if the month is valid or not , its callling boolean member function isValidMonth*/
    if (isValidMonth() == true)
    {
        /*if-else condition to check if the days is between 1 to the number of days calculated from daysinmonth member function*/
        if (day >= 1 && day <= days)
        {
            /*if-else condition to check if year s greater than one or not*/
            if (year >= 1)
                return true;
            else
                return false;
        }
        else
            return false;

    }
    else
        return false;

}

/*the private member function bool isValidMonth ( ) const check if the month component is valid*/
bool Date::isValidMonth() const
{
    string newMonth;
    /*it converts the month from the client program to upper case and then uses nested if-else loop
     *     to check if the month is valid or not*/
    for (unsigned int i = 0; i<month.size(); i++)
    {
        newMonth += toupper(month.at(i));
    }

    if (newMonth == "JANUARY")
    {
        return true;
    }
    else if (newMonth == "FEBRUARY")
    {
        return true;
    }
    else if (newMonth == "MARCH")
    {
        return true;
    }
    else if (newMonth == "APRIL")
    {
        return true;
    }
    else if (newMonth == "MAY")
    {
        return true;
    }
    else if (newMonth == "JUNE")
    {
        return true;
    }
    else if (newMonth == "JULY")
    {
        return true;
    }
    else if (newMonth == "AUGUST")
    {
        return true;
    }
    else if (newMonth == "SEPTEMBER")
    {
        return true;
    }
    else if (newMonth == "OCTOBER")
    {
        return true;
    }
    else if (newMonth == "NOVEMBER")
    {
        return true;
    }
    else if (newMonth == "DECEMBER")
    {
        return true;
    }
    else
        return false;
}

/*private member function bool isLeapYear ( ) const to find if a year is leap or not*/
bool Date::isLeapYear() const
{
    /*if-else loop to check if year is leap or not */
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    else
        return false;
}

/*the private member function int daysInMonth ( const string& m ) const to return the number
 *  * of days in the month m to check if the day component is valid. If the month m is February,
 *   * the function daysInMonth ( ) calls the private member function bool isLeapYear ( ) const
 *    * to get the correct number of days in the month m*/
int Date::daysInMonth(const string& month) const
{
    /*if the month is April , June Spetember , Novemebr this function returns 30 days*/

    if (month == "April" || month == "June" || month == "September" || month == "November")
    {
        return 30;
    }
        /*if the month is February this function first check if year is leap or not and then returns 29 or 28 respectively  */
    else if (month == "February")
    {

        return ((isLeapYear()) ? 29 : 28);
    }
    else
        return 31;


}

/*the non-member function: string intToString ( const int& n ), which takes
 * the integer value n and returns its corresponding value as a string*/
string intToString(const int& n)
{
    return to_string(n);
}

/*public member function can be used to convert the
 * month component of a Date object in the form dd–mmm–yyyy, where dd is a
 * one- or two-digit date, mmm the three-letter abbreviation for the month, and
 * yyyy is the four-digit year.*/
string Date::toString()
{
    string str = Monthy(month);
    string str1 = to_string(day);
    string str2 = to_string(year);
    string finalstr = (str1 + "-" + str.substr(0, 3) + "-" + str2);
    return finalstr;

}

/*This non-member function can
 * be implemented as a friend to the Date class, which overloads the extraction
 * operator (>>). It reads the individual date components from the stream is to
 * the Date object d, where a date can be entered either in the form month day
 * year or month day, year.*/
istream& operator >> (istream& is, Date& d)
{



    is >> d.month >> d.day;
    char c;


    do{
        is.get(c);
    } while (c == ' ');

    if (isdigit(c))
        is.unget();

    is >> d.year;

    return is;
}

/*This non-member
 * function can also be implemented as a friend to the Date class, which overloads
 * the insertion operator (<<). It gets the individual components from the Date
 * object d and to the stream os, where d is inserted in os in the form month day,
 * year*/
ostream& operator<<(ostream& os, const Date& d)
{
    os << d.month << " " << d.day << ", " << d.year;
    return os;
}


int Date::dayIndex() const
{
    string Month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                          "October", "November", "December"};
    int b, c;
    if (year > 0)
    {
        c=year - 1;
        b = c * 365;
        b = b + (c / 4);
        b = b - (c / 100);
        b = b + (c / 400);

        if (isLeapYear() == 0)
        {
            if (month == Month_str[11])
            {
                b = b + 334 + day;
            }
            if (month == Month_str[10])
            {
                b = b + 304 + day;
            }
            if (month == Month_str[9])
            {
                b = b + 273 + day;
            }
            if (month == Month_str[8])
            {
                b = b + 243 + day;
            }
            if (month == Month_str[7])
            {
                b = b + 212 + day;
            }
            if (month == Month_str[6])
            {
                b = b + 181 + day;
            }
            if (month == Month_str[5])
            {
                b = b + 151 + day;
            }
            if (month == Month_str[4])
            {
                b = b + 120 + day;
            }
            if (month == Month_str[3])
            {
                b = b + 90 + day;
            }
            if (month == Month_str[2])
            {
                b = b + 59 + day;
            }
            if (month == Month_str[1])
            {
                b = b + 31 + day;
            }
            if (month == Month_str[0])
            {
                b = b + day;
            }
        }
        if (isLeapYear() == 1)
        {
            if (month == Month_str[0])
            {
                b = b + day;
            }
            if (month == Month_str[1])
            {
                b = b + 31 + day;
            }
            if (month == Month_str[2])
            {
                b = b + 60 + day;
            }
            if (month == Month_str[3])
            {
                b = b + 91 + day;
            }
            if (month == Month_str[4])
            {
                b = b + 121 + day;
            }
            if (month == Month_str[5])
            {
                b = b + 152 + day;
            }
            if (month == Month_str[6])
            {
                b = b + 182 + day;
            }
            if (month == Month_str[7])
            {
                b = b + 213 + day;
            }
            if (month == Month_str[8])
            {
                b = b + 244 + day;
            }
            if (month == Month_str[9])
            {
                b = b + 274 + day;
            }
            if (month == Month_str[10])
            {
                b = b + 305 + day;
            }
            if (month == Month_str[11])
            {
                b = b + 335 + day;
            }
        }
    }
    if (year < 0)
    {
        c = year + 1;
        b = c * 365;
        b = b + (c / 4);
        b = b - (c / 100);
        b = b + (c / 400);
        if (isLeapYear() == 0)
        {
            if (month == Month_str[11])
            {
                b = b - 32 + day;
            }
            if (month == Month_str[10])
            {
                b = b - 31 - 31 + day;
            }
            if (month == Month_str[9])
            {
                b = b - 61 - 32 + day;
            }
            if (month == Month_str[8])
            {
                b = b - 92 - 31 + day;
            }
            if (month == Month_str[7])
            {
                b = b - 122 - 32 + day;
            }
            if (month == Month_str[6])
            {
                b = b - 153 -32 + day;
            }
            if (month == Month_str[5])
            {
                b = b - 184 - 31 + day;
            }
            if (month == Month_str[4])
            {
                b = b - 214 - 32 + day;
            }
            if (month == Month_str[3])
            {
                b = b - 245 -31 + day;
            }
            if (month == Month_str[2])
            {
                b = b - 275 - 32 + day;
            }
            if (month == Month_str[1])
            {
                b = b - 306 - 29 + day;
            }
            if (month == Month_str[0])
            {
                b = b - 334 + 32 + day;
            }
        }
        if (isLeapYear() == true)
        {
            if (month == Month_str[11])
            {
                b = b - 32 + day;
            }
            if (month == Month_str[10])
            {
                b = b - 31 - 31 + day;
            }
            if (month == Month_str[9])
            {
                b = b - 61 - 32 + day;
            }
            if (month == Month_str[8])
            {
                b = b - 92 - 31 + day;
            }
            if (month == Month_str[7])
            {
                b = b - 122 - 32 + day;
            }
            if (month == Month_str[6])
            {
                b = b - 153 - 32 + day;
            }
            if (month == Month_str[5])
            {
                b = b - 184 - 31 + day;
            }
            if (month == Month_str[4])
            {
                b = b - 214 - 32 + day;
            }
            if (month == Month_str[3])
            {
                b = b - 245 - 31 + day;
            }
            if (month == Month_str[2])
            {
                b = b - 275 - 32 + day;
            }
            if (month == Month_str[1])
            {
                b = b - 305 - 30 + day;
            }
            if (month == Month_str[0])
            {
                b = b - 334 + 32 + day;
            }
        }
    }
    return b;
}

unsigned int dateDiff(const Date &d1, const Date &d2)
{
    int x = d1.dayIndex();
    int y = d2.dayIndex();
    int z;
    if (y > 0 && x > 0)
    {
        if (y > x)
            z = y - x;
        if (y < x)
            z = x - y;
        return z;
    }
    else if (y < 0 && x>0)
    {
        z = x - y-1;
        return z;
    }
    else if (y > 0 && x < 0)
    {
        z = y - x-1;
        return z;
    }
    else if (y < 0 && x < 0)
    {
        z = y - x;
        if (z < 0)
        {
            return -z;
        }
        if (z > 0)
        {
            return z;
        }
    }
}
