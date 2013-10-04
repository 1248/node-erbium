Node.js bindings for Erbium CoAP library
========================================

Toby Jaffey <toby@1248.io>
https://github.com/1248/node-erbium
http://1248.io

    var erbium = require('node-erbium');
    var pkt = new erbium.Erbium(erbium.COAP_TYPE_CON, erbium.CONTENT_2_05, 0x1234);
    pkt.setPayload("Hello world");
    var buf = pkt.serialize();
    console.log(buf);

    var parsed = new erbium.Erbium(buf);
    console.log(parsed.getPayload());

 
See src/erbium.cc for API.

Methods:

    serialize
    getHeaderMID
    getHeaderContentType
    setHeaderContentType
    getHeaderAccept
    setHeaderAccept
    getHeaderMaxAge
    setHeaderMaxAge
    getHeaderETag
    setHeaderETag
    getHeaderIfMatch
    setHeaderIfMatch
    getHeaderIfNoneMatch
    setHeaderIfNoneMatch
    getHeaderToken
    setHeaderToken
    getHeaderProxyUri
    setHeaderProxyUri
    getHeaderUriHost
    setHeaderUriHost
    getHeaderUriPath
    setHeaderUriPath
    getHeaderUriQuery
    setHeaderUriQuery
    getHeaderLocationPath
    setHeaderLocationPath
    getHeaderLocationQuery
    setHeaderLocationQuery
    getHeaderObserve
    setHeaderObserve
    getHeaderSize
    setHeaderSize
    setPayload
    getPayload
    getHeaderStatusCode
    setHeaderStatusCode
    getHeaderType
    setHeaderType


MIT license.

