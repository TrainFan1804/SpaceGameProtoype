##### default configuration stuff #####

cmake_minimum_required(VERSION 3.16)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)
find_package(nlohmann_json 3.11.3 REQUIRED)

project(SFMLGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##### include stuff #####

include_directories(include)

file(GLOB_RECURSE CODE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}" "${CODE_SOURCES}"
        include/utils/RandomUtils.h
        src/utils/RandomUtils.cpp
        src/ui/GalaxyJumpUI.cpp
        include/ui/GalaxyJumpUI.h
        src/ui/UIButton.cpp
        include/ui/UIButton.h
        src/GameSettings.cpp
        include/GameSettings.h
        src/core/renderer/RendererEntry.cpp
        include/core/renderer/RendererEntry.h
        include/scenes/PlanetScene.h
        src/core/statemachine/StateMachine.cpp
        include/core/statemachine/StateMachine.h
        include/assets/PlanetTypes.h
        src/assets/PlanetTypes.cpp
        src/resources/ResourceInventory.cpp
        include/resources/ResourceInventory.h
        src/utils/AssetUtils.cpp
        include/utils/AssetUtils.h
        src/ui/ResourceOverlay.cpp
        include/ui/ResourceOverlay.h
        include/resources/ResourceType.h
        src/resources/ResourceType.cpp
        src/core/debug/Logger.cpp.old
        include/core/debug/Logger.cpp.h.old
        include/core/debug/Debug.h
        src/core/debug/Debug.cpp
)

##### debug stuff ######

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# TODO find a way to deactivate the logger when not in DEBUG mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG_BUILD)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC LOG_FILE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/log/")
endif()

##### more include stuff #####

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE sfml-graphics sfml-audio sfml-window sfml-system nlohmann_json::nlohmann_json)

##### messages #####

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
