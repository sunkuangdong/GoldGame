# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CoinFilp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CoinFilp_autogen.dir\\ParseCache.txt"
  "CoinFilp_autogen"
  )
endif()
