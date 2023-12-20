project(GrphAlgo)
file(GLOB INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../include")
file(GLOB_RECURSE main_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") #Add all cpp files

add_library(graph ${main_SRC})

target_include_directories(graph PUBLIC ${INCLUDES})

