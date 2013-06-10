# Install script for directory: C:/Documents and Settings/William/Meus documentos/Zhockon

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Arquivos de programas/zhockon")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/library/json/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/library/jsonrpc/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/core/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/coronae/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/samples/server/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/samples/allegro/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/samples/helloworld/cmake_install.cmake")
  INCLUDE("C:/Documents and Settings/William/Meus documentos/Zhockon/samples/pyramid/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "C:/Documents and Settings/William/Meus documentos/Zhockon/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "C:/Documents and Settings/William/Meus documentos/Zhockon/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
