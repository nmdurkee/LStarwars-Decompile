/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x61a590; label: FUN_0061a590
 */

void FUN_0061a590(int param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  uint local_14;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00618000(param_2,param_3,param_4,&local_4);
  local_14 = (uint)(longlong)ROUND(param_4);
  uVar1 = local_14 | 0xffff8000;
  local_14 = (uint)(longlong)ROUND(param_3);
  uVar1 = uVar1 << 8 | local_14;
  local_14 = (uint)(longlong)ROUND(param_2);
  *(uint *)(param_1 + 0xc) = uVar1 << 8 | local_14;
  *(undefined4 *)(param_1 + 0x10) = local_c;
  *(undefined4 *)(param_1 + 0x14) = local_8;
  *(undefined4 *)(param_1 + 0x18) = local_4;
  return;
}

