################################################################################
#
# Example programs using Aquila
#
################################################################################

include_directories("${CMAKE_SOURCE_DIR}")


# a common setup for most of the examples
macro(aquila_example example)
  add_executable(${example} EXCLUDE_FROM_ALL ${example}.cpp)
  add_dependencies(examples ${example})
  target_link_libraries(${example} Aquila)
endmacro(aquila_example)


add_subdirectory(utility_functions)

add_subdirectory(frame_iteration)

add_subdirectory(wave_info)
add_subdirectory(wave_iteration)
add_subdirectory(window_plot)
add_subdirectory(window_usage)

add_subdirectory(text_plot)

add_subdirectory(sine_generator)
add_subdirectory(square_generator)
add_subdirectory(triangle_generator)
add_subdirectory(generators)

add_subdirectory(am_modulation)

add_subdirectory(fft_comparison)
add_subdirectory(fft_simple_spectrum)
add_subdirectory(fft_filter)
add_subdirectory(spectrogram)
add_subdirectory(mfcc_calculation)
add_subdirectory(dtw_path_recovery)

add_subdirectory(workshop)
