cmake_minimum_required(VERSION 3.20)
project(NBody C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.0
)
FetchContent_MakeAvailable(raylib)

add_executable(NBody main.c
        physics/include_physics/physics_include.h
        render/src_render/nbody_simulation.c
        physics/src_physics/interaction_gravitationnelle.c
        physics/src_physics/NBody_update_position.c
        render/include_render/render_include.h
        render/src_render/nbody_draw_objects.c
        physics/src_physics/nbody_set_position_mass_velocity.c
        render/src_render/init_window.c
        render/src_render/menu.c
        render/src_render/init_button.c
        render/src_render/draw_button.c
        render/src_render/exit_simulation.c
        render/src_render/galaxy_simulation.c
        render/src_render/draw_disk.c
        render/src_render/galaxy_draw_objects.c
        physics/src_physics/galaxy_set_position_mass_velocity.c
        physics/src_physics/orbital_velocity.c
        physics/src_physics/galaxy_update_position.c)

target_link_libraries(NBody PRIVATE raylib)