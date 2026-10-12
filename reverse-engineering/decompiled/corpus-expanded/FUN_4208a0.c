/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x4208a0; label: FUN_004208a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004208b8) */

uint FUN_004208a0(float param_1,float param_2)

{
  uint uVar1;
  undefined4 local_8;
  
  uVar1 = (uint)param_2;
  param_2 = (float)((uint)param_2 >> 0x18) * param_1;
  if (255.0 < param_2) {
    param_2 = 255.0;
  }
  local_8 = (int)(longlong)ROUND(param_2);
  return local_8 << 0x18 | uVar1 & 0xffffff;
}

