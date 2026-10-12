/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x420450; label: FUN_00420450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00420450(void)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  
  iVar6 = 0;
  bVar2 = false;
  if (0 < *(int *)(in_ECX + 4)) {
    piVar5 = (int *)(in_ECX + 0x3c);
    do {
      iVar1 = *piVar5;
      if (-1 < iVar1) {
        bVar2 = true;
        uVar3 = FUN_006e6b90();
        FUN_006d93d0(iVar1,uVar3);
        iVar4 = FUN_006d67a0(iVar1);
        if (iVar4 != 0) {
          uVar3 = FUN_006e6b90();
          FUN_006d9400(iVar1,uVar3);
        }
        FUN_006d5d90(iVar1,0,iVar6);
        FUN_006d6870(iVar1,iVar6,iVar6);
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar6 < *(int *)(in_ECX + 4));
    if (bVar2) {
      FUN_006da550();
      return;
    }
  }
  return;
}

