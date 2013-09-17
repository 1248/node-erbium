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
