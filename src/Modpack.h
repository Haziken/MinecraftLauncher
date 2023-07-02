#pragma once 

#include <vector>
#include <string>

#include <nlohmann/json.hpp>

#define MODPACK Modpack::instance()

class Modpack
{
public:
    static Modpack& instance();

    bool InstallModpack(std::string pathToArchive);
    bool DeleteModpack();

    ~Modpack();
private:
    Modpack();
    Modpack(const Modpack&) = delete;
    Modpack(Modpack&&) = delete;

    Modpack& operator=(const Modpack&) = delete;
    Modpack& operator=(Modpack&&) = delete;

    using json = nlohmann::json;

    json installing;
};