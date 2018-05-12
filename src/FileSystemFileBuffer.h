/* 
 * Essex Engine
 * 
 * Copyright (C) 2018 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <EssexEngineFileSystemDaemon/IFileSystemDriver.h>

namespace EssexEngine{
namespace Drivers{
namespace FileSystem{
    class FileSystemFileBuffer:public Daemons::FileSystem::IFileBuffer {
    public:
        FileSystemFileBuffer(std::string _filename, char* _data, uint64_t _size);
        ~FileSystemFileBuffer();
        
        std::string GetFileName() override;
        void* GetBuffer() override;
        uint64_t GetSize() override;
    private:
        std::string filename;
        char* data;
        uint64_t size;
    };
}}};
