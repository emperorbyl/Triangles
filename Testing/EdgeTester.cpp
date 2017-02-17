//
// Created by Stephen Clyde on 2/3/17.
//

#include "EdgeTester.h"

#include <iostream>
#include <cmath>
#include "../Point.h"
#include "../Edge.h"

void EdgeTester::testEdge01()
{
    std::cout << "Execute EdgeTester::testEdge01" << std::endl;

    Point p0(0,0,0);
    Point p1(1,0,0);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (e.getLength()!=1)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 1)"
                  << std::endl;
        return;
    }

    if (e.getSlopeX()!=INFINITY)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting INFINITY)"
                  << std::endl;
        return;
    }

    if (e.getSlopeY()!=0)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0)"
                  << std::endl;
        return;
    }

    if (e.getSlopeZ()!=0)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 0)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testEdge02()
{
    std::cout << "Execute EdgeTester::testEdge02" << std::endl;

    Point p0(1,0,0);
    Point p1(3,4,5);

    // Create and test a edge between p0 and p1, then test all characteristics of that edge
    Edge e(&p0, &p1);
    if (!e.isValid() || e.getPoint1() != &p0 || e.getPoint2()!= &p1)
    {
        std::cout << "Failure in constructing Edge(&p1, &p2) isValid()="
                  << e.isValid()
                  << " point1=" << e.getPoint1() << " (expecting " << &p0 << ")"
                  << " point2=" << e.getPoint2() << " (expecting " << &p1 << ")"
                  << std::endl;
        return;
    }

    if (fabs(e.getLength() - 6.708203932) > 0.001)
    {
        std::cout << "Failure in e.getLenth(), length="
                  << e.getLength() << " (expecting 6.708203932)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeX() - 0.312347524) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeX(), slope="
                  << e.getSlopeX() << " (expecting 0.312347524)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeY() - 0.742781353) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeY(), slope="
                  << e.getSlopeY() << " (expecting 0.742781353)"
                  << std::endl;
        return;
    }

    if (fabs(e.getSlopeZ() - 1.118033989) >= 0.001)
    {
        std::cout << "Failure in e.getSlopeZ(), slope="
                  << e.getSlopeZ() << " (expecting 1.118033989)"
                  << std::endl;
        return;
    }
}

void EdgeTester::testParallelEdges()
{
    std::cout << "Execute EdgeTester::testParallelEdges" << std::endl;
    // Create two edges and then test isParallel and then test there slopes.
    Point p1(0,1,0);
    Point p2(0,0,0);
    Point p3(0,4,0);
    Point p4(0,0,0);
    Edge e1(&p1, &p2);
    Edge e2(&p3, &p4);
    if(!e1.isParallelTo(e2))
        std::cout<<"failure in isParallelTo()" << std::endl;
    if(e1.getSlopeX() != e2.getSlopeX())
        std::cout<<"failure in getSlopeX" << std::endl;
    if(e1.getSlopeY() != e2.getSlopeY())
        std::cout<<"failure in getSlopeY" << std::endl;
    if(e1.getSlopeZ() != e2.getSlopeZ())
        std::cout<<"failure in getSlopeZ" << std::endl;
}

void EdgeTester::testNonParallelEdges()
{
    std::cout << "Execute EdgeTester::testNonParallelEdges" << std::endl;
    // Create two edges and test isParallelTo and if the slopes are equal.
    Point p1(0,1,0);
    Point p2(2,7,6);
    Point p3(3,4,3);
    Point p4(6,8,0);
    Edge e1(&p1, &p2);
    Edge e2(&p3, &p4);
    if(e1.isParallelTo(e2))
        std::cout<<"failure in isParallelTo()" << std::endl;
    if(e1.getSlopeX() == e2.getSlopeX() && e1.getSlopeY() == e2.getSlopeY() && e1.getSlopeZ() == e2.getSlopeZ())
        std::cout << "failure in one of the getSlope methods" << std::endl;
}

void EdgeTester::testNonLengthEdges()
{
    std::cout << "Execute EdgeTester::testNonLengthEdges" << std::endl;
    // Create an edge and test it's length and see if the points are the same.
    Point p1(1,1,1);
    Point p2(1,1,1);
    Edge edge(&p1, &p2);
    if(edge.getLength() > 0.00001)
        std::cout << "failure in getLength" << std::endl;
    if(!p1.isEquivalentTo(p2))
        std::cout << "failure in isEquivalentTo" << std::endl;\
}

void EdgeTester::testBadEdges()
{
    // Build an edge and test to see if it is a proper edge.
    std::cout << "Execute EdgeTester::testBadEdges" << std::endl;
    Point p1(-1,-1,-1);
    Point p2(1,1,1);
    Edge edge(&p1, &p2);
    if(edge.getLength() < 0)
        std::cout << "failure in getLength" << std::endl;
    if(p1.isEquivalentTo(p2))
        std::cout << "Not a valid edge" << std::endl;
    if(!edge.isValid())
        std::cout << "Failure in edge construction" << std::endl;
}
