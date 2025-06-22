cmake_minimum_required(VERSION 3.12)
project(crappy-bird VERSION 1.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(NCURSES_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/ncurses-6.5)
set(NCURSES_LIB_DIR ${NCURSES_SOURCE_DIR}/lib)
set(NCURSES_INCLUDE_DIR ${NCURSES_SOURCE_DIR}/include)
set(NCURSES_LIB ${NCURSES_LIB_DIR}/libncursesw.so)

add_custom_command(
  OUTPUT ${NCURSES_LIB}
  COMMAND ./configure --with-shared --enable-widec CFLAGS="-fPIC"
  COMMAND make -j${CMAKE_BUILD_PARALLEL_LEVEL}
  DEPENDS ${NCURSES_SOURCE_DIR}/configure
  WORKING_DIRECTORY ${NCURSES_SOURCE_DIR}
  COMMENT "Building ncurses library"
)

add_custom_target(ncurses DEPENDS ${NCURSES_LIB})

include_directories(
  ${NCURSES_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/lib
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(
  out
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/common.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_timer.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_vector.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_bird.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_camera.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_screen.c
  ${CMAKE_CURRENT_SOURCE_DIR}/src/crappy_pipe.c
)

add_dependencies(out ncurses)

target_link_libraries(out ${NCURSES_LIB})
