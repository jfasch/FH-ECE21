Development Workflow
====================

.. contents::
   :local:

Checkout and Initialization
---------------------------

.. code-block:: console

   $ cd ~                            # or wherever you like
   $ git clone https://github.com/jfasch/FH-ECE21.git
   $ cd ~/FH-ECE21
   $ git submodule init
   $ git submodule update

Build
-----

Create build directory for Intel architecture (``x86_64``)

.. code-block:: console

   $ mkdir ~/FH-ECE21-x86_64      # or wherever you like
   $ cd ~/FH-ECE21-x86_64
   $ cmake ~/FH-ECE21
   $ make

Test

.. code-block:: console

   $ ./livehacking/hello 
   Hello World

.. code-block:: console

   $ ./tests/test-suite 
   Running main() from /home/jfasch/tmp/FH-ECE21/googletest/googletest/src/gtest_main.cc
   [==========] Running 1 test from 1 test suite.
   [----------] Global test environment set-up.
   [----------] 1 test from test_suite
   [ RUN      ] test_suite.basic
   /home/jfasch/tmp/FH-ECE21/tests/fail.cpp:6: Failure
   Failed
   
   [  FAILED  ] test_suite.basic (0 ms)
   [----------] 1 test from test_suite (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 1 test from 1 test suite ran. (0 ms total)
   [  PASSED  ] 0 tests.
   [  FAILED  ] 1 test, listed below:
   [  FAILED  ] test_suite.basic
   
    1 FAILED TEST
   
