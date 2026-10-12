/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x420450; label: FUN_00420450
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

