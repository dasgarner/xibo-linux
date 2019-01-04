#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include "field.hpp"
#include "soap.hpp"

namespace Schedule
{
    struct response
    {
        std::string scheduleXml;
    };

    struct request
    {
        Field<std::string> serverKey{"serverKey"};
        Field<std::string> hardwareKey{"hardwareKey"};
    };
}

template<>
struct soap::request_traits<Schedule::request>
{
    static inline const std::string name = "Schedule";
    using response_t = Schedule::response;
};


#endif // SCHEDULE_HPP