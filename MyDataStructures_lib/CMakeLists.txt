PROJECT(MyDataStructures_lib)

set(HEADER_FILES
        LinkedList.h
        Stack.h
        Queue.h)

set(SOURCE_FILES
        LinkedList.cpp
        Stack.cpp
        Queue.cpp)

add_library(MyDataStructures_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})