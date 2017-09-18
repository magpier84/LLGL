/*
 * VKShader.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015-2017 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef LLGL_VK_SHADER_H
#define LLGL_VK_SHADER_H


#include <LLGL/Shader.h>
#include "../Vulkan.h"
#include "../VKPtr.h"


namespace LLGL
{


class VKShader : public Shader
{

    public:

        VKShader(const VKPtr<VkDevice>& device, const ShaderType type);

        bool Compile(const std::string& sourceCode, const ShaderDescriptor& shaderDesc = {}) override;

        bool LoadBinary(std::vector<char>&& binaryCode, const ShaderDescriptor& shaderDesc = {}) override;

        std::string Disassemble(int flags = 0) override;

        std::string QueryInfoLog() override;

        // Returns the Vulkan shader module.
        inline const VKPtr<VkShaderModule>& GetShaderModule() const
        {
            return shaderModule_;
        }

    private:

        enum class LoadBinaryResult
        {
            Success,
            InvalidCodeSize,
        };

        VkDevice                device_             = VK_NULL_HANDLE;
        VKPtr<VkShaderModule>   shaderModule_;
        LoadBinaryResult        loadBinaryResult_   = LoadBinaryResult::Success;

};


} // /namespace LLGL


#endif



// ================================================================================