cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(PROJECT_ProjectName)

#----------------------------------------------------------------------------

set(useROOT false)
set(ProjectName_SOURCE_DIRECTORIES src)
set(ProjectName_HEADER_DIRECTORIES include)
set(ProjectName_EXECUTABLES example)
set(ProjectName_SCRIPTS run.mac vis.mac)

#----------------------------------------------------------------------------

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

if(useROOT)
  list(APPEND ProjectName_SOURCE_DIRECTORIES)
  list(APPEND ProjectName_HEADER_DIRECTORIES)
  list(APPEND ProjectName_EXECUTABLES)
endif(useROOT)

set(ProjectName_SOURCES_DIRECTORIES_FULL)
foreach(_directory ${ProjectName_SOURCE_DIRECTORIES})
  list(APPEND ProjectName_SOURCE_DIRECTORIES_FULL ${PROJECT_SOURCE_DIR}/${_directory})
endforeach(_directory)

set(ProjectName_HEADERS_DIRECTORIES_FULL)
foreach(_directory ${ProjectName_HEADER_DIRECTORIES})
  list(APPEND ProjectName_HEADER_DIRECTORIES_FULL ${PROJECT_SOURCE_DIR}/${_directory})
endforeach(_directory)

set(ProjectName_SOURCES)
foreach(_directory ${ProjectName_SOURCE_DIRECTORIES_FULL})
  list(APPEND ProjectName_SOURCES ${_directory}/*.cc)
endforeach(_directory)

set(ProjectName_HEADERS)
foreach(_directory ${ProjectName_HEADER_DIRECTORIES_FULL})
  list(APPEND ProjectName_HEADERS ${_directory}/*.hh)
endforeach(_directory)

include(${Geant4_USE_FILE})
include_directories(${ProjectName_SOURCE_DIRECTORIES_FULL})
include_directories(${ProjectName_HEADER_DIRECTORIES_FULL})
if(useROOT)
  include_directories(${ROOT_INCLUDE_DIR})
endif(useROOT)

if(useROOT)
  find_package(ROOT REQUIRED)
  EXECUTE_PROCESS(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CXX_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ROOT_CXX_FLAGS}")
endif(useROOT)

file(GLOB sources ${ProjectName_SOURCES})
file(GLOB headers ${ProjectName_HEADERS})

foreach(_executable ${ProjectName_EXECUTABLES})
  add_executable(${_executable} ${_executable}.cc ${sources} ${headers})
if(useROOT)
  EXECUTE_PROCESS(COMMAND root-config --libs OUTPUT_VARIABLE ROOT_LD_FLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)
  set(CMAKE_EXE_LINKER_FLAGS ${ROOT_LD_FLAGS})
  target_link_libraries(${_executable} ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
endif(useROOT)
  target_link_libraries(${_executable} ${Geant4_LIBRARIES})
endforeach(_executable)

foreach(_script ${ProjectName_SCRIPTS})
  configure_file( ${PROJECT_SOURCE_DIR}/${_script} ${PROJECT_BINARY_DIR}/${_script} COPYONLY)
endforeach(_script)

add_custom_target(PROJECT_ProjectName DEPENDS ${ProjectName_EXECUTABLES})

foreach(_executable ${ProjectName_EXECUTABLES})
  install(TARGETS ${_executable} DESTINATION bin)
endforeach(_executable)
