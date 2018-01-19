cmake_minimum_required(VERSION 3.9)
project(castle_hunter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/event.c
        src/explosion.c
        src/lives.c
        src/main.c
        src/score.c
        src/target.c
        src/cursor.c
        src/gui.c
        src/tools/tools_sprite.c
        src/kernel/init_main.c
        src/kernel/init_window.c
        src/kernel/init_ui.c
        src/kernel/init_target.c
        src/tools/tools_gui.c
        src/ending.c
        src/events/events_gui.c
        src/boss.c
        src/kernel/init_boss.c
	src/events/events_boss.c
	src/tools/tools_global.c
	src/boss_health.c)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories(include)

add_executable(caslte_hunter ${SOURCE_FILES})

target_link_libraries(castle_hunter c_graph_prog)
