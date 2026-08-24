cmake_minimum_required(VERSION 3.20)

project(Etincelle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS System Window Graphics Audio REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(etincelle ${SOURCES}
    src/Game/Handler.hpp
    src/Player/joueur.hpp)

target_include_directories(etincelle PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(etincelle PRIVATE
    SFML::System
    SFML::Window
    SFML::Graphics
    SFML::Audio
)