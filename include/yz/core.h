#ifndef YZ_CORE_H
#define YZ_CORE_H

namespace yz {

// 引擎版本
struct Version {
    int major;
    int minor;
    int patch;
};

// 获取引擎版本
inline Version GetVersion() {
    return {0, 1, 0};
}

} // namespace yz

#endif // YZ_CORE_H
