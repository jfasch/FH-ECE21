ADD_LIBRARY(
  lib-wenzel.lang

  my-first-code.h
  my-first-code.c
)

TARGET_INCLUDE_DIRECTORIES(
  lib-wenzel.lang

  PUBLIC .
)
