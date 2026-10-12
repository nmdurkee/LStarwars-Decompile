/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x512fc0; label: FUN_00512fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00512fc0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f1440(param_2 + 0x10);
  if (param_1 != 0) {
    for (; iVar1 != 0; iVar1 = FUN_004f1460(param_2 + 0x10,iVar1)) {
      iVar2 = FUN_004f8b10(param_1,*(undefined4 *)(iVar1 + 0x18));
      if (iVar2 == 0) {
        return iVar1;
      }
    }
  }
  return 0;
}

