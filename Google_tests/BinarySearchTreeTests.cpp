#include "gtest/gtest.h"
#include "BinarySearchTree.h"

TEST(BSTSuite, insertContainsTest){
    auto bst = std::make_unique<myds::BinarySearchTree<int>>();
    bst->insert(4);
    bst->insert(3);
    bst->insert(5);
    bst->insert(2);
    EXPECT_EQ(bst->contains(4),true);
    EXPECT_EQ(bst->contains(2),true);
    EXPECT_EQ(bst->contains(5),true);
    EXPECT_EQ(bst->contains(3),true);
    EXPECT_EQ(bst->contains(0), false);
    EXPECT_EQ(bst->contains(1), false);
    EXPECT_EQ(bst->contains(6), false);
}

TEST(BSTSuite, insertWithVariadicContainsTest){
    auto bst = std::make_unique<myds::BinarySearchTree<int>>();
    bst->insert(4, 3, 5, 2);
    EXPECT_EQ(bst->contains(4),true);
    EXPECT_EQ(bst->contains(2),true);
    EXPECT_EQ(bst->contains(5),true);
    EXPECT_EQ(bst->contains(3),true);
    EXPECT_EQ(bst->contains(0), false);
    EXPECT_EQ(bst->contains(1), false);
    EXPECT_EQ(bst->contains(6), false);
}

TEST(BSTSuite, removeTest) {
    auto bst = std::make_unique<myds::BinarySearchTree<int>>();
    bst->insert(4,3,5,6);
    EXPECT_EQ(bst->contains(6), true);
    //test remove leaf
    bst->remove(6);
    EXPECT_EQ(bst->contains(6), false);
    bst->insert(6);
    //test remove with 1 child
    bst->remove(5);
    EXPECT_EQ(bst->contains(5), false);
    EXPECT_EQ(bst->contains(6), true);
    bst->insert(5);
    bst->insert(7);
    //test remove with 2 children
    bst->remove(6);
    EXPECT_EQ(bst->contains(5), true);
    EXPECT_EQ(bst->contains(7), true);
    EXPECT_EQ(bst->contains(6), false);
}

TEST(BSTSuite, removeNotFoundTest) {
    testing::internal::CaptureStderr();
    auto bst = std::make_unique<myds::BinarySearchTree<int>>();
    bst->insert(4, 3, 5, 6);
    bst->remove(2);
    EXPECT_EQ(testing::internal::GetCapturedStderr(), "Data not found.\n");
}