/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x5143a0; label: FUN_005143a0
 */

void FUN_005143a0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  FUN_004f1440(&DAT_00921ee8);
  if (param_1 != 0) {
    for (iVar3 = FUN_004f1440(param_1 + 0x1c); iVar3 != 0;
        iVar3 = FUN_004f1460(param_1 + 0x1c,iVar3)) {
      for (iVar4 = FUN_004f1440(iVar3 + 0x10); iVar4 != 0; iVar4 = FUN_004f1460(iVar3 + 0x10,iVar4))
      {
        for (iVar5 = FUN_004f1440(iVar4 + 8); iVar5 != 0; iVar5 = FUN_004f1460(iVar4 + 8,iVar5)) {
          pcVar1 = *(code **)(*(int *)(iVar5 + 0x1c) + 8);
          if (pcVar1 != (code *)0x0) {
            uVar6 = (*pcVar1)(param_1,*(undefined4 *)(iVar5 + 0x14),iVar3);
            *(undefined4 *)(iVar5 + 0x18) = uVar6;
          }
          iVar2 = *(int *)(iVar5 + 0x28);
          if (((iVar2 != 0) && (*(int *)(iVar2 + 0x1c) != 0)) &&
             (pcVar1 = *(code **)(*(int *)(iVar2 + 0x1c) + 8), pcVar1 != (code *)0x0)) {
            uVar6 = (*pcVar1)(param_1,*(undefined4 *)(iVar2 + 0x14),iVar3);
            *(undefined4 *)(*(int *)(iVar5 + 0x28) + 0x18) = uVar6;
          }
        }
      }
      uVar6 = FUN_00512fc0(&DAT_00753270,iVar3);
      *(undefined4 *)(iVar3 + 0x38) = uVar6;
      FUN_00514140(param_1,iVar3);
    }
  }
  for (iVar3 = FUN_004f1440(&DAT_00921ee8); iVar3 != 0; iVar3 = FUN_004f1460(&DAT_00921ee8,iVar3)) {
    for (iVar4 = FUN_004f1440(iVar3 + 0x10); iVar4 != 0; iVar4 = FUN_004f1460(iVar3 + 0x10,iVar4)) {
      for (iVar5 = FUN_004f1440(iVar4 + 8); iVar5 != 0; iVar5 = FUN_004f1460(iVar4 + 8,iVar5)) {
        pcVar1 = *(code **)(*(int *)(iVar5 + 0x1c) + 8);
        if ((pcVar1 != (code *)0x0) &&
           (((param_1 == 0 || ((*(byte *)(param_1 + 0x1386) & 4) == 0)) ||
            (*(int *)(iVar5 + 0x18) == 0)))) {
          uVar6 = (*pcVar1)(param_1,*(undefined4 *)(iVar5 + 0x14),iVar3);
          *(undefined4 *)(iVar5 + 0x18) = uVar6;
        }
      }
    }
    uVar6 = FUN_00512fc0(&DAT_00753270,iVar3);
    *(undefined4 *)(iVar3 + 0x38) = uVar6;
    FUN_00514140(param_1,iVar3);
  }
  return;
}

