ADD_LIBRARY(
  fh-ece21-boiling-pot

  boiling-pot.h
  boiling-pot.cpp
)

TARGET_LINK_LIBRARIES(fh-ece21-boiling-pot fh-ece21-base)
TARGET_INCLUDE_DIRECTORIES(
  fh-ece21-boiling-pot

  PUBLIC
  .
)
