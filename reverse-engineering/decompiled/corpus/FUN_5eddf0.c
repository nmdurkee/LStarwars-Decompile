/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5eddf0; label: FUN_005eddf0
 */

void FUN_005eddf0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  _memset(&DAT_009716a0,0,0x40);
  FUN_005d7f80(param_2,0,7);
  FUN_005d7f80(param_2,0,0x10);
  iVar1 = FUN_005e4b20(0);
  DAT_0097397c = iVar1;
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffff2 | 2;
  FUN_00601030(iVar1);
  *(short *)(iVar1 + 0x2c0) = *(short *)(iVar1 + 0x2c0) + 1;
  DAT_0097396c = 1;
  return;
}

