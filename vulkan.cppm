export module vulkan;

// UNDEFINED BEHAVIOUR: A translation unit shall not #define or #undef names lexically identical to keywords
// Justification: `module` is used as an identifier by vulkan.h, but it is a keyword in module files
#define module _module
// Justification: variables with internal linkage (i.e. static) are not allowed as module exports
#define static constexpr

export {
#include <vulkan/vulkan.h>  

#undef VK_NULL_HANDLE
constexpr auto VK_NULL_HANDLE = nullptr;

#undef VK_MAKE_API_VERSION
constexpr uint32_t VK_MAKE_API_VERSION(uint32_t variant, uint32_t major, uint32_t minor, uint32_t patch)
{
    return ((variant << 29)
        |   (major   << 22)
        |   (minor   << 12)
        |   (patch   <<  0));
}

#undef VK_API_VERSION_VARIANT
constexpr uint32_t VK_API_VERSION_VARIANT(uint32_t version)
{
    return version >> 29;
}

#undef VK_API_VERSION_MAJOR
constexpr uint32_t VK_API_VERSION_MAJOR(uint32_t version)
{
    return (version >> 22) & 0x7F;
}

#undef VK_API_VERSION_MINOR
constexpr uint32_t VK_API_VERSION_MINOR(uint32_t version)
{
    return (version >> 12) & 0x3FF;
}

#undef VK_API_VERSION_PATCH
constexpr uint32_t VK_API_VERSION_PATCH(uint32_t version)
{
    return version & 0xFFF;
}

#undef VK_API_VERSION_1_0
constexpr auto VK_API_VERSION_1_0 = VK_MAKE_API_VERSION(0, 1, 0, 0);

#undef VK_API_VERSION_1_1
constexpr auto VK_API_VERSION_1_1 = VK_MAKE_API_VERSION(0, 1, 1, 0);

#undef VK_API_VERSION_1_2
constexpr auto VK_API_VERSION_1_2 = VK_MAKE_API_VERSION(0, 1, 2, 0);

#undef VK_UUID_SIZE
constexpr size_t VK_UUID_SIZE = 16;

#undef VK_ATTACHMENT_UNUSED
constexpr uint32_t VK_ATTACHMENT_UNUSED = ~0U;

#undef VK_FALSE
constexpr VkBool32 VK_FALSE = 0;

#undef VK_LOD_CLAMP_NONE
constexpr float VK_LOD_CLAMP_NONE = 1000.0f;

#undef VK_QUEUE_FAMILY_IGNORED
constexpr uint32_t VK_QUEUE_FAMILY_IGNORED = ~0U;

#undef VK_REMAINING_ARRAY_LAYERS
constexpr uint32_t VK_REMAINING_ARRAY_LAYERS = ~0U;

#undef VK_REMAINING_MIP_LEVELS
constexpr uint32_t VK_REMAINING_MIP_LEVELS = ~0U;

#undef VK_SUBPASS_EXTERNAL
constexpr uint32_t VK_SUBPASS_EXTERNAL = ~0U;

#undef VK_TRUE
constexpr VkBool32 VK_TRUE = 1;

#undef VK_WHOLE_SIZE
constexpr VkDeviceSize VK_WHOLE_SIZE = ~0U;

#undef VK_MAX_MEMORY_TYPES
constexpr uint32_t VK_MAX_MEMORY_TYPES = 32;

#undef VK_MAX_MEMORY_HEAPS
constexpr uint32_t VK_MAX_MEMORY_HEAPS = 16;

#undef VK_MAX_PHYSICAL_DEVICE_NAME_SIZE
constexpr size_t VK_MAX_PHYSICAL_DEVICE_NAME_SIZE = 256;

#undef VK_MAX_EXTENSION_NAME_SIZE
constexpr size_t VK_MAX_EXTENSION_NAME_SIZE = 256;

#undef VK_MAX_DESCRIPTION_SIZE
constexpr size_t VK_MAX_DESCRIPTION_SIZE = 256;

}

#undef static
#undef module
