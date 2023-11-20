# Usage:
#
# IF (MOSQUITTO_FOUND)
#    TARGET_LINK_LIBRARIES(MyTarget Mosquitto::Mosquitto)
# ENDIF()

FIND_PATH(Mosquitto_INCLUDE_DIR mosquitto.h)
FIND_LIBRARY(Mosquitto_LIBRARY NAMES mosquitto)
INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(
  Mosquitto 
  FOUND_VAR MOSQUITTO_FOUND
  REQUIRED_VARS Mosquitto_LIBRARY Mosquitto_INCLUDE_DIR
)

MESSAGE(STATUS "libmosquitto include dir: ${Mosquitto_INCLUDE_DIR}")
MESSAGE(STATUS "libmosquitto: ${Mosquitto_LIBRARY}")
SET(Mosquitto_LIBRARIES ${Mosquitto_LIBRARY})

MARK_AS_ADVANCED(Mosquitto_INCLUDE_DIR Mosquitto_LIBRARY)

ADD_LIBRARY(Mosquitto::Mosquitto INTERFACE IMPORTED)
TARGET_LINK_LIBRARIES(Mosquitto::Mosquitto INTERFACE ${Mosquitto_LIBRARIES})
TARGET_INCLUDE_DIRECTORIES(Mosquitto::Mosquitto INTERFACE ${Mosquitto_INCLUDE_DIR})
