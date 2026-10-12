/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74b3a0; label: FUN_0074b3a0
 */

byte FUN_0074b3a0(void)

{
  char cVar1;
  
  cVar1 = FUN_0074a9a0("default");
  if (cVar1 == '\0') {
    cVar1 = FUN_0074a9a0("strict");
    if (cVar1 != '\0') {
      return 0xd;
    }
    cVar1 = FUN_0074a9a0("semantic_default");
    if (cVar1 == '\0') {
      cVar1 = FUN_0074a9a0("semantic_position");
      if (cVar1 != '\0') {
        return 2;
      }
      cVar1 = FUN_0074a9a0("semantic_position1");
      if (cVar1 != '\0') {
        return 3;
      }
      cVar1 = FUN_0074a9a0("semantic_vpos");
      if (cVar1 != '\0') {
        return 4;
      }
      cVar1 = FUN_0074a9a0("semantic_normal");
      if (cVar1 != '\0') {
        return 5;
      }
      cVar1 = FUN_0074a9a0("semantic_tangent");
      if (cVar1 != '\0') {
        return 6;
      }
      cVar1 = FUN_0074a9a0("semantic_binormal");
      if ((cVar1 != '\0') || (cVar1 = FUN_0074a9a0("semantic_bitangent"), cVar1 != '\0')) {
        return 7;
      }
      cVar1 = FUN_0074a9a0("semantic_tangent1");
      if (cVar1 != '\0') {
        return 8;
      }
      cVar1 = FUN_0074a9a0("semantic_colorx");
      if (cVar1 != '\0') {
        return 9;
      }
      cVar1 = FUN_0074a9a0("semantic_color0");
      if (cVar1 != '\0') {
        return 10;
      }
      cVar1 = FUN_0074a9a0("semantic_color1");
      if (cVar1 != '\0') {
        return 0xb;
      }
      cVar1 = FUN_0074a9a0("semantic_fog");
      if (cVar1 != '\0') {
        return 0xc;
      }
      cVar1 = FUN_0074a9a0("semantic_texcoordx");
      if (cVar1 != '\0') {
        return 0xd;
      }
      cVar1 = FUN_0074a9a0("semantic_texcoord0");
      if (cVar1 != '\0') {
        return 0xe;
      }
      cVar1 = FUN_0074a9a0("semantic_texcoord1");
      if (cVar1 != '\0') {
        return 0xf;
      }
      cVar1 = FUN_0074a9a0("semantic_texcoord2");
      if (cVar1 != '\0') {
        return 0x10;
      }
      cVar1 = FUN_0074a9a0("semantic_texcoord3");
      if (cVar1 == '\0') {
        cVar1 = FUN_0074a9a0("semantic_texcoord4");
        if (cVar1 != '\0') {
          return 0x12;
        }
        cVar1 = FUN_0074a9a0("semantic_texcoord5");
        if (cVar1 != '\0') {
          return 0x13;
        }
        cVar1 = FUN_0074a9a0("semantic_texcoord6");
        if (cVar1 != '\0') {
          return 0x14;
        }
        cVar1 = FUN_0074a9a0("semantic_texcoord7");
        if (cVar1 == '\0') {
          cVar1 = FUN_0074a9a0("semantic_blendIndices0");
          if (cVar1 != '\0') {
            return 0x16;
          }
          cVar1 = FUN_0074a9a0("semantic_blendWeight0");
          if (cVar1 == '\0') {
            cVar1 = FUN_0074a9a0("semantic_index");
            return -(cVar1 != '\0') & 0x18;
          }
          return 0x17;
        }
        return 0x15;
      }
      return 0x11;
    }
  }
  return 1;
}

