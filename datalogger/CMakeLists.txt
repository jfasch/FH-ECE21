ADD_LIBRARY(
  fh-ece21-logger

  sensor-config.h
  sink-logger.h
  sink-terminal.h
  data-logger.h 
  data-logger.cpp

)

target_link_libraries(fh-ece21-logger fh-ece21-toolcase)
TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-toolcase

  PUBLIC
  .
)
