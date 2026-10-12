/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x5132a0; label: FUN_005132a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005132a0(undefined4 param_1)

{
  float10 fVar1;
  
  _DAT_0092224c = 0;
  DAT_00922250 = 0;
  DAT_00922254 = 0;
  fVar1 = (float10)FUN_004f88e0(param_1,FUN_00513230);
  if (DAT_00922250 != 0) {
    DAT_00922254 = 1;
  }
  return (float10)(float)fVar1;
}

