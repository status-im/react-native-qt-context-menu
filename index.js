/**
 * @providesModule react-native-qt-context-menu
 */
'use strict';

let { Platform, NativeModules } = require('react-native')
var ContextMenu = NativeModules.RNCM;

module.exports = {
  show: function (text) {
    ContextMenu.show(text);
  }
}
