#----------------------------------------------------------------------
# 
#----------------------------------------------------------------------

# define min version of cmake required
cmake_minimum_required(VERSION 2.8)


# Set variable for project name
set(PROJ_NAME jonesybreakout)


# Set Project
project(${PROJ_NAME})


# This gets rid of the warning you would have seen earlier if you were using Cygwin. 
# If you aren’t using Cygwin then it has no effect at all. 
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

# use cmake folder for FIND modules cmake doesn't have e.g fmod
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})


# Create some custom variables for diff envs
if (WIN32)
  set(MAKE_SYSTEM_WIN32 1)
elseif (APPLE)
  set(MAKE_SYSTEM_MACOSX 1)
else()
  set(MAKE_SYSTEM_LINUX 1)
endif()

set(origin "$ORIGIN")
if (APPLE)
  set(origin "@loader_path")
endif()

# http://www.blaenkdenum.com/notes/cmake/
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--disable-new-dtags")
set (CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set (CMAKE_INSTALL_RPATH "$ORIGIN")

# find opengl
find_package(OpenGL REQUIRED)
#find_package(FMOD REQUIRED)

# add dependencies directory so we build glfw3 from source etc
add_subdirectory(deps)

include_directories(${GLFW_SOURCE_DIR})

# add dependencies headers so we can find them
include_directories(deps/glfw/include)

#FMOD for 64bit linux
include_directories(deps/fmod/linux/inc)
set(FMOD_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/deps/fmod/linux/lib/x86_64/libfmod.so")

# Add a target executable
add_executable(${PROJ_NAME}
  src/main.cpp src/GameWindow.cpp src/Triangle.cpp src/Ball.cpp src/Paddle.cpp src/Brick.cpp src/BoundingBox.cpp src/Vector2.cpp src/Wall.cpp src/Collision.cpp src/Subject.cpp src/InputHandler.cpp src/Background.cpp src/GameSound.cpp
)

# link glfw3 libraries
target_link_libraries(${PROJ_NAME} glfw ${GLFW_LIBRARIES} ${FMOD_LIBRARY})