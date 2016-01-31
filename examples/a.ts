import gl = require('../');

var width = 320;
var height = 240;

var graphics = new gl.Graphics();
var texture = new gl.GfxTexture(width, height);

var data = new Buffer(width * height);

data.fill(0);
for (var x = 0; x < width / 2; x++) {
  for (var y = 0; y < height / 2; y++) {
    data.writeUInt8(128, y * width + x);
  }
}

var running = true;
while (running) {
  console.log('running');
  texture.setPixels(data);

  graphics.beginFrame();
  //    float aspect_ratio = float(width) / float(height);
  //    float screen_aspect_ratio = 1920.f / 1080.f;
  //DrawTextureRect(&texture,-aspect_ratio/screen_aspect_ratio,-1.f,aspect_ratio/screen_aspect_ratio,1.f);
  graphics.drawTextureRect(texture, -1, -1, 1, 1);
  graphics.endFrame();
}