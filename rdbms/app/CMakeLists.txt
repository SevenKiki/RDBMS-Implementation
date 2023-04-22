include_directories(${CMAKE_SOURCE_DIR}/rdbms/operations)
include_directories(${CMAKE_SOURCE_DIR}/rdbms)
include_directories(${CMAKE_SOURCE_DIR}/rdbms/util)
include_directories(/opt/homebrew/Cellar/boost/1.79.0_1/include/)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

link_directories(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_executable(rdbms_app app.cpp)

target_link_libraries(rdbms_app 
                        operations.a 
                        rSchema.a
                        schema.a
                        table.a
                        tuples.a)

install(TARGETS rdbms_app
        RUNTIME DESTINATION bin)