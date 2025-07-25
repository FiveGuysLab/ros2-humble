/*
 * Copyright (c) 2017, Bosch Software Innovations GmbH.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../../src/rviz_rendering/string_helper.cpp"  // NOLINT (build/include)

using namespace ::testing;  // NOLINT

TEST(String_Helper__Test, correctly_split_string) {
  std::vector<std::string> expected {"Test", "Test2"};

  std::string test_string("Test \n Test2");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, '\n');

  ASSERT_THAT(expected, Eq(actual));
}

TEST(String_Helper__Test, correctly_split_string_with_whitespace) {
  std::vector<std::string> expected {"Test", "Test2"};

  std::string test_string(" Test  \n \tTest2 ");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, '\n');

  ASSERT_THAT(expected, Eq(actual));
}

TEST(String_Helper__Test, correctly_split_string_at_line_breaks_with_whitespace_in_between) {
  std::vector<std::string> expected {"Test 1", "Test 2"};

  std::string test_string("Test 1 \n Test 2");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, '\n');

  ASSERT_THAT(expected, Eq(actual));
}

TEST(String_Helper__Test, correctly_split_string_with_other_whitespace) {
  std::vector<std::string> expected {"Test", "More"};

  std::string test_string("Test More");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, ' ');

  ASSERT_THAT(expected, Eq(actual));
}

TEST(String_Helper__Test, split_string_with_empty_and_space_items) {
  std::vector<std::string> expected {"Test", "Test2"};
  std::string test_string(" \n Test \n \n Test2 \n ");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, '\n');
  ASSERT_THAT(expected, Eq(actual));
}

TEST(String_Helper__Test, HandlesNothingBesidesDelimiters) {
  std::vector<std::string> expected{};
  std::string test_string(",,\n,\n,,");
  std::vector<std::string> actual = rviz_rendering::string_helper::splitStringIntoTrimmedItems(
    test_string, ',');
  ASSERT_THAT(expected, Eq(actual));
}
