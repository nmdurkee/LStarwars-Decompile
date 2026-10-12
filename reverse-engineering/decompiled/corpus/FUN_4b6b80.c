/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b6b80; label: FUN_004b6b80
 */

void FUN_004b6b80(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x1085) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  if (*(short *)(iVar1 + 0xe8) != -1) {
    FUN_00547cb0(param_1,(int)*(short *)(iVar1 + 0xe8),(float)*(byte *)(iVar1 + 0x11e));
  }
  if (((*(int *)(*(int *)(param_1 + 0x54) + 0x18) != 0x4b5120) && (*(short *)(param_1 + 0xe1c) != 0)
      ) && ((*(uint *)(param_1 + 0xe24) & 0x2000) == 0)) {
    *(undefined2 *)(param_1 + 0xe1c) = 0;
  }
  return;
}

