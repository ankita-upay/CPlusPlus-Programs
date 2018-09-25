#include "/home/cs689/progs/17f/p10/Shape.h"

#ifndef H_SHAPE2
#define H_SHAPE2

#include <math.h>
#include <iostream>

using  namespace std;

#define PI ( 4 * atan ( 1 ) )

class Rectangle : public Shape {
public:
    Rectangle ( const double& = 0, const doubl                                                                                                                          e& = 0 );
    Rectangle ( const Rectangle& );
    Rectangle& operator= ( const Rectangle& );
    Rectangle& operator+= ( const Rectangle& )                                                                                                                          ;
    ~Rectangle ( );

    double perimeter ( ) const;
    double area ( ) const;
    void print ( ) const;

protected:
    double length, width;

private:
    void copy ( const Rectangle& );
};

//********************************************                                                                                                                          ************************

class Circle : public Shape {
public:
    Circle ( const double& = 0 );
    Circle ( const Circle& );
    Circle& operator= ( const Circle& );
    Circle& operator+= ( const Circle& );
    ~Circle ( );

    double perimeter ( ) const;
    double area ( ) const;
    void print ( ) const;

protected:
    double radius;

private:
    void copy ( const Circle& );
};

//********************************************                                                                                                                          ************************

class Triangle : public Shape {
public:
    Triangle ( const double& = 0, const double                                                                                                                          & = 0,
        const double& = 0);
    Triangle ( const Triangle& );
    Triangle& operator= ( const Triangle& );
    Triangle& operator+= ( const Triangle& );
    ~Triangle ( );

    double perimeter ( ) const;
    double area ( ) const;
    void print ( ) const;

protected:
    double a, b, c;

private:
    void copy ( const Triangle& );
};

//********************************************                                                                                                                          ************************

class Square : public Rectangle {
public:
    Square ( const double& = 0 );
    Square ( const Square& );
    Square& operator= ( const Square& );
    Square& operator+= ( const Square& );
    ~Square ( );

    void print ( ) const;
};

//********************************************                                                                                                                          ************************

class rightTriangle : public Triangle {
public:
    rightTriangle ( const double& = 0, const d                                                                                                                          ouble& = 0 );
    rightTriangle ( const rightTriangle& );
    rightTriangle& operator= ( const rightTria                                                                                                                          ngle& );
    rightTriangle& operator+= ( const rightTri                                                                                                                          angle& );
    ~rightTriangle ( );

    void print ( ) const;
};

//********************************************                                                                                                                          ************************

class equTriangle : public Triangle {
public:
    equTriangle ( const double& = 0 );
    equTriangle ( const equTriangle& );
    equTriangle& operator= ( const equTriangle                                                                                                                          & );
    equTriangle& operator+= ( const equTriangl                                                                                                                          e& );
    ~equTriangle ( );

    void print ( ) const;
};

#endif
