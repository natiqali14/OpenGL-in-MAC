#pragma once
#include "../includes.h"
#include "Events.h"

class IEventHandler;
class EventSystem {
public:

    void initialise();
    
    void subscribe(EventType type, std::shared_ptr<IEventHandler> event_handle);
    void unsubscribe(EventType type, std::shared_ptr<IEventHandler> event_handle);
    void trigger_event(EventType type, IEvent* event_data);
    void dispatch_events();
    void queue_events(EventType type, IEvent* event_data);
    void shut_down();
private:
    std::unordered_map<EventType,std::vector<u32>> PFN_to_trigger;
    std::unordered_map<u32, std::shared_ptr<IEventHandler>> event_handler_map;
    // may be we need multiple Qs 
    // push events than need more time to process to high priority
    // and have another Q for low priority tasks (some light tasks).
    // may be use multithreading on events Q that is only changing / depend on cpu code
    // and run one other Q on main thread that is changing / performing some GPU code.
    std::queue<std::pair<EventType, IEvent*>> events_queue; /// right now there is only 1 Q running on main thread.
};