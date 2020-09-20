cmake_minimum_required(VERSION 3.16)
project(filler C)

set(CMAKE_C_STANDARD 11)

include_directories(general/includes)
include_directories(general/libftprintf/includes)

# Libft
file(GLOB_RECURSE LIBFT_FILES "${PROJECT_SOURCE_DIR}/general/libftprintf/srcs/*.c")
set(LIBFT_FILES ${LIBFT_FILES} ${LIBFT_ADD_FILES})
add_library(ftprintf STATIC ${LIBFT_FILES})


# filler
add_executable(sdagger general/srcs/service.c general/srcs/main.c general/includes/filler.h general/srcs/fill_structure.c)
target_link_libraries(sdagger ${PROJECT_BINARY_DIR}/libftprintf.a)
add_dependencies(sdagger ftprintf)
