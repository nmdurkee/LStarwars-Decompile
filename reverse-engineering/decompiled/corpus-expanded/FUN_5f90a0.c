/* Ghidra pseudocode, not original source.
 * ev_eb6388f9e6f0da39ba23c58a55c6a14172e207ae27b9d6b4ddcb98efebe4d9b1
 * Entry: 0x5f90a0; label: FUN_005f90a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005f90a0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_005f9030(param_1);
  param_3 = iVar1 * param_2 * param_3;
  return (int)(param_3 + (param_3 >> 0x1f & 7U)) >> 3;
}

