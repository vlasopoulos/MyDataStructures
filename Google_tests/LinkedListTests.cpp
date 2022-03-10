#include "gtest/gtest.h"
#include "LinkedList.h"

TEST(linkedListNodeSuite, setData_getData_test){
    auto n = std::make_shared<myds::Node<int>>();
    n->data = 5;
    EXPECT_EQ(n->data,5);
}

TEST(linkedListNodeSuite, copyConstructorDataTest){
    auto n = std::make_shared<myds::Node<int>>();
    n->data = 5;
    auto n2 = n;
    EXPECT_EQ(n->data,n2->data);
}

TEST(linkedListNodeSuite, setRightNodeTest){
    auto n = std::make_shared<myds::Node<int>>();
    auto n2 = std::make_shared<myds::Node<int>>();
    n->next = n2;
    EXPECT_EQ(n->next,n2);
    EXPECT_NE(n->next, n2->next);
}

TEST(linkedListNodeSuite, copyConstructorRightNodeTest){
    auto n = std::make_shared<myds::Node<int>>();
    auto n2 = std::make_shared<myds::Node<int>>();
    n->next = n2;
    auto n3 = n;
    EXPECT_EQ(n->next, n3->next);
}

TEST(linkedListSuite, createAndAddToListTest){
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

TEST(linkedListSuite, addAndDeleteFromListTest){
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(3);
    l->add(4);
    l->add(5);
    l->deleteAt(1);
    EXPECT_EQ(l->getSize(),2);
    EXPECT_EQ(l->get(1), 5);
}

TEST(linkedListSuite, addOutOfBoundsTest){
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->add(1, 1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}

TEST(linkedListSuite, deleteOutOfBoundsTest) {
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->deleteAt(1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}

TEST(linkedListSuite, getOutOfBoundsTest) {
    testing::internal::CaptureStderr();
    auto l = std::make_unique<myds::LinkedList<int>>();
    l->get(1);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Index out of bounds.\n");
}