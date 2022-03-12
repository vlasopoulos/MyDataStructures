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