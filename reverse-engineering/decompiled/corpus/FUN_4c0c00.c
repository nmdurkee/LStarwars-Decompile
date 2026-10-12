/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c0c00; label: FUN_004c0c00
 */

void FUN_004c0c00(int param_1,undefined4 param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(byte *)(param_1 + 0x3c) = *(byte *)(param_1 + 0x3c) | 4;
  iVar1 = param_1 + 0x48;
  *(undefined4 *)(param_1 + 0x44) = param_2;
  FUN_005b3690(iVar1,&DAT_00802500,*(undefined2 *)(param_1 + 0x38));
  FUN_005b3690(iVar1,iVar1,*(undefined2 *)(param_1 + 0x36));
  FUN_005b3830(iVar1,iVar1,0x40400000);
  FUN_0054a8d0(**(undefined4 **)(*(int *)(param_1 + 0x44) + 0xca4),1,0);
  iVar1 = FUN_0054fa60();
  *(byte *)(param_1 + 0x3c) =
       *(byte *)(param_1 + 0x3c) ^ ((iVar1 < 0x8000) << 6 ^ *(byte *)(param_1 + 0x3c)) & 0x40;
  return;
}

