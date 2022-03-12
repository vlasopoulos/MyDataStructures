PROJECT(MyDataStructures_lib)

set(HEADER_FILES
        LinkedList.h
        Stack.h
        Queue.h
        Deque.h
        BinarySearchTree.h)

add_library(MyDataStructures_lib INTERFACE)
target_sources(MyDataStructures_lib INTERFACE ${HEADER_FILES})