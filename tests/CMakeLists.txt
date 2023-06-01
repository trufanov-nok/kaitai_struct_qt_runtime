find_package(GTest REQUIRED)

add_executable(unittest unittest.cpp)

target_include_directories(unittest PRIVATE ${CMAKE_SOURCE_DIR})

# Link the test executable with the main library and the test framework/library
target_link_libraries(unittest PRIVATE ${PROJECT_NAME} GTest::GTest GTest::Main)

add_test(NAME unittest COMMAND unittest)
