/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x533ed0; label: FUN_00533ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00533ed0(undefined4 param_1,int param_2)

{
  uint *puVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 != 0) {
    iVar3 = *(int *)(param_2 + 0xc);
    if (iVar3 == 0) {
      iVar3 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,0,"Delete current route??");
      if (iVar3 != 0) {
        uVar5 = FUN_00627a80(2,&DAT_00801cb4,0,0,FUN_00533ed0,&DAT_0075f2d0);
        FUN_00618e10(iVar3,uVar5);
        uVar5 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00533ed0,&PTR_DAT_0075f2d4);
        FUN_00618e10(iVar3,uVar5);
        FUN_006279b0(param_1,iVar3);
        return;
      }
    }
    else if (iVar3 == 1) {
      iVar3 = *(int *)(DAT_009238e4 + 0x4868);
      if (*(int *)(iVar3 + 0x28) != 0) {
        iVar7 = *(int *)(iVar3 + 0x28);
        puVar1 = (uint *)(*(int *)(iVar3 + 0x28) + 0x18);
        *puVar1 = *puVar1 & 0xfffffffe;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) = 0;
        iVar7 = (iVar7 - iVar3) + -0x40 >> 5;
        iVar3 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18);
        if (iVar3 != 0) {
          uVar2 = __allshl();
          uVar2 = ~uVar2;
          do {
            *(ushort *)(iVar3 + 0x38) = *(ushort *)(iVar3 + 0x38) & uVar2;
            *(ushort *)(iVar3 + 0x44) = *(ushort *)(iVar3 + 0x44) & uVar2;
            *(ushort *)(iVar3 + 0x50) = *(ushort *)(iVar3 + 0x50) & uVar2;
            *(ushort *)(iVar3 + 0x5c) = *(ushort *)(iVar3 + 0x5c) & uVar2;
            *(ushort *)(iVar3 + 0x68) = *(ushort *)(iVar3 + 0x68) & uVar2;
            *(ushort *)(iVar3 + 0x74) = *(ushort *)(iVar3 + 0x74) & uVar2;
            *(ushort *)(iVar3 + 0x80) = *(ushort *)(iVar3 + 0x80) & uVar2;
            *(ushort *)(iVar3 + 0x8c) = *(ushort *)(iVar3 + 0x8c) & uVar2;
            *(ushort *)(iVar3 + 0x96) = *(ushort *)(iVar3 + 0x96) & uVar2;
            iVar3 = FUN_004f1460(*(int *)(DAT_009238e4 + 0x4868) + 0x18,iVar3);
          } while (iVar3 != 0);
        }
        iVar6 = 4;
        iVar3 = DAT_009238e4;
        do {
          iVar7 = iVar7 + 1;
          if (0xf < iVar7) {
            iVar7 = 0;
          }
          iVar4 = (iVar7 + 2) * 0x20 + *(int *)(iVar3 + 0x4868);
          if ((*(byte *)(iVar4 + 0x18) & 1) != 0) {
            *(int *)(*(int *)(iVar3 + 0x4868) + 0x28) = iVar4;
            iVar3 = DAT_009238e4;
          }
          iVar7 = iVar7 + 1;
          if (0xf < iVar7) {
            iVar7 = 0;
          }
          iVar4 = (iVar7 + 2) * 0x20 + *(int *)(iVar3 + 0x4868);
          if ((*(byte *)(iVar4 + 0x18) & 1) != 0) {
            *(int *)(*(int *)(iVar3 + 0x4868) + 0x28) = iVar4;
            iVar3 = DAT_009238e4;
          }
          iVar7 = iVar7 + 1;
          if (0xf < iVar7) {
            iVar7 = 0;
          }
          iVar4 = (iVar7 + 2) * 0x20 + *(int *)(iVar3 + 0x4868);
          if ((*(byte *)(iVar4 + 0x18) & 1) != 0) {
            *(int *)(*(int *)(iVar3 + 0x4868) + 0x28) = iVar4;
            iVar3 = DAT_009238e4;
          }
          iVar7 = iVar7 + 1;
          if (0xf < iVar7) {
            iVar7 = 0;
          }
          iVar4 = (iVar7 + 2) * 0x20 + *(int *)(iVar3 + 0x4868);
          if ((*(byte *)(iVar4 + 0x18) & 1) != 0) {
            *(int *)(*(int *)(iVar3 + 0x4868) + 0x28) = iVar4;
            iVar3 = DAT_009238e4;
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        if (*(int *)(iVar3 + 4) != 0) {
          FUN_00624220(*(undefined4 *)(iVar3 + 4));
          *(undefined4 *)(DAT_009238e4 + 4) = 0;
          return;
        }
      }
    }
    else if (iVar3 == 2) {
      FUN_00624220(param_1);
    }
  }
  return;
}

