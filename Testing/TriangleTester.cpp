//
// Created by Stephen Clyde on 2/3/17.
//

#include "TriangleTester.h"

#include <iostream>
#include <cmath>
#include <limits>

#include "../Triangle.h"
#include "../Utils.h"

void TriangleTester::testFirstConstructor()
{
    // Build a triangle using pointers and test the properties of a triangle.
    std::cout << "Execute TriangleTester::testFirstConstructorWithPointer" << std::endl;

    Point** points = new Point*[3];
    points[0] = new Point(1,2,8);
    points[1] = new Point(3,1,4);
    points[2] = new Point(6,4,3);

    Triangle t(points);
    if (!t.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t.getTriangleType()!='S')
    {
        std::cout << "Triangle: unexpected type of "
                 << t.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t.computerArea(), 9.35414, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                 << t.computerArea() << std::endl;
        return;
    }

    const Point* p = t.getPoint(0);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 0 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=1 || p->getY()!=2 || p->getZ()!=8)
    {
        std::cout << "Point 0 of triangle is not as expected, namely (1,2,8)" << std::endl;
        return;
    }

    p = t.getPoint(1);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=3 || p->getY()!=1 || p->getZ()!=4)
    {
        std::cout << "Point 1 of triangle is not as expected, namely (3,1,4)" << std::endl;
        return;
    }

    p = t.getPoint(2);
    if (p== nullptr)
    {
        std::cout << "Failure to get point 1 from triangle" << std::endl;
        return;
    }

    if (p->getX()!=6 || p->getY()!=4 || p->getZ()!=3)
    {
        std::cout << "Point 2 of triangle is not as expected, namely (6,4,3)" << std::endl;
        return;
    }
}

void TriangleTester::testSecondConstructor()
{
    // Build a triangle using the triangle constructor and test the properties of a triangle.
    std::cout << "Execute TriangleTester::testSecondConstructor" << std::endl;
    std::string triangleStr = "-10,0,0|10,0,0|0,10,0";
    Triangle t1(triangleStr);
    if(!t1.isValid())
        std::cout<< "Failed to construct triangle from a string." << std::endl;
    if (!t1.isTriangle())
        std::cout << "Failure to constructor a triangle from a string." << std::endl;
    if (t1.getTriangleType()=='N')
        std::cout << "Triangle: unexpected type of " << t1.getTriangleType() << std::endl;
    const Point* p = t1.getPoint(0);
    if (p== nullptr)
        std::cout << "Failure to get point 0 from triangle" << std::endl;
    if (p->getX()!=-10 || p->getY()!=0 || p->getZ()!=0)
        std::cout << "Point 0 of triangle is not as expected, namely (-10,0,0)" << std::endl;
    p = t1.getPoint(1);
    if (p== nullptr)
        std::cout << "Failure to get point 1 from triangle" << std::endl;
    if (p->getX()!=10 || p->getY()!=0 || p->getZ()!=0)
        std::cout << "Point 1 of triangle is not as expected, namely (10,0,0)" << std::endl;
    p = t1.getPoint(2);
    if (p== nullptr)
        std::cout << "Failure to get point 1 from triangle" << std::endl;
    if (p->getX()!=0 || p->getY()!=10 || p->getZ()!=0)
        std::cout << "Point 2 of triangle is not as expected, namely (0,10,0)" << std::endl;

}

void TriangleTester::testEquilateralTriangles()
{
    std::cout << "Execute TriangleTester::testEquilateralTriangles" << std::endl;
// Construct an equilateral triangle and test the properties.
    std::string triangleStr = "-10,0,0|10,0,0|0,17.32050808,0";
    Triangle t1(triangleStr);
    if (!t1.isValid())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
        return;
    }

    if (!t1.isTriangle())
    {
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
        return;
    }

    if (t1.getTriangleType()!='E')
    {
        std::cout << "Triangle: unexpected type of "
                 << t1.getTriangleType() << std::endl;
        return;
    }

    if (!approximatelyEquals(t1.computerArea(), 173.205, 0.001))
    {
        std::cout << "Triangle: unexpected area of "
                 << t1.computerArea() << std::endl;
        return;
    }
    const Point* p0 = t1.getPoint(0);
    const Point* p1 = t1.getPoint(1);
    const Point* p2 = t1.getPoint(2);
    Edge edge0(p0, p1);
    Edge edge1(p1, p2);
    Edge edge2(p2, p0);
    if(edge0.getLength() != edge1.getLength() && edge1.getLength() != edge2.getLength() && edge2.getLength() != edge0.getLength())
        std::cout << "Is not an equilateral triangle because edges are not the same length." << std::endl;
}

