#ifndef YZ_PLUGIN_H
#define YZ_PLUGIN_H

// C 风格接口，确保 ABI 稳定
#ifdef __cplusplus
extern "C" {
#endif

// 插件句柄
typedef void* yz_plugin_t;

// 插件信息
typedef struct {
    const char* name;
    int version_major;
    int version_minor;
    int version_patch;
    const char* description;
} yz_plugin_info_t;

// 插件生命周期函数
typedef yz_plugin_t (*yz_create_plugin_func)();
typedef void (*yz_destroy_plugin_func)(yz_plugin_t plugin);
typedef int (*yz_init_plugin_func)(yz_plugin_t plugin);
typedef void (*yz_shutdown_plugin_func)(yz_plugin_t plugin);
typedef const yz_plugin_info_t* (*yz_get_plugin_info_func)();

// 插件导出函数名称（固定，便于内核查找）
#define YZ_CREATE_PLUGIN_FUNC_NAME "yz_create_plugin"
#define YZ_DESTROY_PLUGIN_FUNC_NAME "yz_destroy_plugin"
#define YZ_INIT_PLUGIN_FUNC_NAME "yz_init_plugin"
#define YZ_SHUTDOWN_PLUGIN_FUNC_NAME "yz_shutdown_plugin"
#define YZ_GET_PLUGIN_INFO_FUNC_NAME "yz_get_plugin_info"

#ifdef __cplusplus
}
#endif

#endif // YZ_PLUGIN_H
