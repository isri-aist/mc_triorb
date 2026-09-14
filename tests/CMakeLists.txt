if(TARGET triorb)
  set(ROBOT_MODULE_PARAMS "\"triorb\"")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/loader.in.cpp"
                 "${CMAKE_CURRENT_BINARY_DIR}/triorb/loader.cpp")
  add_executable(loader_triorb "${CMAKE_CURRENT_BINARY_DIR}/triorb/loader.cpp")
  target_link_libraries(loader_triorb PUBLIC mc_rtc::mc_rbdyn)
  add_test(NAME loader_triorb COMMAND loader_triorb "$<TARGET_FILE_DIR:triorb>")
endif()
