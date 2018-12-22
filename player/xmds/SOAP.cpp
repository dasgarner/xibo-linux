#include "SOAP.hpp"

#include "utils/Utilities.hpp"
#include "utils/Logger.hpp"

SOAP::BaseResponseParser::BaseResponseParser(const std::string& xmlResponse)
{
    m_responseTree = parseSoapResponse(xmlResponse);
}

const boost::property_tree::ptree&SOAP::BaseResponseParser::responseTree() const
{
    return m_responseTree;
}

boost::property_tree::ptree SOAP::BaseResponseParser::parseSoapResponse(const std::string& xmlResponse)
{
    auto parsedBody = Utils::parseXmlFromString(xmlResponse).get_child("SOAP-ENV:Envelope").get_child("SOAP-ENV:Body");
    auto bodyNode = parsedBody.front().second;

    if(auto faultNode = parsedBody.get_child_optional("SOAP-ENV:Fault"))
    {
        auto faultCode = faultNode->get<std::string>("faultcode");
        auto faultMessage = faultNode->get<std::string>("faultstring");
        Log::debug("Fault Response: {} Message: {}", faultCode, faultMessage);
        return {};
    }
    return bodyNode;
}
