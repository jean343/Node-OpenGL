var Node_OpenGL = require('bindings')('Node_OpenGL');

export class GL {
  constructor() {
    console.log(Node_OpenGL.hello()); // 'world'
  }
}
