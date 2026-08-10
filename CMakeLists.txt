cmake_minimum_required(VERSION 3.20)
project(Etincelle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS System Window Graphics Audio REQUIRED)

add_executable(etincelle src/main.cpp)

target_link_libraries(etincelle PRIVATE
    SFML::System SFML::Window SFML::Graphics SFML::Audio
)