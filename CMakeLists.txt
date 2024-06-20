cmake_minimum_required(VERSION 3.26)
project(Speech_Contest)

set(CMAKE_CXX_STANDARD 17)



add_executable(speechManager server/speechManager.cpp)

add_executable(Speech_Contest main.cpp)
