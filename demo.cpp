
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>

void demoBufferCReadFile(){
    char buffer[1024];
    FILE * stream;

    stream = fopen("input.txt", "r");
    int count = fread(buffer, sizeof(char), 100, stream);
    fclose(stream);
    printf("Read %d characters\n", count);
    printf("Buffer: %s\n", buffer);

}
void demoBufferCppReadFile() {
    std::string in_file_name = "input.txt";
    std::string line;

    std::ifstream in_file(in_file_name);

    int buf_size = 4096;
    char buffer[buf_size];

    while(in_file.read(buffer, buf_size)){

        std::cout << buffer << std::endl;
        for(int i =0; i < buf_size; i++){
            buffer[i] = ' ';
        }
    }
    in_file.read(buffer, buf_size);
    std::cout << buffer << std::endl;



}

int main(){
    auto start = std::chrono::steady_clock::now();
    demoBufferCReadFile();
    auto end = std::chrono::steady_clock::now();
    std::cout << "C Read File: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;
}