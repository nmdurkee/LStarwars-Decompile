/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x514140; label: FUN_00514140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00514140(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar2 = FUN_004f1440(param_2 + 0x40);
    while (iVar2 != 0) {
      iVar3 = FUN_004f1460(param_2 + 0x40,iVar2);
      if (((*(byte *)(param_1 + 0x1386) & 4) == 0) || (*(int *)(iVar2 + 0xc) == 0)) {
        uVar4 = FUN_00513010(param_1,*(undefined4 *)(iVar2 + 8),1,*(uint *)(iVar2 + 0x18) >> 1 & 1,
                             *(uint *)(iVar2 + 0x18) & 1);
        *(undefined4 *)(iVar2 + 0xc) = uVar4;
      }
      if ((*(int *)(iVar2 + 0xc) == 0) || (*(int *)(iVar2 + 0xc) == param_2)) {
        FUN_004f1410(param_2 + 0x40,iVar2);
        iVar2 = iVar3;
      }
      else {
        iVar5 = FUN_00512fc0(*(undefined4 *)(iVar2 + 0x10),param_2);
        *(int *)(iVar2 + 0x14) = iVar5;
        if ((iVar5 == 0) && (iVar5 = *(int *)(iVar2 + 0x10), iVar5 != 0)) {
          if (DAT_00922248 == 1) {
            FUN_00512860(iVar5,*(undefined4 *)(param_2 + 8));
          }
          else {
            FUN_00512850(iVar5,*(undefined4 *)(param_2 + 8));
          }
        }
        iVar5 = iVar2 + 0x1c;
        for (iVar6 = FUN_004f1440(iVar5); iVar2 = iVar3, iVar6 != 0;
            iVar6 = FUN_004f1460(iVar5,iVar6)) {
          pcVar1 = *(code **)(*(int *)(iVar6 + 0x1c) + 8);
          if (pcVar1 != (code *)0x0) {
            uVar4 = (*pcVar1)(param_1,*(undefined4 *)(iVar6 + 0x14),param_2);
            *(undefined4 *)(iVar6 + 0x18) = uVar4;
          }
        }
      }
    }
    for (iVar2 = FUN_004f1440(param_2 + 0x10); iVar2 != 0;
        iVar2 = FUN_004f1460(param_2 + 0x10,iVar2)) {
      iVar3 = FUN_004f1440(iVar2 + 0x1c);
      while (iVar3 != 0) {
        iVar5 = FUN_004f1460(iVar2 + 0x1c,iVar3);
        if (((*(byte *)(param_1 + 0x1386) & 4) == 0) || (*(int *)(iVar3 + 0xc) == 0)) {
          uVar4 = FUN_00513010(param_1,*(undefined4 *)(iVar3 + 8),1,*(uint *)(iVar3 + 0x18) >> 1 & 1
                               ,*(uint *)(iVar3 + 0x18) & 1);
          *(undefined4 *)(iVar3 + 0xc) = uVar4;
        }
        if ((*(int *)(iVar3 + 0xc) == 0) || (*(int *)(iVar3 + 0xc) == param_2)) {
          FUN_004f1410(param_2 + 0x40,iVar3);
        }
        iVar6 = FUN_00512fc0(*(undefined4 *)(iVar3 + 0x10),param_2);
        *(int *)(iVar3 + 0x14) = iVar6;
        if ((iVar6 == 0) && (*(int *)(iVar3 + 0x10) != 0)) {
          if (DAT_00922248 == 1) {
            FUN_00512860();
          }
          else {
            FUN_00512850(*(int *)(iVar3 + 0x10),*(undefined4 *)(param_2 + 8),
                         *(undefined4 *)(iVar2 + 0x18));
          }
        }
        iVar6 = iVar3 + 0x1c;
        for (iVar7 = FUN_004f1440(iVar6); iVar3 = iVar5, iVar7 != 0;
            iVar7 = FUN_004f1460(iVar6,iVar7)) {
          pcVar1 = *(code **)(*(int *)(iVar7 + 0x1c) + 8);
          if (pcVar1 != (code *)0x0) {
            uVar4 = (*pcVar1)(param_1,*(undefined4 *)(iVar7 + 0x14),param_2);
            *(undefined4 *)(iVar7 + 0x18) = uVar4;
          }
        }
      }
    }
  }
  return;
}

