ADD_LIBRARY(
  fh-ece21-data-logger

  sensor-values.h
  sensor-config.h
  sink-logger.h
  sink-terminal.h
  sink-mock.h
  sink-file.h
  data-logger.h 
  data-logger.cpp

)

TARGET_LINK_LIBRARIES(fh-ece21-data-logger fh-ece21-base)
TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-data-logger

  PUBLIC
  .
)
