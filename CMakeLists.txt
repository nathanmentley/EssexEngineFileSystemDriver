#files

file(GLOB EssexEngineFileSystemDriver_HEADERS
    "src/Drivers/FileSystemDriver/*.h"
)
file(GLOB EssexEngineFileSystemDriver_SRC
    ${EssexEngineFileSystemDriver_HEADERS}
    "src/Drivers/FileSystemDriver/*.cpp"
)

#setup headers

file(COPY ${EssexEngineFileSystemDriver_HEADERS} DESTINATION "${CMAKE_BINARY_DIR}/lib/include/EssexEngineFileSystemDriver/")

#setup build

add_library(EssexEngineFileSystemDriver SHARED ${EssexEngineFileSystemDriver_SRC})
target_link_libraries(EssexEngineFileSystemDriver EssexEngineCore)
target_link_libraries(EssexEngineFileSystemDriver EssexEngineFileSystemDaemon)