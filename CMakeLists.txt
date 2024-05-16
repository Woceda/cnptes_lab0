cmake_minimum_required(VERSION 3.16)

project(Stream LANGUAGES C)

include_directories(
    lib/inc
    lab/inc)

set(SERVER
    lab/src/server.c
)

set(CLIENT
    lab/src/client.c
)


link_directories(lib/src)

add_executable(server ${SERVER})
add_executable(client ${CLIENT})

target_link_libraries(server pthread rt server_f)
target_link_libraries(client pthread rt client_f)

