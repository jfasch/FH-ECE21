ADD_LIBRARY(
  fh-ece21-logger

  sensor-values.h
  sensor-config.h
  sink-logger.h
  sink-terminal.h
  sink-mock.h
  sink-file.h
  data-logger.h 
  data-logger.cpp

)

target_link_libraries(fh-ece21-logger fh-ece21-toolcase)
TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-toolcase

  PUBLIC
  .
)
