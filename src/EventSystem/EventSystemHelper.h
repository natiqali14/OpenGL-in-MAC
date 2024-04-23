#include "../includes.h"
#include "Events.h"

class IEventHandler;
namespace EventSystemHelper {
    void initialise();
    void subscribe(EventType type, std::shared_ptr<IEventHandler> event_handle);
    void unsubscribe(EventType type, std::shared_ptr<IEventHandler> event_handle);
    void trigger_event(EventType type, IEvent* event_data);
    void dispatch_events();
    void queue_events(EventType type, IEvent* event_data);
    void shut_down();
}