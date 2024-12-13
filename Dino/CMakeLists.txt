cmake_minimum_required(VERSION 3.8)

project("Dino")

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "src/main.cpp" 
                               "src/Application.h" 
                               "src/Application.cpp" 
                               "src/Core/ECS/Components.h" 
                               "src/Core/ECS/Entity.h" 
                               "src/Core/Renderer.h" 
                               "src/Core/Renderer.cpp" 
                               "src/Core/SpriteSheet.h"
                               "src/Core/SpriteSheet.cpp" 
                               "src/Core/ECS/AnimationSystem.h" 
                               "src/Core/ECS/AnimationSystem.cpp" 
                               "src/GameLevel.h" 
                               "src/GameLevel.cpp" "src/Core/ECS/PhysicsSystem.h" "src/Core/ECS/PhysicsSystem.cpp")
add_compile_definitions(ASSETS_DIRECTORY="${CMAKE_SOURCE_DIR}/assets")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/vendor/raylib/include"
                                                  "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/vendor/raylib/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC "raylib.lib"
                                             "winmm.lib")