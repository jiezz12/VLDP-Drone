#pragma once

namespace vldp
{

template<typename T>
class Singleton
{
public:

    static T& Instance()
    {
        static T instance;
        return instance;
    }

protected:

    Singleton() = default;

private:

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

}