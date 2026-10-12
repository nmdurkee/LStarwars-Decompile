/* Ghidra pseudocode, not original source.
 * ev_8c08cb58b3e2eca2ce3b645626710873c7692325f2a23ef4bde2c2500b41a2fb
 * Entry: 0x442b70; label: FUN_00442b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00442b70(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_0051ac10(param_1,param_2);
    return uVar1;
  }
  return 0;
}

