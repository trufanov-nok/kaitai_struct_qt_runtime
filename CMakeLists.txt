cmake_minimum_required (VERSION 3.3)
project (kaitai_struct_cpp_stl_runtime CXX)
enable_testing()

set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(ZLIB)

find_path(ICONV_INCLUDE_DIRS iconv.h)
mark_as_advanced(ICONV_INCLUDE_DIRS)
find_library(ICONV_LIBRARIES NAMES libiconv libiconv-2 iconv)
mark_as_advanced(ICONV_LIBRARIES)

set(ICONV_FOUND FALSE)
if(ICONV_INCLUDE_DIRS AND ICONV_LIBRARIES)
    SET(ICONV_FOUND TRUE)
endif()

set (HEADERS
    kaitai/kaitaistream.h
    kaitai/kaitaistruct.h
    kaitai/exceptions.h
)

set (SOURCES
    kaitai/kaitaistream.cpp
)

set(STRING_ENCODING_TYPE "ICONV" CACHE STRING "Set the way strings have to be encoded (ICONV|WIN32API|NONE|...)")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library (${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY PUBLIC_HEADER ${HEADERS})

if (ZLIB_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${ZLIB_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ZLIB_LIBRARIES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE -DKS_ZLIB)
endif()

if(ICONV_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${ICONV_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ICONV_LIBRARIES})
endif()

include(Common.cmake)

install(TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include/kaitai
)

# Add the tests
add_subdirectory(tests)
