include_directories(/usr/include/hello)
add_executable(main main.c)
target_link_libraries(main libhello.a)
