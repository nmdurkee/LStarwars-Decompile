/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570c00; label: FUN_00570c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00570c00(int param_1)

{
  uint uVar1;
  undefined2 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(param_1 + 0x30);
  local_8 = *(undefined4 *)(param_1 + 0x34);
  local_4 = *(undefined4 *)(param_1 + 0x38);
  uVar1 = (uint)ROUND((float)*(ushort *)(param_1 + 0x13a) + _DAT_00925018 * 16384.0);
  local_10 = (undefined2)uVar1;
  *(undefined2 *)(param_1 + 0x13a) = local_10;
  FUN_005b4670(param_1,uVar1 & 0xffff);
  FUN_005b4900(param_1,&local_c);
  return;
}

