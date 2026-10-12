/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x443d30; label: FUN_00443d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00443d30(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = FUN_00570090(PTR_DAT_00802c54,param_2);
    return uVar1;
  }
  return 0;
}

