/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c4e70; label: FUN_005c4e70
 */

void FUN_005c4e70(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  FUN_00605b60(uVar1,0,*(undefined4 *)(in_ECX + 0x14),0);
  return;
}

