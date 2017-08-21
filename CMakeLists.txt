project (kaitai_struct_cpp_stl_runtime CXX)
cmake_minimum_required (VERSION 3.3)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

set (HEADERS
    kaitai/kaitaistream.h
    kaitai/kaitaistruct.h
)

set (SOURCES
    kaitai/kaitaistream.cpp
)

add_library (${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

if (APPLE)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} z iconv)
endif()

install (TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
)
