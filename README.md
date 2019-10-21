### Scope
This is a sample application to compare poker hands and determine the winner based on the following rules, Poker hands are ranked by the
following partial order from lowest to highest.

 - High Card: Hands which do not fit any higher category are ranked by the value of
their highest card. If the highest cards have the same value, the hands are ranked by
the next highest, and so on.

 - Pair: 2 of the 5 cards in the hand have the same value. Hands which both contain a
pair are ranked by the value of the cards forming the pair. If these values are the
same, the hands are ranked by the values of the cards not forming the pair, in
decreasing order.
 - Two Pairs: The hand contains 2 different pairs. Hands which both contain 2 pairs are
ranked by the value of their highest pair. Hands with the same highest pair are
ranked by the value of their other pair. If these values are the same the hands are
ranked by the value of the remaining card.
 - Three of a Kind: Three of the cards in the hand have the same value. Hands which
both contain three of a kind are ranked by the value of the 3 cards.
 - Straight: Hand contains 5 cards with consecutive values. Hands which both contain a
straight are ranked by their highest card.
 - Flush: Hand contains 5 cards of the same suit. Hands which are both flushes are
ranked using the rules for High Card.
 - Full House: 3 cards of the same value, with the remaining 2 cards forming a pair.
Ranked by the value of the 3 cards.
 - Four of a kind: 4 cards with the same value. Ranked by the value of the 4 cards.
 - Straight flush: 5 cards of the same suit with consecutive values. Ranked by the
highest card in the hand.


### How To Build this Application
```$xslt
#cd build
#cmake ../
#make
```

### How to run this application
Note:- Follow the steps as outlined above to build this application.
```$xslt
#cd source
#./poker_hand
```

Provide sample input e.g `Black: 2H 3D 5S 9C KD White: 2C 3H 4S 8C AH` and press `Enter`.

The output on terminal as below,

`White wins - with High Card : Ace`

### To run gtest
```$xslt
#cd poker-hand/test/build
#cmake ../
#make
#./card_test
```

The output on terminal as below,

```$xslt
[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from GetValueTest
[ RUN      ] GetValueTest.GetValue
[       OK ] GetValueTest.GetValue (0 ms)
[----------] 1 test from GetValueTest (0 ms total)

[----------] 1 test from GetSuitTest
[ RUN      ] GetSuitTest.GetSuit
[       OK ] GetSuitTest.GetSuit (0 ms)
[----------] 1 test from GetSuitTest (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 2 tests.
```

### ToDo
 - Take series of input continuously instead of one at a time.
 - Add more gtest cases and invoke it properly from Cmake
 - Update CMake to build platform specific binaries (at the moment it generates only MacOs/Linus binaries)

### Prerequisites
Before building the application please ensure the system has Cmake and its dependencies installed.
