/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442e80; label: FUN_00442e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00442e80(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                    int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_5 != 0)) {
    fVar1 = (float10)FUN_005becc0(param_5 + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,local_c);
    return fVar1;
  }
  return (float10)(float)0x4e6e6b28;
}

