/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x514600; label: FUN_00514600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00514600(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_2 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 4) != 0)) {
    iVar1 = FUN_00512fc0(param_2,*(int *)(param_1 + 4));
    if (iVar1 != 0) {
      FUN_005145a0(param_1,iVar1);
      return 1;
    }
  }
  return 0;
}

