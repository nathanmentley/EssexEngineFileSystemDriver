/* 
 * Essex Engine
 * 
 * Copyright (C) 2017 Nathan Mentley - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the BSD license.
 *
 * You should have received a copy of the BSD license with
 * this file. If not, please visit: https://github.com/nathanmentley/EssexEngine
 */
#pragma once

#include <unistd.h>
#include <fstream>

#include <EssexEngineCore/BaseDriver.h>
#include <EssexEngineCore/LogDaemon.h>
#include <EssexEngineCore/Context.h>
#include <EssexEngineFileSystemDaemon/IFileSystemDriver.h>

#include <EssexEngineFileSystemDriver/FileSystemFileBuffer.h>

namespace EssexEngine{
namespace Drivers{
namespace FileSystem{
    class FileSystemDriver:public Core::Drivers::Base::BaseDriver, public Daemons::FileSystem::IFileSystemDriver
    {
    public:
        FileSystemDriver(WeakPointer<Context> _context);
        ~FileSystemDriver();
        
        //IDriver
        void Init() {
            if(GetContext()->HasDaemon<Core::Logging::LogDaemon>()) {
                GetContext()->GetDaemon<Core::Logging::LogDaemon>()->LogLine(
                    "Loading Driver [%s] [%s]",
                    GetDriverName().c_str(),
                    GetDriverVersion().c_str()
                );
            }
        }
        
        //IFileSystemDriver
        void LoadZipArchive(std::string filepath);
        void CloseZipArchive();
        WeakPointer<Daemons::FileSystem::IFileBuffer> ReadFile(std::string filename);
        void SaveFile(std::string filename, void* data, uint64_t size);
        
        //BaseDriver
        std::string GetDriverName() { return "File System"; }
        std::string GetDriverVersion() { return ESSEX_ENGINE_VERSION; }
    private:
        std::string cwd;
    };
}}};
