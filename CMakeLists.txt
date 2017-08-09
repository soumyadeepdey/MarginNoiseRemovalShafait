cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Release)

project(ocropus_noisefilter)

set(CMAKE_CXX_FLAGS "-Wall -O2 -std=c++0x ")

add_executable(noisefilter NoiseFilter_ocropus.cc folder.cpp folder.h)

# find opencv package
#find_package( OpenCV REQUIRED )

# includes
#set(LEPTONICA_INCLUDE_PATH "/usr/local/include/leptonica")
set(ocropus_INCLUDE_PATH "/usr/local/include/ocropus")
set(colib_INCLUDE_PATH "/usr/local/include/colib")
set(iulib_INCLUDE_PATH "/usr/local/include/iulib")
#set(TESSERACT_INCLUDE_PATH "/usr/local/include/tesseract")
#include_directories(${OpenCV_INCLUDE_DIRS} ${LEPTONICA_INCLUDE_PATH} ${TESSERACT_INCLUDE_PATH})
#include_directories(${OpenCV_INCLUDE_DIRS} ${TESSERACT_INCLUDE_PATH})
include_directories(${ocropus_INCLUDE_PATH} ${colib_INCLUDE_PATH} ${iulib_INCLUDE_PATH})
set(LINK_DIR "/usr/local/lib")
link_directories(${LINK_DIR})

# libraries
set(OCROPUS_LIB "ocropus")
#set(COLIB_LIB "colib")
set(IULIB_LIB "iulib")
set(LIBS ${OCROPUS_LIB} ${COLIB_LIB} ${IULIB_LIB})
#set(LEPTONICA_LIBS "lept")
#set(LIBS ${LIBS} ${LEPTONICA_LIBS})
#set(TESSERAC_LIBS "tesseract")
# set(LIBS ${LIBS} ${OpenCV_LIBS} ${LEPTONICA_LIBS} ${TESSERAC_LIBS})
#set(LIBS ${LIBS} ${OpenCV_LIBS} ${TESSERAC_LIBS})
target_link_libraries(noisefilter ${LIBS})
