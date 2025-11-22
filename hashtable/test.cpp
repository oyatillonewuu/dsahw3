#include <iostream>
#include "src.h"

int main(void) {
    MadCompression mad_compressor(13, 23);
    NaiveCompression naive_compressor;

    HashTable h1(11, 33, naive_compressor); 
    HashTable h2(13, 33, mad_compressor); 

    std::cout << "Is Hello in h1?\n>> " << h1.find("Hello") << std::endl;
    h1.insert("Hello");
    std::cout << "Is Hello in h1?\n>> " << h1.find("Hello") << std::endl;
    std::cout << "Is hello in h2?\n>> " << h2.find("hello") << std::endl;
    h2.insert("hello");
    std::cout << "Is hello in h2?\n>> " << h2.find("hello") << std::endl;

    h1.insert("World!");
    h1.insert("Cool!");
    h1.insert("C++");
    h1.insert("Py3");
    h1.insert("Py2");
    h1.insert("Rust");
    h1.insert("Haskell");
    h1.insert("C#");
    h1.insert("Php");
    h1.insert("Scala");
    h1.insert("Elixir");
    h1.displayKeys();
    h1.displayMaxCollisionBucket();

    return 0;
}
