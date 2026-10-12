/* Ghidra pseudocode, not original source.
 * ev_09b5e7ee7088db2a04984dfae30d6ae02c213fc9199c1befda76464f991548e2
 * Entry: 0x5c2f50; label: FUN_005c2f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c2f50(undefined4 param_1)

{
  int in_ECX;
  
  switch(param_1) {
  case 0:
    return (float10)*(float *)(in_ECX + 0x80c);
  case 1:
    return (float10)*(float *)(in_ECX + 0x810);
  case 2:
    return (float10)*(float *)(in_ECX + 0x814);
  case 3:
    return (float10)*(float *)(in_ECX + 0x818);
  default:
    return (float10)0;
  case 6:
  case 7:
    return (float10)*(float *)(in_ECX + 0x110);
  case 8:
    return (float10)*(float *)(in_ECX + 0x490);
  case 9:
  case 10:
  case 0xb:
  case 0xf:
  case 0x10:
    return (float10)*(float *)(in_ECX + 0x484);
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x11:
  case 0x12:
    return (float10)*(float *)(in_ECX + 0x100);
  case 0x13:
    return (float10)*(float *)(in_ECX + 0x81c);
  case 0x14:
    return (float10)*(float *)(in_ECX + 0x820);
  }
}

