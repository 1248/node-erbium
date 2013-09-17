var erbium = require('./build/Release/erbium');

var pkt = new erbium.Erbium(new Buffer([0x60,0x45,0x04,0xd2,0xc2,0x00,0x00,0xff,0x68,0x65,0x6c,0x6c,0x6f]));

console.log(pkt.getPayload().toString());
console.log(pkt.getHeaderContentType());
console.log(pkt.getHeaderContentType());
console.log(pkt.getHeaderMID());

process.exit(0);

var obj = new erbium.Erbium(erbium.COAP_TYPE_CON, erbium.COAP_GET, 0);
/*
obj.setHeaderContentType(erbium.APPLICATION_LINK_FORMAT);

console.log(obj.getHeaderContentType(), erbium.APPLICATION_LINK_FORMAT);

obj.setHeaderAccept(erbium.TEXT_PLAIN);
obj.setHeaderAccept(erbium.APPLICATION_LINK_FORMAT);
console.log(obj.getHeaderAccept());

console.log("maxage", obj.getHeaderMaxAge());
obj.setHeaderMaxAge(10);
console.log("maxage", obj.getHeaderMaxAge());

console.log("etag", obj.getHeaderETag());
obj.setHeaderETag(new Buffer("AAA"));
console.log("etag", obj.getHeaderETag());

console.log("ifmatch", obj.getHeaderIfMatch());
obj.setHeaderIfMatch(new Buffer("AAA"));
console.log("ifmatch", obj.getHeaderIfMatch());

console.log("ifnonematch", obj.getHeaderIfNoneMatch());
obj.setHeaderIfNoneMatch();
console.log("ifnonematch", obj.getHeaderIfNoneMatch());

console.log("token", obj.getHeaderToken());
obj.setHeaderToken(new Buffer("BBB"));
console.log("token", obj.getHeaderToken());

console.log("proxyuri", obj.getHeaderProxyUri());
//obj.setHeaderProxyUri("coap://www.proxy.com");
//console.log("proxyuri", obj.getHeaderProxyUri());

console.log("urihost", obj.getHeaderUriHost());
obj.setHeaderUriHost("server.com");
console.log("urihost", obj.getHeaderUriHost());

console.log("uripath", obj.getHeaderUriPath());
console.log(obj.setHeaderUriPath("/bob"));
console.log("uripath", obj.getHeaderUriPath());
*/
console.log("uriquery", obj.getHeaderUriQuery());
obj.setHeaderUriQuery("?a=b");
console.log("uriquery", obj.getHeaderUriQuery());

console.log("locationpath", obj.getHeaderLocationPath());
obj.setHeaderLocationPath("xyz");
console.log("locationpath", obj.getHeaderLocationPath());

console.log("locationquery", obj.getHeaderLocationQuery());
obj.setHeaderLocationQuery("abc");
console.log("locationquery", obj.getHeaderLocationQuery());

console.log("observe", obj.getHeaderObserve());
obj.setHeaderObserve(10);
console.log("observe", obj.getHeaderObserve());

console.log("size", obj.getHeaderSize());
obj.setHeaderSize(10);
console.log("size", obj.getHeaderSize());

obj.setPayload(new Buffer("HHHHH"));
var buf;
console.log(buf = obj.serialize());

var o2 = new erbium.Erbium(buf);
console.log("uriquery", o2.getHeaderUriQuery());
console.log(o2.serialize());

