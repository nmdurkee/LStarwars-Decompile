/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513230; label: FUN_00513230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00513230(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_4;
  
  _DAT_0092224c = 1;
  local_4 = 0;
  DAT_00922250 = 1;
  if (DAT_009238c0 != (code *)0x0) {
    iVar1 = (*DAT_009238c0)(0,0,param_1,&local_4);
    if (iVar1 != 0) {
      DAT_00922250 = 0;
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_4;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = FUN_006e6b90();
    *param_3 = uVar2;
    return 0;
  }
  return 0;
}

