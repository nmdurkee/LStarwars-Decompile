/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442b00; label: FUN_00442b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442b00(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     ((*(byte *)(**(int **)(param_3 + 0xd0) + 0xef0) & 8) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

