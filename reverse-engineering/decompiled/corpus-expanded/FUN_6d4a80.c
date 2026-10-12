/* Ghidra pseudocode, not original source.
 * ev_c1426acf87a342a1866e519dab13ac5b40d9f4eac6e37fcdd4b99f9d53dd1e8b
 * Entry: 0x6d4a80; label: FUN_006d4a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d4a80(int param_1,uint param_2)

{
  int iVar1;
  short sVar2;
  int in_ECX;
  
  param_1 = param_1 * 0x17c;
  sVar2 = *(short *)(param_1 + 0x4ea4 + in_ECX);
  iVar1 = param_1 + 0x4ea2 + in_ECX;
  if (*(char *)(param_1 + 0x4ea2 + in_ECX) == '\x01') {
    if (sVar2 == 0x80) {
      param_2 = param_2 & 0xffffefff;
    }
    if (sVar2 == 0x82) {
      param_2 = param_2 & 0xffffbfff;
    }
    if (sVar2 == 0x83) {
      param_2 = param_2 & 0xffff7fff;
    }
    if (sVar2 == 0x81) {
      param_2 = param_2 & 0xffffdfff;
    }
  }
  sVar2 = *(short *)(iVar1 + 6);
  if (*(char *)(iVar1 + 4) == '\x01') {
    if (sVar2 == 0x80) {
      param_2 = param_2 & 0xffffefff;
    }
    if (sVar2 == 0x82) {
      param_2 = param_2 & 0xffffbfff;
    }
    if (sVar2 == 0x83) {
      param_2 = param_2 & 0xffff7fff;
    }
    if (sVar2 == 0x81) {
      param_2 = param_2 & 0xffffdfff;
    }
  }
  sVar2 = *(short *)(iVar1 + 10);
  if (*(char *)(iVar1 + 8) == '\x01') {
    if (sVar2 == 0x80) {
      param_2 = param_2 & 0xffffefff;
    }
    if (sVar2 == 0x82) {
      param_2 = param_2 & 0xffffbfff;
    }
    if (sVar2 == 0x83) {
      param_2 = param_2 & 0xffff7fff;
    }
    if (sVar2 == 0x81) {
      param_2 = param_2 & 0xffffdfff;
    }
  }
  sVar2 = *(short *)(iVar1 + 0xe);
  if (*(char *)(iVar1 + 0xc) == '\x01') {
    if (sVar2 == 0x80) {
      param_2 = param_2 & 0xffffefff;
    }
    if (sVar2 == 0x82) {
      param_2 = param_2 & 0xffffbfff;
    }
    if (sVar2 == 0x83) {
      param_2 = param_2 & 0xffff7fff;
    }
    if (sVar2 == 0x81) {
      param_2 = param_2 & 0xffffdfff;
    }
  }
  return param_2;
}

