var Node_OpenGL = require('bindings')('Node_OpenGL');
import gl = require('../');

export class Graphics {
  graphics;
  constructor() {
    this.graphics = Node_OpenGL.Graphics();
  }
  beginFrame() {
    this.graphics.beginFrame();
  }
  endFrame() {
    this.graphics.endFrame();
  }
  drawTextureRect(texture: gl.GfxTexture, x0: number, y0: number, x1: number, y1: number) {
    this.graphics.drawTextureRect(texture.texture, x0, y0, x1, y1);
  }
}
