#include "gtest/gtest.h"
#include "Stack.h"

TEST(StackSuite, pushPeekSizePopTest) {
    auto s = std::make_unique<myds::Stack<int>>();
    s->push(5);
    EXPECT_EQ(s->peek(), 5);
    EXPECT_EQ(s->getSize(), 1);
    EXPECT_EQ(s->pop(), 5);
    EXPECT_EQ(s->getSize(), 0);
}

TEST(StackSuite, correctOrderTest) {
    auto s = std::make_unique<myds::Stack<int>>();
    s->push(5);
    s->push(6);
    EXPECT_EQ(s->peek(), 6);
}

TEST(StackSuite, isEmptyTest) {
    auto s = std::make_unique<myds::Stack<int>>();
    EXPECT_EQ(s->isEmpty(), true);
    s->push(5);
    EXPECT_NE(s->isEmpty(), true);
}

TEST(StackSuite, emptyStackPopTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Stack<int>>();
    s->pop();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to pop.\n");
}

TEST(StackSuite, emptyStackPeekTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Stack<int>>();
    s->peek();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to peek.\n");
}