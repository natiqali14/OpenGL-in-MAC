#include "CameraSystem.h"
#include "../EventSystem/EventSystemHelper.h"

CameraSystem::CameraSystem()
: key_press_handler (std::make_shared<EventHandler<KeyPressedEvent>>
   (EventHandler<KeyPressedEvent>([this](KeyPressedEvent* e) { onKeyPress(e); })))
, key_release_handler (std::make_shared<EventHandler<KeyReleasedEvent>>
   (EventHandler<KeyReleasedEvent>([this](KeyReleasedEvent* e) { on_key_release(e); })))
{
    EventSystemHelper::subscribe(EVENTTYPE_KEY_PRESSED, key_press_handler);
    EventSystemHelper::subscribe(EVENTTYPE_KEY_RELEASED, key_release_handler);
}

    

void CameraSystem::onKeyPress(KeyPressedEvent* event)
{
    std::cout << event->get_key_code() << "\n";
    u32 key = event->get_key_code();
    if(key == )
    event->set_handled_flag(true);
}

void CameraSystem::on_key_release(KeyReleasedEvent* event)
{
     std::cout << event->get_key_code() << "\n";
     event->set_handled_flag(true);
}
