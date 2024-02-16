cmake_minimum_required(VERSION 3.28)

#project name
project(mayaPluginCmake VERSION 1.0 LANGUAGES CXX)

#maya Dir
set(MAYA_DIR "C:/Program Files/Autodesk/Maya2023")

#maya include header
set(MAYA_INCLUDE_DIR ${MAYA_DIR}/include)

#Maya libraries header
set(MAYA_LIBRARIES_DIR ${MAYA_DIR}/lib)

#maya libs
set(MAYA_LIBRARIES
    ${MAYA_LIBRARIES_DIR}/Foundation.lib
    ${MAYA_LIBRARIES_DIR}/OpenMaya.lib
)

#username
set(USERS $ENV{USERNAME})

#set output binary
set(PLUGIN_OUTPUT_DIR "C:/Users/${USERS}/Documents/maya/2023/plug-ins")
message("ABC : ${PLUGIN_OUTPUT_DIR}")

#include header and librarie folder
include_directories(${MAYA_INCLUDE_DIR})
link_directories(${MAYA_LIBRARIES_DIR})

#project source file
set(PROJECT_SOURCE
    src/pluginMain.cpp
    include/SampleCommand.h
)

#config output
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PLUGIN_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PLUGIN_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PLUGIN_OUTPUT_DIR})

#plugin dynamic 
add_library(LeeSample
    SHARED
    ${PROJECT_SOURCE}
)

#Linker
target_link_libraries(LeeSample ${MAYA_LIBRARIES})

add_custom_command(TARGET LeeSample POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LeeSample> ${PLUGIN_OUTPUT_DIR}/LeeSample.mll
)

message("Current Version : ${CMAKE_VERSION}")