void TriangleTester::testIsoscelesTriangles()
{
    // Make an isosceles triangle and test the properties of it.
    std::cout << "Execute TriangleTester::testIsoscelesTriangles" << std::endl;
    std::string stringConstruct = "0,5,0|0,-5,0|12,0,0";
    Triangle triangle(stringConstruct);
    if (!triangle.isValid())
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
    if (!triangle.isTriangle())
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
    if (triangle.getTriangleType()!='I')
        std::cout << "Triangle: unexpected type of " << triangle.getTriangleType() << std::endl;
    const Point* p0 = triangle.getPoint(0);
    const Point* p1 = triangle.getPoint(1);
    const Point* p2 = triangle.getPoint(2);
    Edge edge1(p1, p2);
    Edge edge2(p2, p0);
    if(edge1.getLength() != edge2.getLength())
        std::cout << "Is not an isosceles triangle because the two edges are not the same length." << std::endl;
}

void TriangleTester::testScaleneTriangles()
{
    // Construct a triangle and test the qualities of a scalene triangle.
    std::cout << "Execute TriangleTester::testScaleneTriangles" << std::endl;
    std::string stringConstruct = "0,2,0|0,-3,0|9,0,0";
    Triangle triangle(stringConstruct);
    if (!triangle.isValid())
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
    if (!triangle.isTriangle())
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly not a triangle" << std::endl;
    if (triangle.getTriangleType()!='S')
        std::cout << "Triangle: unexpected type of " << triangle.getTriangleType() << std::endl;
    const Point* p0 = triangle.getPoint(0);
    const Point* p1 = triangle.getPoint(1);
    const Point* p2 = triangle.getPoint(2);
    Edge edge0(p0, p1);
    Edge edge1(p1, p2);
    Edge edge2(p2, p0);
    if(edge0.getLength() == edge1.getLength() || edge1.getLength() == edge2.getLength() || edge2.getLength() == edge0.getLength())
        std::cout << "Is not an scalene triangle because edges are the same length." << std::endl;
}

void TriangleTester::testNonTriangles()
{
    // Make a "Triangle" with points that won't form a triangle and test charecteristics of it.
    std::cout << "Execute TriangleTester::testNonTriangles" << std::endl;
    std::string stringConstruct = "0,5,0|0,5,0|12,0,0";
    Triangle triangle(stringConstruct);
    if (!triangle.isValid())
        std::cout << "Failure to constructor a triangle from 3 points; unexpectedly invalid" << std::endl;
    if (triangle.isTriangle())
        std::cout << "Failure to constructor a triangle from 3 points; unexpected a triangle" << std::endl;
    if (triangle.getTriangleType()!='N')
        std::cout << "Triangle: unexpected type of " << triangle.getTriangleType() << std::endl;
    const Point* p0 = triangle.getPoint(0);
    const Point* p1 = triangle.getPoint(1);
    const Point* p2 = triangle.getPoint(2);
    Edge edge1(p1, p2);
    Edge edge2(p2, p0);
    Edge edge0(p0, p1);
    if(!p0->isEquivalentTo(*p1) && !p1->isEquivalentTo(*p2) && !p2->isEquivalentTo(*p0))
        std::cout << "Failure in isEqualTo." << std::endl;
    if(edge1.isParallelTo(edge2) && edge2.isParallelTo(edge0) && edge0.isParallelTo(edge1))
        std::cout << "Failure in isParallel or in points to make edges." << std::endl;
}

void TriangleTester::testInvalid()
{
    //Pass in invalid parameters to triangle to check validity.
    std::cout << "Execute TriangleTester::testInvalid" << std::endl;
    Point** points = new Point*[3];
    points[0] = new Point(1,2,8);
    points[1] = new Point("3,1,b");
    points[2] = new Point(6,4,7);

    Triangle t(points);
    if(t.isValid())
        std::cout << "Failure in Triangle constructor" << std::endl;
}
