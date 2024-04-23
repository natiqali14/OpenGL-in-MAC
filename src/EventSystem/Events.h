#pragma once

#include "../includes.h"
enum EventType : u16 {
    EVENTTYPE_NONE,
    EVENTTYPE_KEY_PRESSED,
    EVENTTYPE_KEY_RELEASED,
    EVENTTYPE_MOUSE_MOVED,
    EVENTTYPE_MOUSE_BUTTON_PRESSED,
    EVENTTYPE_MOUSE_BUTTON_RELEASED,
    EVENTTYPE_MOUSE_SCROLLED,
};

class IEvent {
    bool b_handled;
public:
    IEvent(){std::cout << "Event constructed" << "\n";}
    virtual EventType get_type() const = 0;
    bool is_handled() const {return b_handled;}
    void set_handled_flag(bool b_flag) {b_handled = b_flag;}
    virtual ~IEvent() {std::cout << "Event destructed" << "\n";}
};


class KeyPressedEvent : public IEvent {
    int key_code;
public:
    KeyPressedEvent(int code)
    : IEvent()
    , key_code(code) {}
    int get_key_code() const {return key_code;}
    EventType get_type() const override {return EVENTTYPE_KEY_PRESSED;}
};


class KeyReleasedEvent : public IEvent {
    int key_code;
public:
    KeyReleasedEvent(int code)
    : IEvent()
    , key_code(code) {}
    int get_key_code() const {return key_code;}
    EventType get_type() const override {return EVENTTYPE_KEY_RELEASED;}
};

class KeyMouseMoved : public IEvent {
    u16 x_val;
    u16 y_val;
public:
    KeyMouseMoved(u16 x, u16 y)
    : IEvent()
    , x_val(x)
    , y_val(y) {}

    std::array<u16, 2> get_values() const {return {x_val, y_val};}
    EventType get_type() const override {return EVENTTYPE_MOUSE_MOVED;}

};
