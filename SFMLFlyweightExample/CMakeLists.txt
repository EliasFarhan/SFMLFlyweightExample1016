cmake_minimum_required(VERSION 3.3)
project(SFMLFlyweightExample)


set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)
#SFML
set(SFML_DIR ${EXTERNAL_DIR}/SFML)
set(SFML_BUILD_EXAMPLES FALSE)
set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(${SFML_DIR})
include_directories(${SFML_DIR}/include)

#JSON
set(JSON_DIR ${EXTERNAL_DIR}/json/)
add_subdirectory(${JSON_DIR})
include_directories(${JSON_DIR}/src/)

#SOURCE
include_directories(include/)
file(GLOB SRC src/*.cpp include/*.h)

add_executable(SFMLFlyweightExample ${SRC})

target_link_libraries(SFMLFlyweightExample PUBLIC sfml-system
	sfml-window
	sfml-graphics
	sfml-audio
	sfml-network)