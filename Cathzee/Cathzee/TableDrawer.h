#include "Player.h"

void Player::DisplayPlayerCard() {
    std::cout << "------------------------------------" << std::endl;
    if (aces != -1) {
        std::cout << "a. Aces           | " << aces << std::endl;
    }
    else {
        std::cout << "a. Aces           | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (twos != -1) {
        std::cout << "b. 2's            | " << twos << std::endl;
    }
    else {
        std::cout << "b. 2's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (threes != -1) {
        std::cout << "c. 3's            | " << threes << std::endl;
    }
    else {
        std::cout << "c. 3's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fours != -1) {
        std::cout << "d. 4's            | " << fours << std::endl;
    }
    else {
        std::cout << "d. 4's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fives != -1) {
        std::cout << "e. 5's            | " << fives << std::endl;
    }
    else {
        std::cout << "e. 5's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (sixes != -1) {
        std::cout << "f. 6's            | " << sixes << std::endl;
    }
    else {
        std::cout << "f. 6's            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (bonus != -1) {
        std::cout << "Bonus             | " << bonus << std::endl;
    }
    else {
        std::cout << "Bonus             | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Top Score            | " << topScore << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    if (threeKind != -1) {
        std::cout << "g. 3 of a kind       | " << threeKind << std::endl;
    }
    else {
        std::cout << "g. 3 of a kind       | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fourKind != -1) {
        std::cout << "h. 4 of a kind       | " << fourKind << std::endl;
    }
    else {
        std::cout << "h. 4 of a kind       | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (fullHouse != -1) {
        std::cout << "i. Full House        | " << fullHouse << std::endl;
    }
    else {
        std::cout << "i. Full House        | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (smStraight != -1) {
        std::cout << "j. Sm. Straight      | " << smStraight << std::endl;
    }
    else {
        std::cout << "j. Sm. Straight      | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (lrgStraight != -1) {
        std::cout << "k. Lrg. Straight     | " << lrgStraight << std::endl;
    }
    else {
        std::cout << "k. Lrg. Straight     | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (yahtzee != -1) {
        std::cout << "l. Yahtzee           | " << yahtzee << std::endl;
    }
    else {
        std::cout << "l. Yahtzee           | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    if (chance != -1) {
        std::cout << "m. Chance            | " << chance << std::endl;
    }
    else {
        std::cout << "m. Chance            | " << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Score                    | " << playerScore << std::endl;
    std::cout << "------------------------------------" << std::endl;
}