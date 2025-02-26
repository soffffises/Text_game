cmake_minimum_required(VERSION 3.26.0)
project(hillel-game)

find_package(fmt CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

set(GAME_DIR src)
set(GAME_SRC
    ${GAME_DIR}/main.cpp
    ${GAME_DIR}/Player.cpp
    ${GAME_DIR}/Command.cpp
    ${GAME_DIR}/World.cpp
    ${GAME_DIR}/Utils.cpp
    ${GAME_DIR}/Location.cpp
    ${GAME_DIR}/Item.cpp)

include_directories(${GAME_DIR})

add_executable(${PROJECT_NAME} ${GAME_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES
                                            CXX_STANDARD 20
                                            CXX_STANDARD_REQUIRED ON)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt nlohmann_json::nlohmann_json)