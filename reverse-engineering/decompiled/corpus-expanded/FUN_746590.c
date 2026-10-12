/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746590; label: FUN_00746590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_00746590(void)

{
  int in_ECX;
  
  switch(*(undefined4 *)(in_ECX + 0x10)) {
  case 0:
    return *(char **)(in_ECX + 0x14);
  case 1:
    return "DEFAULT";
  case 2:
    return "POSITION";
  case 3:
    return "POSITION1";
  case 4:
    return "VPOS";
  case 5:
    return "NORMAL";
  case 6:
    return "TANGENT";
  case 7:
    return "BINORMAL";
  case 8:
    return "TANGENT1";
  case 9:
    return "COLORX";
  case 10:
    return "COLOR0";
  case 0xb:
    return "COLOR1";
  case 0xc:
    return "FOG";
  case 0xd:
    return "TEXCOORDX";
  case 0xe:
    return "TEXCOORD0";
  case 0xf:
    return "TEXCOORD1";
  case 0x10:
    return "TEXCOORD2";
  case 0x11:
    return "TEXCOORD3";
  default:
    return "INVALID";
  case 0x14:
    return "TEXCOORD6";
  case 0x15:
    return "TEXCOORD7";
  case 0x16:
    return "BLENDINDICES0";
  case 0x17:
    return "BLENDWEIGHT0";
  case 0x18:
    return "INDEX";
  }
}

