/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x5242b0; label: FUN_005242b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005242b0(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
    iVar2 = FUN_004f1440(iVar1 + 0x18);
    sVar3 = 0;
    for (; iVar2 != 0; iVar2 = FUN_004f1460(iVar1 + 0x18,iVar2)) {
      *(short *)(iVar2 + 0x90) = sVar3;
      sVar3 = sVar3 + 1;
    }
  }
  return;
}

