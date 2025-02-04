cmake_minimum_required(VERSION 3.16)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
find_package(nlohmann_json 3.11.3 REQUIRED)

project(SFMLGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE CODE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}" "${CODE_SOURCES}"
        include/utils/RandomUtils.h
        src/utils/RandomUtils.cpp
        src/ui/GalaxyJumpUI.cpp
        include/ui/GalaxyJumpUI.h
        #        src/Planet.cpp
#        include/Planet.h
#        src/Application.cpp
#        include/Application.h
#        include/scenes/GameScene.h
#        src/scenes/SpaceScene.cpp
#        include/scenes/SpaceScene.h
#        src/Renderer.cpp
#        include/Renderer.h
#        include/GameObject.h
)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE sfml-graphics sfml-audio sfml-window sfml-system nlohmann_json::nlohmann_json)