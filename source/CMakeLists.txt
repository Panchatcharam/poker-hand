cmake_minimum_required(VERSION 3.14)
project(poker-hand)

set(CMAKE_CXX_STANDARD 11)

add_executable(poker_hand main.cpp PokerHand.cpp Card.cpp PokerPlay.cpp ../include/Common.h ../include/Card.h ../include/PokerHand.h ../include/PokerPlay.h)