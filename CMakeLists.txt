cmake_minimum_required(VERSION 3.20)
project(Etincelle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML COMPONENTS System Window Graphics Audio REQUIRED)

# Récupère automatiquement tous les fichiers .cpp du dossier src (et sous-dossiers)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(etincelle ${SOURCES})

add_custom_command(TARGET etincelle POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Image
    $<TARGET_FILE_DIR:etincelle>/Image
)

target_include_directories(etincelle PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(etincelle PRIVATE
    SFML::System SFML::Window SFML::Graphics SFML::Audio
)