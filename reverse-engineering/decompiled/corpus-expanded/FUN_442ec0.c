/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442ec0; label: FUN_00442ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442ec0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
      (*(char *)(*(int *)(param_3 + 0xd0) + 0x280) == -1)) && (*(char *)(param_3 + 0x138) == -1)) {
    return (float10)1;
  }
  return (float10)0;
}

