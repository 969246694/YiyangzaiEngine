# 内核库
add_library(yz_core STATIC
    core/engine.cpp
    bus/event_bus.cpp
    loader/plugin_loader.cpp
)

target_include_directories(yz_core PUBLIC /include)

# 可执行文件（启动器）
add_executable(yz_launcher main.cpp)
target_link_libraries(yz_launcher yz_core)

# 平台相关链接
if(WIN32)
    target_link_libraries(yz_launcher dbghelp) # Windows 调试帮助
elseif(APPLE)
    # macOS 特定设置
elseif(UNIX)
    target_link_libraries(yz_launcher dl) # Linux 动态库加载需要 dl
endif()
