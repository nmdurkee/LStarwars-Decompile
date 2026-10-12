/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x552e50; label: FUN_00552e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00552e50(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    iVar1 = FUN_005cfac0(param_1);
    if (iVar1 != 0) {
      uVar2 = FUN_005d6170();
      FUN_005c0500(param_2,param_2,uVar2);
      uVar2 = FUN_005f33b0(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}

