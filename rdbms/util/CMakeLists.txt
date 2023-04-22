add_library(tuples STATIC tuples.cpp tuples.hpp)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

install(TARGETS tuples 
        ARCHIVE DESTINATION lib/rdbms)
        