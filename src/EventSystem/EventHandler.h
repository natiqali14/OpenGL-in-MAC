#include "../includes.h"
#include "Events.h"

class IEventHandler {
public:
    virtual void call(IEvent* e) = 0;
    virtual u32 get_uid() = 0;
    virtual ~IEventHandler() = default;
};

template <typename T>
class EventHandler : public IEventHandler {
    using EventType = T;
    using handler = std::function<void(EventType* e_type)>;
    handler e_handler;
    u32 uid;
    void set_uid() {
        static u32 id = 0;
        uid = id;
        id++;
    }
public:

    EventHandler() = default;
    EventHandler(handler h) : e_handler(h) {
        set_uid();
    }
    void call(IEvent* e) override {
        e_handler(static_cast<EventType*>(e));
    }
    u32 get_uid() override {
        return uid;
    }
    ~EventHandler() = default;
    
};