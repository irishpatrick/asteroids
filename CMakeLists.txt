cmake_minimum_required(VERSION 3.0)

project(asteroids C CXX)

find_package(PkgConfig)
pkg_check_modules(cairo REQUIRED cairo)
pkg_check_modules(sdl2 REQUIRED sdl2)

file(GLOB sources src/*.cpp)
file(GLOB headers src/*.hpp)

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_compile_options(${PROJECT_NAME} PUBLIC -O2 -g ${cairo_CFLAGS_OTHER} ${sdl2_CFLAGS_OTHER})
target_include_directories(${PROJECT_NAME} PUBLIC ${cairo_INCLUDE_DIRS} ${sdl2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} -lpthread -lm ${cairo_LIBRARIES} ${sdl2_LIBRARIES})