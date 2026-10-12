/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b7120; label: FUN_004b7120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004b7120(int param_1)

{
  int iVar1;
  
  if ((param_1 != -1) && ((param_1 == 0 || (param_1 == 1)))) {
    iVar1 = FUN_006e6b90();
    return (float10)((1.0 - ((float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] + 1.0) * 0.5) *
                     (_DAT_007fc2bc - _DAT_007fc2b8) + _DAT_007fc2b8);
  }
  return (float10)_DAT_007fc2b8;
}

