cmake_minimum_required(VERSION 3.8)

project("Dino")

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} "src/main.cpp" "src/Core/AApplication.h" "src/Core/AApplication.cpp" "src/DinoApplication.h" "src/DinoApplication.cpp" "src/Core/ECS/Components.h" "src/Core/ECS/Entity.h" "src/Core/ECS/Entity.cpp" "src/Core/ECS/Components.cpp" "src/Core/Renderer.h")
add_compile_definitions(ASSETS_DIRECTORY="${CMAKE_SOURCE_DIR}/assets")
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/vendor/raylib/include"
                                                  "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/vendor/raylib/lib")
target_link_libraries(${PROJECT_NAME} PUBLIC "raylib.lib"
                                             "winmm.lib")