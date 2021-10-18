import vulkan;
import <stdexcept>;

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

    vkDestroyInstance(instance, nullptr);
}
