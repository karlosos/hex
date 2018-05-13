//
// Created by karol on 5/9/18.
//

#include "gtest/gtest.h"
#include "../src/InputProcessor.h"
#include "../src/Parser.h"
#include "../src/Splitter.h"

TEST(parser, parse_correct_hex_string_to_int)
{
    Parser p;
    EXPECT_EQ(p.hexStringToInt("0"), 0);
    EXPECT_EQ(p.hexStringToInt("1"), 1);
    EXPECT_EQ(p.hexStringToInt("A"), 10);
    EXPECT_EQ(p.hexStringToInt("a"), 10);
    EXPECT_EQ(p.hexStringToInt("01"), 1);
    EXPECT_EQ(p.hexStringToInt("0A"), 10);
}

TEST(parser, throw_exception_on_incorrect_string)
{
    Parser p;
    EXPECT_THROW(p.hexStringToInt("GA"), std::invalid_argument);
}

TEST(input, discard_illegal_chars)
{
    Parser p;
    EXPECT_EQ(p.filterString("01BCDF873126abd12gfGhf3g"), "01BCDF873126abd12ff3");
}

TEST(parser, split_into_pairs_odd)
{
    Parser p;
    std::vector<std::string> pairs;
    pairs.push_back("AB");
    pairs.push_back("12");
    pairs.push_back("3");

    EXPECT_EQ(p.splitStringIntoPairs("AB123"), pairs);
}

TEST(parser, split_into_pairs_even)
{
    Parser p;
    std::vector<std::string> pairs;
    pairs.push_back("AB");
    pairs.push_back("12");
    pairs.push_back("31");

    EXPECT_EQ(p.splitStringIntoPairs("AB1231"), pairs);
}

TEST(parser, split_into_pairs_empty)
{
    Parser p;
    std::vector<std::string> pairs;

    EXPECT_EQ(p.splitStringIntoPairs(""), pairs);
}

TEST(parser, parse_pairs_into_shorts)
{
    Parser p;
    std::vector<std::string> v_string = {"AA", "03", "0A", "0B", "F0", "f", "1"};
    std::vector<unsigned char> v_short = {170, 3, 10, 11, 240, 15, 1};
    EXPECT_EQ(p.convertStringPairsToBytes(v_string), v_short);
}

TEST(splitter, even_numbers_of_ones)
{
    Splitter s;
    EXPECT_EQ(s.isEvenNumberOfOnes(0b11), true);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b101), true);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b0), true);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b011), true);
}

TEST(splitter, odd_numbers_of_ones)
{
    Splitter s;
    EXPECT_EQ(s.isEvenNumberOfOnes(0b10), false);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b100), false);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b01), false);
    EXPECT_EQ(s.isEvenNumberOfOnes(0b010), false);
}

TEST(splitter, into_even_and_odds)
{
    Splitter s;
    std::vector<unsigned char> even = {0, 3, 51, 18, 114, 255};
    std::vector<unsigned char> odd = {1, 4, 42, 127};
    std::vector<std::vector<unsigned char>> even_and_odd;
    std::vector<unsigned char> even_and_odd_together = {0, 1, 3, 4, 42, 51, 18, 127, 114, 255};
    even_and_odd.push_back(even);
    even_and_odd.push_back(odd);
    EXPECT_EQ(s.splitIntoEvenAndOdd(even_and_odd_together), even_and_odd);
}

TEST(splitter, into_even_and_odds_only_odd)
{
    Splitter s;
    std::vector<unsigned char> even;
    std::vector<unsigned char> odd = {1, 4, 42, 127};
    std::vector<std::vector<unsigned char>> even_and_odd;
    std::vector<unsigned char> even_and_odd_together = {1, 4, 42, 127};
    even_and_odd.push_back(even);
    even_and_odd.push_back(odd);
    EXPECT_EQ(s.splitIntoEvenAndOdd(even_and_odd_together), even_and_odd);
}

TEST(splitter, into_even_and_odds_only_even)
{
    Splitter s;
    std::vector<unsigned char> even = {0, 3, 51, 18, 114, 255};
    std::vector<unsigned char> odd = {};
    std::vector<std::vector<unsigned char>> even_and_odd;
    std::vector<unsigned char> even_and_odd_together = {0, 3, 51, 18, 114, 255};
    even_and_odd.push_back(even);
    even_and_odd.push_back(odd);
    EXPECT_EQ(s.splitIntoEvenAndOdd(even_and_odd_together), even_and_odd);
}

TEST(sort, sort_even_and_odd)
{
    InputProcessor ip;
    std::vector<unsigned char> even = {0, 3, 18, 51, 114, 255};
    std::vector<unsigned char> odd = {127, 42, 4, 1};
    std::vector<std::vector<unsigned char>> even_and_odd;
    even_and_odd.push_back(even);
    even_and_odd.push_back(odd);

    std::vector<unsigned char> even_random = {114, 18, 3, 51, 0, 255};
    std::vector<unsigned char> odd_random = {4, 42, 127, 1};
    std::vector<std::vector<unsigned char>> even_and_odd_random;
    even_and_odd_random.push_back(even_random);
    even_and_odd_random.push_back(odd_random);

    EXPECT_NE(even_and_odd_random, even_and_odd);
    ip.sortEvenAndOdd(even_and_odd_random);
    EXPECT_EQ(even_and_odd_random, even_and_odd);
}

TEST(all_toghether, all)
{
    InputProcessor ip;
    std::vector<std::vector<unsigned char>> v = { { 15, 36, 45, 63, 72, 129, 129, 169, 169 }, { 244, 242, 173, 152, 50, 49, 35, 25, 1 } };
    EXPECT_EQ(ip.processRawData("01f4j32198124ashdfr2983yjfhsa9812y348a9312sdf"), v);
}