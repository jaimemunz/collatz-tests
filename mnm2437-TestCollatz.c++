// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("3 9\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 3, i);
    ASSERT_EQ(9, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("1 5\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(5, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("5 7\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 5, i);
    ASSERT_EQ(7, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(564, 920);
    ASSERT_EQ(179, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(231, 812);
    ASSERT_EQ(171, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 564, 920, 179);
    ASSERT_EQ("564 920 179\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 231, 812, 171);
    ASSERT_EQ("231 812 171\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("13 277\n555 937\n602 658\n86 238\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("13 277 128\n555 937 179\n602 658 145\n86 238 128\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("255 605\n315 374\n769 974\n165 376\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("255 605 144\n315 374 144\n769 974 179\n165 376 144\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("155 666\n596 639\n435 486\n677 721\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("155 666 145\n596 639 132\n435 486 129\n677 721 171\n", w.str());}
