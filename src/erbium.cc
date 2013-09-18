#include <string>
#include <node.h>
#include <node_buffer.h>
#include <node_version.h>
#include "erbium.h"

extern "C" {
#include "er-coap-13.h"
}

using namespace node;
using namespace v8;

Erbium::Erbium() {};
Erbium::~Erbium() {};

void Erbium::Init(Handle<Object> target) {
    // Prepare constructor template
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("Erbium"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    // Prototype

#define DEFINE_METHOD(X, Y) \
    tpl->PrototypeTemplate()->Set(String::NewSymbol(X), FunctionTemplate::New(Y)->GetFunction());

    DEFINE_METHOD("serialize", Serialize);
    DEFINE_METHOD("getHeaderMID", GetHeaderMID);
    DEFINE_METHOD("getHeaderContentType", GetHeaderContentType);
    DEFINE_METHOD("setHeaderContentType", SetHeaderContentType);
    DEFINE_METHOD("getHeaderAccept", GetHeaderAccept);
    DEFINE_METHOD("setHeaderAccept", SetHeaderAccept);
    DEFINE_METHOD("getHeaderMaxAge", GetHeaderMaxAge);
    DEFINE_METHOD("setHeaderMaxAge", SetHeaderMaxAge);
    DEFINE_METHOD("getHeaderETag", GetHeaderETag);
    DEFINE_METHOD("setHeaderETag", SetHeaderETag);
    DEFINE_METHOD("getHeaderIfMatch", GetHeaderIfMatch);
    DEFINE_METHOD("setHeaderIfMatch", SetHeaderIfMatch);
    DEFINE_METHOD("getHeaderIfNoneMatch", GetHeaderIfNoneMatch);
    DEFINE_METHOD("setHeaderIfNoneMatch", SetHeaderIfNoneMatch);
    DEFINE_METHOD("getHeaderToken", GetHeaderToken);
    DEFINE_METHOD("setHeaderToken", SetHeaderToken);
    DEFINE_METHOD("getHeaderProxyUri", GetHeaderProxyUri);
    DEFINE_METHOD("setHeaderProxyUri", SetHeaderProxyUri);
    DEFINE_METHOD("getHeaderUriHost", GetHeaderUriHost);
    DEFINE_METHOD("setHeaderUriHost", SetHeaderUriHost);
    DEFINE_METHOD("getHeaderUriPath", GetHeaderUriPath);
    DEFINE_METHOD("setHeaderUriPath", SetHeaderUriPath);
    DEFINE_METHOD("getHeaderUriQuery", GetHeaderUriQuery);
    DEFINE_METHOD("setHeaderUriQuery", SetHeaderUriQuery);
    DEFINE_METHOD("getHeaderLocationPath", GetHeaderLocationPath);
    DEFINE_METHOD("setHeaderLocationPath", SetHeaderLocationPath);
    DEFINE_METHOD("getHeaderLocationQuery", GetHeaderLocationQuery);
    DEFINE_METHOD("setHeaderLocationQuery", SetHeaderLocationQuery);
    DEFINE_METHOD("getHeaderObserve", GetHeaderObserve);
    DEFINE_METHOD("setHeaderObserve", SetHeaderObserve);
    DEFINE_METHOD("getHeaderSize", GetHeaderSize);
    DEFINE_METHOD("setHeaderSize", SetHeaderSize);
    DEFINE_METHOD("setPayload", SetPayload);
    DEFINE_METHOD("getPayload", GetPayload);
    DEFINE_METHOD("getHeaderStatusCode", GetHeaderStatusCode);
    DEFINE_METHOD("setHeaderStatusCode", SetHeaderStatusCode);
    DEFINE_METHOD("getHeaderType", GetHeaderType);

    // Constants
#define DEFINE_CONST(X) \
    target->Set(String::NewSymbol(#X), Number::New(X)); \
    NODE_DEFINE_CONSTANT(target, NODE_MINOR_VERSION);

    DEFINE_CONST(COAP_TYPE_CON);
    DEFINE_CONST(COAP_TYPE_NON);
    DEFINE_CONST(COAP_TYPE_ACK);
    DEFINE_CONST(COAP_TYPE_RST);
    DEFINE_CONST(COAP_GET);
    DEFINE_CONST(COAP_POST);
    DEFINE_CONST(COAP_PUT);
    DEFINE_CONST(COAP_DELETE);
    DEFINE_CONST(NO_ERROR);
    DEFINE_CONST(CREATED_2_01);
    DEFINE_CONST(DELETED_2_02);
    DEFINE_CONST(VALID_2_03);
    DEFINE_CONST(CHANGED_2_04);
    DEFINE_CONST(CONTENT_2_05);
    DEFINE_CONST(BAD_REQUEST_4_00);
    DEFINE_CONST(UNAUTHORIZED_4_01);
    DEFINE_CONST(BAD_OPTION_4_02);
    DEFINE_CONST(FORBIDDEN_4_03);
    DEFINE_CONST(NOT_FOUND_4_04);
    DEFINE_CONST(METHOD_NOT_ALLOWED_4_05);
    DEFINE_CONST(NOT_ACCEPTABLE_4_06);
    DEFINE_CONST(PRECONDITION_FAILED_4_12);
    DEFINE_CONST(REQUEST_ENTITY_TOO_LARGE_4_13);
    DEFINE_CONST(UNSUPPORTED_MEDIA_TYPE_4_15);
    DEFINE_CONST(INTERNAL_SERVER_ERROR_5_00);
    DEFINE_CONST(NOT_IMPLEMENTED_5_01);
    DEFINE_CONST(BAD_GATEWAY_5_02);
    DEFINE_CONST(SERVICE_UNAVAILABLE_5_03);
    DEFINE_CONST(GATEWAY_TIMEOUT_5_04);
    DEFINE_CONST(PROXYING_NOT_SUPPORTED_5_05);
    DEFINE_CONST(MEMORY_ALLOCATION_ERROR);
    DEFINE_CONST(PACKET_SERIALIZATION_ERROR);
    DEFINE_CONST(MANUAL_RESPONSE);
    DEFINE_CONST(COAP_OPTION_IF_MATCH);
    DEFINE_CONST(COAP_OPTION_URI_HOST);
    DEFINE_CONST(COAP_OPTION_ETAG);
    DEFINE_CONST(COAP_OPTION_IF_NONE_MATCH);
    DEFINE_CONST(COAP_OPTION_OBSERVE);
    DEFINE_CONST(COAP_OPTION_URI_PORT);
    DEFINE_CONST(COAP_OPTION_LOCATION_PATH);
    DEFINE_CONST(COAP_OPTION_URI_PATH);
    DEFINE_CONST(COAP_OPTION_CONTENT_TYPE);
    DEFINE_CONST(COAP_OPTION_MAX_AGE);
    DEFINE_CONST(COAP_OPTION_URI_QUERY);
    DEFINE_CONST(COAP_OPTION_ACCEPT);
    DEFINE_CONST(COAP_OPTION_TOKEN);
    DEFINE_CONST(COAP_OPTION_LOCATION_QUERY);
    DEFINE_CONST(COAP_OPTION_BLOCK2);
    DEFINE_CONST(COAP_OPTION_BLOCK1);
    DEFINE_CONST(COAP_OPTION_SIZE);
    DEFINE_CONST(COAP_OPTION_PROXY_URI);
    DEFINE_CONST(TEXT_PLAIN);
    DEFINE_CONST(TEXT_XML);
    DEFINE_CONST(TEXT_CSV);
    DEFINE_CONST(TEXT_HTML);
    DEFINE_CONST(IMAGE_GIF);
    DEFINE_CONST(IMAGE_JPEG);
    DEFINE_CONST(IMAGE_PNG);
    DEFINE_CONST(IMAGE_TIFF);
    DEFINE_CONST(AUDIO_RAW);
    DEFINE_CONST(VIDEO_RAW);
    DEFINE_CONST(APPLICATION_LINK_FORMAT);
    DEFINE_CONST(APPLICATION_XML);
    DEFINE_CONST(APPLICATION_OCTET_STREAM);
    DEFINE_CONST(APPLICATION_RDF_XML);
    DEFINE_CONST(APPLICATION_SOAP_XML);
    DEFINE_CONST(APPLICATION_ATOM_XML);
    DEFINE_CONST(APPLICATION_XMPP_XML);
    DEFINE_CONST(APPLICATION_EXI);
    DEFINE_CONST(APPLICATION_FASTINFOSET);
    DEFINE_CONST(APPLICATION_SOAP_FASTINFOSET);
    DEFINE_CONST(APPLICATION_JSON);
    DEFINE_CONST(APPLICATION_X_OBIX_BINARY);

    Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
    target->Set(String::NewSymbol("Erbium"), constructor);
}

Handle<Value> Erbium::New(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = new Erbium();

    if (args.Length() == 1) {
        if (!args[0]->IsObject()) {
            ThrowException(Exception::TypeError(String::New("Wrong arguments (not object)")));
            return scope.Close(Undefined());
        }
        Local<Object> bufferObj    = args[0]->ToObject();
        char*         bufferData   = Buffer::Data(bufferObj);
        size_t        bufferLength = Buffer::Length(bufferObj);

        coap_init_message(&obj->pkt_, COAP_TYPE_CON, COAP_GET, 0);  // init bodge

        // FIXME, coap_error_message isn't thread safe
        if (NO_ERROR != coap_parse_message(&obj->pkt_, (uint8_t *)bufferData, bufferLength)) {
            ThrowException(Exception::TypeError(String::New(coap_error_message)));
            return scope.Close(Undefined());
        }
    }
    else
    if (args.Length() == 3) {
        if (!args[0]->IsNumber() || !args[1]->IsNumber() || !args[2]->IsNumber()) {
            ThrowException(Exception::TypeError(String::New("Wrong arguments")));
            return scope.Close(Undefined());
        }
        coap_init_message(&obj->pkt_, (coap_message_type_t)args[0]->NumberValue(), (uint8_t)args[1]->NumberValue(), (uint16_t)args[2]->NumberValue());
    }
    else {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    obj->Wrap(args.This());
    return args.This();
}

Handle<Value> Erbium::GetHeaderMID(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(coap_get_mid(&obj->pkt_)));
}

Handle<Value> Erbium::GetHeaderType(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(coap_get_type(&obj->pkt_)));
}

Handle<Value> Erbium::SetPayload(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsObject()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }

    Local<Object> bufferObj    = args[0]->ToObject();
    char*         bufferData   = Buffer::Data(bufferObj);
    size_t        bufferLength = Buffer::Length(bufferObj);

    rc = coap_set_payload(&obj->pkt_, bufferData, bufferLength);
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetPayload(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_payload(&obj->pkt_, &data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::Serialize(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    uint8_t data[64 * 1024];
    int length;

    length = coap_serialize_message(&obj->pkt_, data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderContentType(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    coap_set_header_content_type(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderContentType(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(coap_get_header_content_type(&obj->pkt_)));
}


Handle<Value> Erbium::SetHeaderAccept(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    rc = coap_set_header_accept(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderAccept(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int count, i;
    const uint16_t *list;
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    count = coap_get_header_accept(&obj->pkt_, &list);

    Handle<Array> bufArray = v8::Array::New(count);
    for(i=0; i<count; ++i)
        bufArray->Set(i, v8::Integer::New(list[i]));

    return scope.Close(bufArray);
}

Handle<Value> Erbium::SetHeaderMaxAge(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    coap_set_header_max_age(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderMaxAge(const Arguments& args) {
    HandleScope scope;
    int rc;
    uint32_t age;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    rc = coap_get_header_max_age(&obj->pkt_, &age);
    if (rc == 1)
        return scope.Close(Number::New(age));
    else
        return scope.Close(Undefined());
}

Handle<Value> Erbium::SetHeaderETag(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsObject()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments (not object)")));
        return scope.Close(Undefined());
    }
    Local<Object> bufferObj    = args[0]->ToObject();
    char*         bufferData   = Buffer::Data(bufferObj);
    size_t        bufferLength = Buffer::Length(bufferObj);
    coap_set_header_etag(&obj->pkt_, (uint8_t *)bufferData, bufferLength);
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderETag(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_header_etag(&obj->pkt_, &data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderIfMatch(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsObject()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments (not object)")));
        return scope.Close(Undefined());
    }
    Local<Object> bufferObj    = args[0]->ToObject();
    char*         bufferData   = Buffer::Data(bufferObj);
    size_t        bufferLength = Buffer::Length(bufferObj);
    coap_set_header_if_match(&obj->pkt_, (uint8_t *)bufferData, bufferLength);
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderIfMatch(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_header_if_match(&obj->pkt_, &data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}


Handle<Value> Erbium::SetHeaderIfNoneMatch(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(coap_set_header_if_none_match(&obj->pkt_)));
}

Handle<Value> Erbium::GetHeaderIfNoneMatch(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    return scope.Close(Number::New(coap_get_header_if_none_match(&obj->pkt_)));
}

Handle<Value> Erbium::SetHeaderToken(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsObject()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments (not object)")));
        return scope.Close(Undefined());
    }
    Local<Object> bufferObj    = args[0]->ToObject();
    char*         bufferData   = Buffer::Data(bufferObj);
    size_t        bufferLength = Buffer::Length(bufferObj);
    coap_set_header_token(&obj->pkt_, (uint8_t *)bufferData, bufferLength);
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderToken(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_header_token(&obj->pkt_, &data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderProxyUri(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->proxy_str = std::string(*v8s0);
    rc = coap_set_header_proxy_uri(&obj->pkt_, obj->proxy_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderProxyUri(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_header_proxy_uri(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderUriHost(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->host_str = std::string(*v8s0);
    rc = coap_set_header_uri_host(&obj->pkt_, obj->host_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderUriHost(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    length = coap_get_header_uri_host(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);

    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderUriPath(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->path_str = std::string(*v8s0);
    rc = coap_set_header_uri_path(&obj->pkt_, obj->path_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderUriPath(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;

    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    length = coap_get_header_uri_path(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);
    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderUriQuery(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->query_str = std::string(*v8s0);
    rc = coap_set_header_uri_query(&obj->pkt_, obj->query_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderUriQuery(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;

    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    length = coap_get_header_uri_query(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);
    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderLocationPath(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->location_str = std::string(*v8s0);
    rc = coap_set_header_location_path(&obj->pkt_, obj->location_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderLocationPath(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;

    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    length = coap_get_header_location_path(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);
    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderLocationQuery(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    int rc;

    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value v8s0(args[0]->ToString());
    obj->location_query_str = std::string(*v8s0);
    rc = coap_set_header_location_query(&obj->pkt_, obj->location_query_str.c_str());
    return scope.Close(Number::New(rc));
}

Handle<Value> Erbium::GetHeaderLocationQuery(const Arguments& args) {
    HandleScope scope;
    const uint8_t *data;
    int length;

    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }

    length = coap_get_header_location_query(&obj->pkt_, (const char **)&data);
    Buffer *slowBuffer = Buffer::New(length);
    memcpy(Buffer::Data(slowBuffer), data, length);
    Local<Object> globalObj = Context::GetCurrent()->Global();
    Local<Function> bufferConstructor = Local<Function>::Cast(globalObj->Get(String::New("Buffer")));
    Handle<Value> constructorArgs[3] = { slowBuffer->handle_, v8::Integer::New(length), v8::Integer::New(0) };
    Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);
    return scope.Close(actualBuffer);
}

Handle<Value> Erbium::SetHeaderObserve(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    coap_set_header_observe(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderObserve(const Arguments& args) {
    HandleScope scope;
    int rc;
    uint32_t age;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    rc = coap_get_header_observe(&obj->pkt_, &age);
    if (rc == 1)
        return scope.Close(Number::New(age));
    else
        return scope.Close(Undefined());
}

Handle<Value> Erbium::SetHeaderSize(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    coap_set_header_size(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderSize(const Arguments& args) {
    HandleScope scope;
    int rc;
    uint32_t age;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    rc = coap_get_header_size(&obj->pkt_, &age);
    if (rc == 1)
        return scope.Close(Number::New(age));
    else
        return scope.Close(Undefined());
}

Handle<Value> Erbium::SetHeaderStatusCode(const Arguments& args) {
    HandleScope scope;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() < 1) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    if (!args[0]->IsNumber()) {
        ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
    }
    coap_set_status_code(&obj->pkt_, args[0]->NumberValue());
    return scope.Close(Undefined());
}

Handle<Value> Erbium::GetHeaderStatusCode(const Arguments& args) {
    HandleScope scope;
    uint8_t code;
    Erbium* obj = ObjectWrap::Unwrap<Erbium>(args.This());
    if (args.Length() != 0) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    code = coap_get_status_code(&obj->pkt_);
    return scope.Close(Number::New(code));
}


