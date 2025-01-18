#include <string>

#include <gtest/gtest.h>

#include "../../structures/Optional/Optional.hpp"

TEST(OptionalTest, OptionalTestSet) {

  EXPECT_FALSE(Optional<int>().check());
}

TEST(OptionalTest, OptionalTestUnset) {

  EXPECT_TRUE(Optional<int>(4).check());
}
