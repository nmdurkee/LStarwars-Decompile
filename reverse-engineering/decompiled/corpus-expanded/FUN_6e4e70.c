/* Ghidra pseudocode, not original source.
 * ev_159ae24d072b02a6eb3bf9a5c1c2d47f096699e5cf3aac35a19c5291e20383ee
 * Entry: 0x6e4e70; label: FUN_006e4e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4e70(undefined4 param_1,undefined4 param_2)

{
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x19c))(DAT_029765cc,param_1,param_2);
  return;
}

