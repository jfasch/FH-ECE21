ADD_LIBRARY(
  lib-simon.hiden

  my-first-code.h
  my-first-code.c
)

TARGET_INCLUDE_DIRECTORIES(
  lib-simon.hiden

  PUBLIC .
)
