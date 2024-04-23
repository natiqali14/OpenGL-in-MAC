#include "../includes.h"
#include "../EventSystem/Events.h"
#include "../EventSystem/EventHandler.h"
class CameraSystem {
public:
    CameraSystem();
    ~CameraSystem() = default; // for now
    void onKeyPress(KeyPressedEvent* event);
    void on_key_release(KeyReleasedEvent* event);
private:
    std::shared_ptr<EventHandler<KeyPressedEvent>> key_press_handler;
    std::shared_ptr<EventHandler<KeyReleasedEvent>> key_release_handler;

};