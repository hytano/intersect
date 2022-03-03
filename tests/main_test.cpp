#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "intersect/intersect.h"

SCENARIO("The intersector can find out if two line segements intersect", "[intersection]")
{
    GIVEN("two intersecting line segments AB and CD")
    {
        Eigen::Vector2d A(1,1);
        Eigen::Vector2d B(3,3);

        Eigen::Vector2d C(1,3);
        Eigen::Vector2d D(3,1);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A,B,C,D));
            }
        }
    }
    GIVEN("two not intersecting line segments AB and CD")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(3, 1);

        Eigen::Vector2d C(1, 2);
        Eigen::Vector2d D(3, 2);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return false")
            {
                REQUIRE_FALSE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two intersecting line segments AB and CD in the style of a T-intersection")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(3, 1);

        Eigen::Vector2d C(2, 1);
        Eigen::Vector2d D(3, 2);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two intersecting line segments AB and CD where CD lies exactly on top of AB")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(2, 1);
        Eigen::Vector2d D(3, 1);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two intersecting line segments AB and CD where CD intersects with the end point of AB")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(4, 0);
        Eigen::Vector2d D(4, 2);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two intersecting line segments AB and CD where CD intersects with the end point of AB")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(1, 20);
        Eigen::Vector2d D(1, -10);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two line segments AB and CD where B and C are the same point")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(4, 1);
        Eigen::Vector2d D(5, 10);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two line segments AB and CD where B and C are the same point and AB and CD are on the same line")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(4, 1);
        Eigen::Vector2d D(50, 1);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE(hytano::intersecting(A, B, C, D));
            }
        }
    }
    GIVEN("two line segments AB and CD and AB and CD are on the same line")
    {
        Eigen::Vector2d A(1, 1);
        Eigen::Vector2d B(4, 1);

        Eigen::Vector2d C(5, 1);
        Eigen::Vector2d D(50, 1);

        WHEN("checking for intersection")
        {
            THEN("the intersection check shall return true")
            {
                REQUIRE_FALSE(hytano::intersecting(A, B, C, D));
            }
        }
    }
}