cmake_minimum_required(VERSION 2.8)

SET("VERILATOR_DIR" "/usr/share/verilator/include")
SET("VERILATOR_LOCAL_DIR" "/mnt/AE06F37906F3413F/University/Academic/065-538-720-GNC/Kaveesha/Testing_load_unit/LoadUnit/obj_dir")

include_directories(${VERILATOR_DIR})
link_directories(${VERILATOR_DIR})

include_directories(${VERILATOR_LOCAL_DIR})
link_directories(${VERILATOR_LOCAL_DIR})

target_link_libraries( test_bench_load_unit ${VERILATOR_LOCAL_DIR} )

project( test_bench_load_unit.cpp )
add_executable( test_bench_load_unit test_bench_load_unit.cpp )
