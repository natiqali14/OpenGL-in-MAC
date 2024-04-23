#include "EventSystem.h"
#include "EventHandler.h"
void EventSystem::initialise()
{
    
}


void EventSystem::subscribe(EventType type, std::shared_ptr<IEventHandler> event_handle)
{
     if(PFN_to_trigger.count(type)) {
        PFN_to_trigger[type].push_back(event_handle->get_uid());
        event_handler_map.insert({event_handle->get_uid(),event_handle});
    }
    else {
        std::vector<u32> uid_list;
        uid_list.push_back(event_handle->get_uid());
        PFN_to_trigger.insert({type, uid_list});
        event_handler_map.insert({event_handle->get_uid(),event_handle});
    }
    
}

void EventSystem::unsubscribe(EventType type, std::shared_ptr<IEventHandler> event_handle)
{
    if(PFN_to_trigger.count(type)) {
        u32 id = event_handle->get_uid();
        auto& id_list = PFN_to_trigger[type];

        for(int i = 0; i < id_list.size(); i++) {
            if(id_list[i] == id){
                id_list.erase(id_list.begin() + i);   // deleted the uid from map PFN_to_trigger
                event_handler_map.erase(id);   // delete the event handler object.
            } 
        }
    }
}

void EventSystem::trigger_event(EventType type, IEvent* event_data)
{
    if(!PFN_to_trigger.count(type)) return;
    for(auto& PFN_handle : event_handler_map) {
        PFN_handle.second->call(event_data);
    }
}

void EventSystem::dispatch_events()
{
    while(!events_queue.empty()) {
        auto queue_event_data = events_queue.front();
        trigger_event(queue_event_data.first, queue_event_data.second);
        if(queue_event_data.second->is_handled()) {
            events_queue.pop();
            delete queue_event_data.second;

        }
    }
}

void EventSystem::queue_events(EventType type,  IEvent* event_data)
{
    events_queue.push({type, event_data});
}

void EventSystem::shut_down()
{
    PFN_to_trigger.clear();
    event_handler_map.clear();
    events_queue = {};
}
