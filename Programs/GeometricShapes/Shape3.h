#include "/home/cs689/progs/17f/p10/Shape2.h"

#ifndef H_SHAPE3
#define H_SHAPE3

class Box : public Rectangle {
public:
    Box ( const double& = 0, const double& = 0, const double& = 0 );
    Box ( const Box& );
    Box& operator= ( const Box& );
    Box& operator+= ( const Box& );
    ~Box ( );

    double perimeter ( ) const;
    double area ( ) const;
    double volume ( ) const;
    void print ( ) const;

private:
    double height;
};

//********************************************************************

class Cube : public Square {
public:
    Cube ( const double& = 0 );
    Cube ( const Cube& );
    Cube& operator= ( const Cube& );
    Cube& operator+= ( const Cube& );
    ~Cube ( );

    double perimeter ( ) const;
    double area ( ) const;
    double volume ( ) const;
    void print ( ) const;
};

//********************************************************************

class Cylinder : public Circle {
public:
    Cylinder ( const double& = 0, const double& = 0 );
    Cylinder ( const Cylinder& );
    Cylinder& operator= ( const Cylinder& );
    Cylinder& operator+= ( const Cylinder& );
    ~Cylinder ( );

    double perimeter ( ) const;
    double area ( ) const;
    double volume ( ) const;
    void print ( ) const;

private:
    double height;
};

//********************************************************************

class Cone : public Circle {
public:
    Cone ( const double& = 0, const double& = 0 );
    Cone ( const Cone& );
    Cone& operator= ( const Cone& );
    Cone& operator+= ( const Cone& );
    ~Cone ( );

    double perimeter ( ) const;
    double area ( ) const;
    double volume ( ) const;
    void print ( ) const;

private:
    double height;
};

//********************************************************************

class Sphere : public Circle {
public:
    Sphere ( const double& = 0 );
    Sphere ( const Sphere& );
    Sphere& operator= ( const Sphere& );
    Sphere& operator+= ( const Sphere& );
    ~Sphere ( );

    double area ( ) const;
    double volume ( ) const;
};

//********************************************************************

class Tetrahedron : public equTriangle {
public:
    Tetrahedron ( const double& = 0 );
    Tetrahedron ( const Tetrahedron& );
    Tetrahedron& operator= ( const Tetrahedron& );
    Tetrahedron& operator+= ( const Tetrahedron& );
    ~Tetrahedron ( );

    double perimeter ( ) const;
    double area ( ) const;
    double volume ( ) const;
};

#endif
