# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\ScannerApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ScannerApp_autogen.dir\\ParseCache.txt"
  "ScannerApp_autogen"
  )
endif()
