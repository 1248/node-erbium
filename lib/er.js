module.exports = require('../build/Release/erbium.node');

module.exports.methodToString = function(code) {
    switch(code) {
        case module.exports.COAP_GET:      return 'get';
        case module.exports.COAP_POST:     return 'post';
        case module.exports.COAP_PUT:      return 'put';
        case module.exports.COAP_DELETE:   return 'del';
        default: throw new Error('code is not a method');
    }
};

module.exports.contentStringToType = function(type) {
    if (type == "text/plain")
        return module.exports.TEXT_PLAIN;
    if (type == "application/linkformat")
        return module.exports.APPLICATION_LINKFORMAT;
    throw new Error('unknown content type string');
};
