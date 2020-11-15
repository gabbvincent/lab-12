//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "slist.hpp"

#include <cstdlib> // srand, rand
#include <ctime>   // time]
#include <string>
using std::string;

TEST_CASE("singly-linked list") {

  SUBCASE("empty list (bool)") {
    SList<bool> list;

    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), "");
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }

  SUBCASE("minimally populated list (int)") {
    SList<int> list;

    for (int i = 50; i >= -50; i -= 10) {
      list.pushFront(i);
    }

    CHECK_EQ(list.empty(), false);
    CHECK_EQ(list.getSize(), 11);
    CHECK_EQ(list.toString(), string("-50,-40,-30,-20,-10,0,10,20,30,40,50"));
    CHECK_EQ(list.front(), -50);
    list.popFront();
    CHECK_EQ(list.front(), -40);
    list.popFront();
    CHECK_EQ(list.front(), -30);
    list.popFront();
    CHECK_EQ(list.front(), -20);
    list.popFront();
    CHECK_EQ(list.front(), -10);
    list.popFront();

    CHECK_EQ(list.getSize(), 6);
    CHECK_EQ(list.toString(), string("0,10,20,30,40,50"));

    list.clear();
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), "");
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }

  SUBCASE("minimally populated list (string)") {
    SList<string> list;

    string words[5] = {"red", "green", "yellow", "purple", "orange"};
    for (unsigned int i = 0; i < 5; i++) {
      list.pushFront(words[i]);
    }

    CHECK_EQ(list.empty(), false);
    CHECK_EQ(list.getSize(), 5);
    CHECK_EQ(list.toString(), string("orange,purple,yellow,green,red"));
    CHECK_EQ(list.front(), string("orange"));
    list.popFront();
    CHECK_EQ(list.front(), string("purple"));
    list.popFront();
    CHECK_EQ(list.front(), string("yellow"));
    list.popFront();
    CHECK_EQ(list.front(), string("green"));
    list.popFront();

    CHECK_EQ(list.getSize(), 1);
    CHECK_EQ(list.toString(), string("red"));

    list.clear();
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), string(""));
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }

  SUBCASE("stress test (unsigned int)") {
    srand(time(nullptr));

    SList<unsigned int> list;

    for (unsigned int i = 0; i < 1000; i++) {
      list.pushFront(rand() % 1000);
    }

    for (unsigned int i = 0; i < 500; i++) {
      list.popFront();
    }

    CHECK_EQ(list.getSize(), 500);

    list.clear();
    CHECK_EQ(list.empty(), true);
    CHECK_EQ(list.getSize(), 0);
    CHECK_EQ(list.toString(), string(""));
    CHECK_THROWS_WITH_AS(list.front(), "EMPTY LIST", logic_error);
    CHECK_THROWS_WITH_AS(list.popFront(), "EMPTY LIST", logic_error);
  }
}