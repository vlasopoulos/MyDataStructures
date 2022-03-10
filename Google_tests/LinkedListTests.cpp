#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(LinkedListNodeSuite, setData_getData_test){
    auto n = std::make_unique<myds::Node<int>>();
    n->data = 5;
    EXPECT_EQ(n->data,5);
}

TEST(LinkedListNodeSuite, copyConstructorDataTest){
    auto n = std::make_shared<myds::Node<int>>();
    n->data = 5;
    auto n2 = n;
    EXPECT_EQ(n->data,n2->data);
}

TEST(LinkedListNodeSuite, setRightNodeTest){
    auto n = std::make_unique<myds::Node<int>>();
    auto n2 = std::make_shared<myds::Node<int>>();
    n->next = n2;
    EXPECT_EQ(n->next,n2);
    EXPECT_NE(n->next, n2->next);
}

TEST(LinkedListNodeSuite, copyConstructorRightNodeTest){
    auto n = std::make_shared<myds::Node<int>>();
    auto n2 = std::make_shared<myds::Node<int>>();
    n->next = n2;
    auto n3 = n;
    EXPECT_EQ(n->next, n3->next);
}

TEST(LinkedListSuite, addToListWithIndexAndGetTest){
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(0, 5);
    EXPECT_EQ(l->get(0), 5);
}

TEST(LinkedListSuite, createAddToList_GetFromListTest){
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(5);
    EXPECT_EQ(l->get(0), 5);
    l->addFirst(3);
    EXPECT_EQ(l->get(0), 3);
    EXPECT_EQ(l->get(1), 5);
    l->add(6);
    l->add(1, 4);
    EXPECT_EQ(l->get(0), 3);
    EXPECT_EQ(l->get(1), 4);
    EXPECT_EQ(l->get(2), 5);
    EXPECT_EQ(l->get(3), 6);
    EXPECT_EQ(l->getSize(), 4);
}

TEST(LinkedListSuite, isEmptyTest) {
    auto l = std::make_unique<myds::LinkedList<int>>();
    EXPECT_EQ(l->isEmpty(), true);
}

TEST(LinkedListSuite, addAndDeleteFromListTest){
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(3);
    l->add(4);
    l->addLast(5);
    l->deleteAt(1);
    EXPECT_EQ(l->getSize(),2);
    EXPECT_EQ(l->get(1), 5);
}

TEST(LinkedListSuite, addOutOfBoundsTest){
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(1, 1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}

TEST(LinkedListSuite, deleteOutOfBoundsTest) {
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->deleteAt(1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}

TEST(LinkedListSuite, getOutOfBoundsTest) {
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->get(1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}