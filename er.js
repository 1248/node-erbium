var erbium = require('./build/Release/erbium');


var obj = new erbium.Erbium(erbium.COAP_TYPE_CON, erbium.COAP_GET, 0);
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

obj.setPayload(new Buffer("HHHHH"));
var buf;
console.log(buf = obj.serialize());

var o2 = new erbium.Erbium(buf);
console.log(o2.serialize());
