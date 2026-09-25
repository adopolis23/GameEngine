#pragma once

#include <utility>

namespace Engine
{


    class Input
    {

    public:
        static inline int GetKeyPressed()
        {
            return mInstance->GetKeyPressedImpl();
        }

        static inline std::pair<float, float> GetMousePosition()
        {
            return mInstance->GetMousePositionImpl();
        }

        static inline float GetMouseX() { return mInstance->GetMouseXImpl(); }
        static inline float GetMouseY() { return mInstance->GetMouseYImpl(); }


    protected:
        // Implementations, To be defined in derived classes
        virtual int GetKeyPressedImpl() = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;


    private:
        // Instance of singleton class
        static Input* mInstance;


    };







};

