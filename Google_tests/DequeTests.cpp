#include "gtest/gtest.h"
#include "Deque.h"

TEST(DequeSuite, pushPeekSizePopTest) {
    auto s = std::make_unique<myds::Deque<int>>();
    s->pushFront(5);
    EXPECT_EQ(s->peekFront(), 5);
    EXPECT_EQ(s->getSize(), 1);
    EXPECT_EQ(s->popFront(), 5);
    EXPECT_EQ(s->getSize(), 0);
}

TEST(DequeSuite, correctOrderTest) {
    auto s = std::make_unique<myds::Deque<int>>();
    s->pushBack(5);
    s->pushBack(6);
    EXPECT_EQ(s->peekBack(), 6);
    EXPECT_EQ(s->peekFront(), 5);
}

TEST(DequeSuite, isEmptyTest) {
    auto s = std::make_unique<myds::Deque<int>>();
    EXPECT_EQ(s->isEmpty(), true);
    s->pushFront(5);
    EXPECT_NE(s->isEmpty(), true);
}

TEST(DequeSuite, clearTest) {
    auto s = std::make_unique<myds::Deque<int>>();
    s->pushFront(4);
    s->pushBack(5);
    s->clear();
    EXPECT_EQ(s->isEmpty(), true);
}

TEST(DequeSuite, emptyDequePopTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Deque<int>>();
    s->popBack();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to pop.\n");
}

TEST(DequeSuite, emptyDequePeekTest) {
    testing::internal::CaptureStderr();
    auto s = std::make_unique<myds::Deque<int>>();
    s->peekFront();
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Nothing to peek.\n");
}
