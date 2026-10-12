/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442b90; label: FUN_00442b90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442b90(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) && (param_3 != 0)) && (*(int *)(param_3 + 0x1b0) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

