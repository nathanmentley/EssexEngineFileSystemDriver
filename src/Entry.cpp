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

#include <EssexEngineFileSystemDriver/FileSystemDriver.h>

using EssexEngine::Context;
using EssexEngine::WeakPointer;

using EssexEngine::Drivers::FileSystem::FileSystemDriver;
using EssexEngine::Daemons::FileSystem::IFileSystemDriver;

extern "C" {
    void driver_init(WeakPointer<Context> context) {
        context->RegisterDriver<IFileSystemDriver>(
            WeakPointer<IFileSystemDriver>(new FileSystemDriver(context)) 
        );
    }
}
