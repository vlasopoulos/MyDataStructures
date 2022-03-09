PROJECT(MyDataStructures_lib)

set(HEADER_FILES
        LinkedList.h
        )

set(SOURCE_FILES
        LinkedList.cpp
        )

add_library(MyDataStructures_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})