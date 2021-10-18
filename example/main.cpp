import vulkan;

import <vector>;

constexpr void check_success(VkResult vkResult)
{
    if(vkResult)
    {
        throw std::runtime_error("Bad VkResult");
    }
}

int main()
{
    VkApplicationInfo applicaionInfo = { VK_STRUCTURE_TYPE_APPLICATION_INFO };
    applicaionInfo.apiVersion = VK_API_VERSION_1_2;

    VkInstanceCreateInfo instanceCreateInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
    instanceCreateInfo.pApplicationInfo = &applicaionInfo;

    VkInstance instance;
    check_success(vkCreateInstance(&instanceCreateInfo, nullptr, &instance));

    uint32_t numPhysicalDevices;
    check_success(vkEnumeratePhysicalDevices(instance, &numPhysicalDevices, nullptr));
    std::vector<VkPhysicalDevice> physicalDevices(numPhysicalDevices);
    check_success(vkEnumeratePhysicalDevices(instance, &numPhysicalDevices, physicalDevices.data()));

    VkDeviceCreateInfo deviceCreateInfo = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO };

    VkDevice device;
    check_success(vkCreateDevice(physicalDevices[0], &deviceCreateInfo, nullptr, &device));

    vkDestroyDevice(device, nullptr);
    vkDestroyInstance(instance, nullptr);
}
