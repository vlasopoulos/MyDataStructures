PROJECT(MyDataStructures_lib)

set(HEADER_FILES
        LinkedList.h
        Stack.h
        )

set(SOURCE_FILES
        LinkedList.cpp
        Stack.cpp )

add_library(MyDataStructures_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})