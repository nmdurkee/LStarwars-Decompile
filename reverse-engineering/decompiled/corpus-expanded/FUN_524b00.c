/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524b00; label: FUN_00524b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00524b00(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874);
  if (param_1 != 0) {
    for (; iVar1 != 0; iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
      iVar2 = FUN_004f8b10(param_1,iVar1 + 8);
      if (iVar2 == 0) {
        return iVar1;
      }
    }
  }
  return *(int *)(DAT_009238e4 + 0x4868);
}

