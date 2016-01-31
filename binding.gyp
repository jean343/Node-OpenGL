{
  "targets": [
    {
      "target_name": "Node_OpenGL",
      "sources": [
        "src/main.cpp",
        "src/GfxTexture.cpp",
        "src/GfxShader.cpp",
        "src/GfxProgram.cpp",
        "src/Graphics.cpp"
      ],
      "defines": [
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "/opt/vc/include",
        "/opt/vc/include/interface/vcos/pthreads",
        "/opt/vc/include/interface/vmcs_host/linux"
      ],
      "link_settings": {
        "library_dirs": [
          "/opt/vc/lib"
        ],
        "libraries": [
          "-lopenmaxil",
          "-lbcm_host",
          "-lvcos",
          "-lpthread"
        ]
      },
    }
  ]
}