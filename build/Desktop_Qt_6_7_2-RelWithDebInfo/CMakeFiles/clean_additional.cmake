# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles/cat_game_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/cat_game_autogen.dir/ParseCache.txt"
  "cat_game_autogen"
  )
endif()
