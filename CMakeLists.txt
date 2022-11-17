cmake_minimum_required(VERSION 3.11)
project(simodel VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wunused-result")

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(elfio URL https://github.com/serge1/ELFIO/releases/download/Release_3.10/elfio-3.10.tar.gz)
FetchContent_MakeAvailable(elfio)

FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/refs/tags/v1.11.0.tar.gz)
FetchContent_MakeAvailable(spdlog)

include_directories(
    src
    ${elfio_SOURCE_DIR}
)

file(GLOB_RECURSE SRC_LIST "src/**.cc")

message(STATUS ${SRC_LIST})

add_executable(simodel ${SRC_LIST})
target_link_libraries(simodel PRIVATE nlohmann_json::nlohmann_json spdlog elfio)
