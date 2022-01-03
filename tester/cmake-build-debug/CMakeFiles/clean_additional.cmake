# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\tester_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tester_autogen.dir\\ParseCache.txt"
  "tester_autogen"
  )
endif()
