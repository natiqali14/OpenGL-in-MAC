#include "EventSystemHelper.h"
#include "EventSystem.h"
static EventSystem* event_system = nullptr;

void EventSystemHelper::initialise()
{
    event_system = new EventSystem;
    event_system->initialise();
}

void EventSystemHelper::subscribe(EventType type, std::shared_ptr<IEventHandler> event_handle)
{
    event_system->subscribe(type,event_handle);
}

void EventSystemHelper::unsubscribe(EventType type, std::shared_ptr<IEventHandler> event_handle)
{
    event_system->unsubscribe(type, event_handle);
}

void EventSystemHelper::trigger_event(EventType type, IEvent* event_data)
{
    event_system->trigger_event(type, event_data);
}

void EventSystemHelper::dispatch_events()
{
    event_system->dispatch_events();
}

void EventSystemHelper::queue_events(EventType type, IEvent* event_data)
{
    event_system->queue_events(type, event_data);
}

void EventSystemHelper::shut_down()
{
    event_system->shut_down();
    delete event_system;
    event_system = nullptr;
}
