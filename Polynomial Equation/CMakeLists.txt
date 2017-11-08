cmake_minimum_required(VERSION 3.8)
project(Polynomial_Equation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h Functions.cpp Functions.h)
add_executable(Polynomial_Equation ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Polynomial_Equation ${SFML_LIBRARIES})
endif()