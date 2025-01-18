#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"

TEST(OptionalTest, OptionalTestSet) {

  EXPECT_FALSE(Optional<int>().check());
}

TEST(OptionalTest, OptionalTestUnset) {

  EXPECT_TRUE(Optional<int>(4).check());
}

TEST(OptionalTest, OptionalGetValue) {

  EXPECT_TRUE(Optional<int>(4).get() == 4);
}

TEST(OptionalTest, OptionalGetPointer) {

  EXPECT_TRUE(*Optional<int>(4) == 4);
}

TEST(OptionalTest, OptionalSetValue) {

  Optional<int> val;
  val.set(3);

  EXPECT_TRUE(*val == 3);

  EXPECT_TRUE(val.check());
}

TEST(OptionalTest, OptionalUnsetValue) {

  Optional<int> val;
  val.set(3);
  val.unset();
  EXPECT_FALSE(val.check());
}