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

#include <EssexEngineFileSystemDriver/FileSystemFileBuffer.h>

EssexEngine::Drivers::FileSystem::FileSystemFileBuffer::FileSystemFileBuffer(std::string _filename, char* _data, uint64_t _size) {
    filename = _filename;
    data = _data;
    size = _size;
}
EssexEngine::Drivers::FileSystem::FileSystemFileBuffer::~FileSystemFileBuffer() {}

void* EssexEngine::Drivers::FileSystem::FileSystemFileBuffer::GetBuffer() {
    return data;
}
uint64_t EssexEngine::Drivers::FileSystem::FileSystemFileBuffer::GetSize() {
    return size;
}
std::string EssexEngine::Drivers::FileSystem::FileSystemFileBuffer::GetFileName() {
    return filename;
}
