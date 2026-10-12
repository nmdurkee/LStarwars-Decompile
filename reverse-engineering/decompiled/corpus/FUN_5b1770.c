/* Ghidra analysis pseudocode, not original source.
 * ev_9de9052a7a74906b1fb5570bf9c5ea7426c8a6fcab6dcccf13cbc82c1ebad988
 * Entry: 0x5b1770; label: FUN_005b1770
 */

undefined4 FUN_005b1770(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
  *(uint *)(param_1 + 0x46d0) = uVar1;
  *(uint *)(param_1 + 0x104) = uVar1 + 0xf00;
  *(undefined4 *)(param_1 + 0x46cc) = 0;
  _memset(*(void **)(param_1 + 0x46d0),0,0xf00);
  uVar1 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
  *(uint *)(param_1 + 0x46d8) = uVar1;
  *(uint *)(param_1 + 0x104) = uVar1 + 0xc00;
  *(undefined4 *)(param_1 + 0x46d4) = 0;
  _memset(*(void **)(param_1 + 0x46d8),0,0xc00);
  return 1;
}

