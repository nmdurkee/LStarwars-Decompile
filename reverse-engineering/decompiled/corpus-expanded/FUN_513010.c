/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513010; label: FUN_00513010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00513010(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    if ((param_4 != 0) && (param_1 != 0)) {
      for (iVar1 = FUN_004f1440(param_1 + 0x1c); iVar1 != 0;
          iVar1 = FUN_004f1460(param_1 + 0x1c,iVar1)) {
        iVar2 = FUN_004f8b10(param_2,*(undefined4 *)(iVar1 + 8));
        if (iVar2 == 0) {
          return iVar1;
        }
      }
    }
    if (param_5 != 0) {
      for (iVar1 = FUN_004f1440(&DAT_00921ee8); iVar1 != 0;
          iVar1 = FUN_004f1460(&DAT_00921ee8,iVar1)) {
        iVar2 = FUN_004f8b10(param_2,*(undefined4 *)(iVar1 + 8));
        if (iVar2 == 0) {
          return iVar1;
        }
      }
    }
  }
  if (param_3 != 0) {
    for (iVar1 = FUN_004f1440(&DAT_00921ee8); iVar1 != 0; iVar1 = FUN_004f1460(&DAT_00921ee8,iVar1))
    {
      iVar2 = FUN_004f8b10("default",*(undefined4 *)(iVar1 + 8));
      if (iVar2 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

