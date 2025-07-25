/*
 * Copyright (c) 2011, Willow Garage, Inc.
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

#include <gtest/gtest.h>
#include <rviz_common/config.hpp>

TEST(Config, set_then_get) {
  rviz_common::Config c;
  c.mapSetValue("a", "1");
  int a;
  EXPECT_TRUE(c.mapGetInt("a", &a));
  EXPECT_EQ(a, 1);
  float aa;
  EXPECT_TRUE(c.mapGetFloat("a", &aa));
  EXPECT_EQ(aa, 1.0);
  QString aaa;
  EXPECT_TRUE(c.mapGetString("a", &aaa));
  EXPECT_EQ(aaa, "1");
}

TEST(Config, parse_floats) {
  rviz_common::Config c;
  c.mapSetValue("f", "1.1");
  float f;
  EXPECT_TRUE(c.mapGetFloat("f", &f));
  EXPECT_EQ(f, 1.1f);

  // In Europe they use "," for a decimal point.
  c.mapSetValue("f", "1,2");
  EXPECT_TRUE(c.mapGetFloat("f", &f));
  EXPECT_EQ(f, 1.2f);
}

TEST(Config, set_get_empty_value) {
  rviz_common::Config c;
  c.mapSetValue("key", "");

  QString s;
  EXPECT_TRUE(c.mapGetString("key", &s));
  EXPECT_EQ("", s);
}

TEST(Config, mapGetValue_key_not_found_null_check) {
  rviz_common::Config c;
  QString s;
  EXPECT_FALSE(c.mapGetString("non_existent_key", &s));
  EXPECT_EQ(s, "");
  QString s_default("my_default_value");
  EXPECT_FALSE(c.mapGetString("non_existent_key", &s_default));
  EXPECT_EQ(s_default, "my_default_value");
}

TEST(Config, handle_mixed_type_values_for_keys) {
  rviz_common::Config c;
  c.mapSetValue("mixed_key", "123abc");
  EXPECT_FALSE(c.mapGetInt("mixed_key", nullptr));
  EXPECT_FALSE(c.mapGetBool("mixed_key", nullptr));
  EXPECT_FALSE(c.mapGetFloat("mixed_key", nullptr));
  QString string_value;
  EXPECT_TRUE(c.mapGetString("mixed_key", &string_value));
  EXPECT_EQ(string_value, "123abc");
}

int main(int argc, char ** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
