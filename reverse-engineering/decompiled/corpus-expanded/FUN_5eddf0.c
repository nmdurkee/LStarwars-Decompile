/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5eddf0; label: FUN_005eddf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

