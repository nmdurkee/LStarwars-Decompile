/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a590; label: FUN_0061a590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

