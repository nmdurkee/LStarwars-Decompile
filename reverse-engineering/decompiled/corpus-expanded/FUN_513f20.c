/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513f20; label: FUN_00513f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00513f20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  iVar1 = param_1;
  if (((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) && ((*(uint *)(param_1 + 0x3c) & 2) != 0))
  {
    uVar2 = *(uint *)(param_1 + 0x3c) >> 2;
    iVar3 = FUN_00513010(param_4,*(int *)(param_1 + 0xc),0,uVar2 & 1,~uVar2 & 1);
    if (iVar3 == 0) {
      if (DAT_00922248 == 1) {
        FUN_00512860(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
        *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffffd;
        return 1;
      }
      FUN_00512850(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    }
    else if (iVar3 != param_1) {
      if ((*(byte *)(iVar3 + 0x3c) & 2) != 0) {
        return 0;
      }
      iVar4 = FUN_004f1440(iVar3 + 0x10);
      if (iVar4 != 0) {
        iVar7 = param_1 + 0x10;
        do {
          for (iVar5 = FUN_004f1440(iVar7); iVar5 != 0; iVar5 = FUN_004f1460(iVar7,iVar5)) {
            iVar6 = FUN_004f8b10(*(undefined4 *)(iVar4 + 0x18),*(undefined4 *)(iVar5 + 0x18));
            if (iVar6 == 0) goto LAB_00513ff4;
          }
          iVar5 = FUN_00513cc0(iVar4,param_3);
          if (iVar5 != 0) {
            FUN_004f1310(iVar7,iVar5);
          }
LAB_00513ff4:
          iVar4 = FUN_004f1460(iVar3 + 0x10,iVar4);
        } while (iVar4 != 0);
      }
      iVar4 = iVar3 - param_1;
      piVar8 = (int *)(iVar3 + 0x1c);
      piVar9 = (int *)(param_1 + 0x18);
      param_1 = 4;
      do {
        iVar3 = *(int *)(iVar4 + (int)piVar9);
        if ((iVar3 != 0) && (*piVar9 == 0)) {
          iVar3 = FUN_00513100(iVar3,param_3);
          *piVar9 = iVar3;
          piVar9[1] = *piVar8;
        }
        piVar9 = piVar9 + 2;
        piVar8 = piVar8 + 2;
        param_1 = param_1 + -1;
      } while (param_1 != 0);
      iVar3 = FUN_004f1440(iVar1 + 0x10);
      if (iVar3 != 0) {
        do {
          for (iVar4 = FUN_004f1440(iVar3 + 8); iVar4 != 0; iVar4 = FUN_004f1460(iVar3 + 8,iVar4)) {
            iVar7 = FUN_00512fc0(*(undefined4 *)(iVar4 + 0x20),iVar1);
            *(int *)(iVar4 + 0x24) = iVar7;
            if ((*(int *)(iVar4 + 0x20) != 0) && (iVar7 == 0)) {
              if (DAT_00922248 == 1) {
                FUN_00512860();
              }
              else {
                FUN_00512850(*(int *)(iVar4 + 0x20),*(undefined4 *)(iVar1 + 8),
                             *(undefined4 *)(iVar3 + 0x18));
              }
            }
          }
          iVar3 = FUN_004f1460(iVar1 + 0x10,iVar3);
        } while (iVar3 != 0);
        *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xfffffffd;
        return 1;
      }
    }
    *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xfffffffd;
  }
  return 1;
}

