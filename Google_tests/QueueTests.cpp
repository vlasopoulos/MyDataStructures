#include "gtest/gtest.h"
#include "Queue.h"

TEST(QueueSuite, pushPeekSizePopTest) {
    auto s = std::make_unique<myds::Queue<int>>();
    s->push(5);
    EXPECT_EQ(s->peek(), 5);
    EXPECT_EQ(s->getSize(), 1);
    EXPECT_EQ(s->pop(), 5);
    EXPECT_EQ(s->getSize(), 0);
}

TEST(QueueSuite, correctOrderTest) {
    auto s = std::make_unique<myds::Queue<int>>();
    s->push(5);
    s->push(6);
    EXPECT_EQ(s->peek(), 5);
}

TEST(QueueSuite, isEmptyTest) {
    auto s = std::make_unique<myds::Queue<int>>();
    EXPECT_EQ(s->isEmpty(), true);
    s->push(5);
    EXPECT_NE(s->isEmpty(), true);
}

TEST(QueueSuite, clearTest) {
    auto s = std::make_unique<myds::Queue<int>>();
    s->push(4);
    s->push(5);
    s->clear();
    EXPECT_EQ(s->isEmpty(), true);
}

TEST(QueueSuite, emptyQueuePopTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Queue<int>>();
    s->pop();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to pop.\n");
}

TEST(QueueSuite, emptyQueuePeekTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Queue<int>>();
    s->peek();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to peek.\n");
}
