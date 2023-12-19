project(GrphAlgo)

file(GLOB_RECURSE main_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp") #Add all cpp files

add_library(graphmain ${main_SRC})

target_include_directories(graphmain PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

