ADD_EXECUTABLE(boiling-pot boiling-pot.cpp)
TARGET_LINK_LIBRARIES(boiling-pot fh-ece21-boiling-pot fh-ece21-base)


IF (MOSQUITTO_FOUND)
    ADD_EXECUTABLE(data-logger data-logger.cpp)
    TARGET_LINK_LIBRARIES(data-logger fh-ece21-data-logger fh-ece21-base)
ENDIF()