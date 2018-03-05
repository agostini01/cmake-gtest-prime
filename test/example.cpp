#include <vector>
#include <algorithm>

#include "gtest/gtest.h"


TEST(ExampleTest, BaseCases)
{

	unsigned int size = 10;

	for(unsigned int index = 0; index < size; index++) {
		EXPECT_EQ(1, 1);
	}

}
