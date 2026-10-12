/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x61a670; label: FUN_0061a670
 */

void FUN_0061a670(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  FUN_00618180(param_2,param_3,param_4,&local_c);
  local_8 = (uint)(longlong)ROUND(local_14 * 255.0);
  uVar1 = local_8 | 0xffff8000;
  local_8 = (uint)(longlong)ROUND(local_10 * 255.0);
  uVar1 = uVar1 << 8 | local_8;
  local_8 = (uint)(longlong)ROUND(local_c * 255.0);
  *(uint *)(param_1 + 0xc) = uVar1 << 8 | local_8;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x18) = param_4;
  return;
}

