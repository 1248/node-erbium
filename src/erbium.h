#ifndef ERBIUM_H
#define ERBIUM_H

#include <node.h>
extern "C" {
    #include "er-coap-13.h"
}

class Erbium : public node::ObjectWrap {
    public:
    static void Init(v8::Handle<v8::Object> target);

    private:
    Erbium();
    ~Erbium();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> Serialize(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderMID(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderContentType(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderContentType(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderAccept(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderAccept(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderMaxAge(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderMaxAge(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderETag(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderETag(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderIfMatch(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderIfMatch(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderIfNoneMatch(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderIfNoneMatch(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderToken(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderToken(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderProxyUri(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderProxyUri(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderUriHost(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderUriHost(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderUriPath(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderUriPath(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderUriQuery(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderUriQuery(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderLocationPath(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderLocationPath(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderLocationQuery(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderLocationQuery(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderObserve(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderObserve(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderSize(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderSize(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetPayload(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetPayload(const v8::Arguments& args);
    static v8::Handle<v8::Value> SetHeaderStatusCode(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderStatusCode(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetHeaderType(const v8::Arguments& args);

    coap_packet_t pkt_;
};

#endif
