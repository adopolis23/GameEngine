#include <Engine.h>


class Sandbox : public Engine::Application
{
    public:
        Sandbox() {};
        ~Sandbox() {};
            
    private:
};


Engine::Application* Engine::CreateApplication()
{
    return new Sandbox();
}
