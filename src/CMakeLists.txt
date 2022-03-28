cmake_minimum_required( VERSION 3.16.3 )

set( MAIN_EXEC_NAME dictionary )

execute_process( COMMAND pg_config --includedir OUTPUT_VARIABLE PG_CONFIG_INCLUDEDIR )

add_definitions( -DBOOST_LOG_DYN_LINK )
find_package( Boost REQUIRED COMPONENTS date_time log filesystem )
find_package( SOCI REQUIRED )

# Create main executable
add_executable( ${MAIN_EXEC_NAME} main.cpp )

target_compile_features( ${MAIN_EXEC_NAME} PRIVATE cxx_std_17 )

target_include_directories( ${MAIN_EXEC_NAME} PRIVATE ${SOCI_INCLUDE_DIRS} )
target_include_directories( ${MAIN_EXEC_NAME} PRIVATE ${PG_CONFIG_INCLUDEDIR} )

target_link_libraries( ${MAIN_EXEC_NAME} PRIVATE boost_filesystem )
target_link_libraries( ${MAIN_EXEC_NAME} PRIVATE boost_log )
target_link_libraries( ${MAIN_EXEC_NAME} PRIVATE SOCI::soci_core )
target_link_libraries( ${MAIN_EXEC_NAME} PRIVATE SOCI::soci_postgresql )
