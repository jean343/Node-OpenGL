var Node_OpenGL = require('bindings')('Node_OpenGL');

export class GfxTexture {
  texture;
  constructor(width: number, height: number) {
    this.texture = Node_OpenGL.GfxTexture(width, height);
  }
  setPixels(pixels: Buffer) {
    this.texture.setPixels(pixels);
  }
}
