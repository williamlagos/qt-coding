CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(zhockon-core)

ADD_LIBRARY(zhockon ${LIBTYPE} zhockon.cc structure.cc platform.cc audio.cc graphics.cc elements.cc physics.cc player.cc)
ADD_LIBRARY(zhockon-python ${LIBTYPE} bindings.cc)
TARGET_LINK_LIBRARIES(zhockon ${SDL_LIBRARY} ${OPENAL_LIBRARY} ${ALUT} ${GLUT})
TARGET_LINK_LIBRARIES(zhockon-python zhockon ${PYTHON_LIBRARIES})

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../library)
