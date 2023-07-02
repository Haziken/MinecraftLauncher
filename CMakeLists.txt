cmake_minimum_required(VERSION 3.2)
set(CMAKE_FIND_DEBUG_MODE 1)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Launcher)

add_executable(Launcher 
src/main.cpp
src/imgui_impl_sdl3.cpp
src/imgui_impl_sdl3.h
src/imgui_impl_sdlrenderer3.cpp
src/imgui_impl_sdlrenderer3.h
src/portable-file-dialogs.h
src/Settings.h
src/Settings.cpp
src/Application.cpp
src/Application.h
src/Minecraft.cpp
src/Minecraft.h
src/Modpack.cpp
src/Modpack.h
)

find_package(SDL3 CONFIG REQUIRED)
target_link_libraries(Launcher PUBLIC SDL3)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(Launcher PRIVATE imgui::imgui)

find_package(CURL CONFIG REQUIRED)
target_link_libraries(Launcher PRIVATE CURL::libcurl)

find_package(ZLIB REQUIRED)
target_link_libraries(Launcher PRIVATE ZLIB::ZLIB)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(Launcher PRIVATE nlohmann_json::nlohmann_json)