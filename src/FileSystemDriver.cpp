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

#include <EssexEngineFileSystemDriver/FileSystemDriver.h>

EssexEngine::Drivers::FileSystem::FileSystemDriver::FileSystemDriver(WeakPointer<Context> _context): BaseDriver(_context) {
    char buffer[512];
    char *answer = getcwd(buffer, sizeof(buffer));
    if (answer)
    {
        cwd = answer;
    }
}

EssexEngine::Drivers::FileSystem::FileSystemDriver::~FileSystemDriver() {}

//IFileSystemDriver
void EssexEngine::Drivers::FileSystem::FileSystemDriver::LoadZipArchive(std::string filepath) {}

void EssexEngine::Drivers::FileSystem::FileSystemDriver::CloseZipArchive() {}

EssexEngine::WeakPointer<EssexEngine::Daemons::FileSystem::IFileBuffer> EssexEngine::Drivers::FileSystem::FileSystemDriver::ReadFile(std::string filename) {
    std::string newfilename = cwd + "/" + filename;
    FILE *fp = fopen(newfilename.c_str(), "rb");
    
    //get file size.
    fseek(fp, 0L, SEEK_END);
    long lSize = ftell(fp);
    rewind(fp);
    
    /* allocate memory for entire content */
    char* buffer = new char[lSize];
    
    /* copy the file into the buffer */
    fread(buffer, lSize, 1, fp);
    fclose(fp);
    
    return WeakPointer<FileSystemFileBuffer>(new FileSystemFileBuffer(filename, buffer, int(lSize))).Cast<Daemons::FileSystem::IFileBuffer>();
}

void EssexEngine::Drivers::FileSystem::FileSystemDriver::SaveFile(std::string filename, void* data, uint64_t size) {
    std::string newfilename = cwd + "/" + filename;
    FILE* fp = fopen(newfilename.c_str(),"w");
    
    /*Create a file and add text*/
    if(fp!=NULL) {
        fwrite (data, sizeof(char), size, fp);
    }
    
    fclose(fp);
}
