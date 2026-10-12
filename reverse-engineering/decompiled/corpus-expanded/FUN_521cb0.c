/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521cb0; label: FUN_00521cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00521cb0(int param_1)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar7 = 0;
  for (iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar2 != 0;
      iVar2 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar2)) {
    *(undefined2 *)(iVar2 + 0x44) = 0xff;
    if (*(int *)(iVar2 + 0x2c) != 0) {
      *(short *)(iVar2 + 0x44) = (short)iVar7;
      iVar7 = iVar7 + 1;
    }
  }
  FUN_00621520(iVar7);
  for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x3cbd8); iVar7 != 0;
      iVar7 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar7)) {
    if (*(int *)(iVar7 + 0x2c) != 0) {
      FUN_00621440(iVar7 + 8,0x10);
      FUN_006214d0(*(undefined4 *)(iVar7 + 0x18));
      FUN_006214d0(*(undefined4 *)(iVar7 + 0x1c));
      FUN_006214d0(*(undefined4 *)(iVar7 + 0x20));
      FUN_006215a0(*(undefined2 *)(iVar7 + 0x24));
      FUN_00621600(*(undefined1 *)(*(int *)(iVar7 + 0x2c) + 0x38));
      iVar2 = *(int *)(*(int *)(param_1 + 4) + *(char *)(*(int *)(iVar7 + 0x2c) + 0x38) * 4);
      uVar6 = (uint)*(ushort *)(iVar2 + 0x12);
      bVar9 = false;
      iVar5 = 0;
      iVar8 = 0;
      if (uVar6 != 0) {
        uVar1 = *(ushort *)(*(int *)(iVar7 + 0x30) + 0x90);
        pbVar3 = (byte *)(*(int *)(iVar2 + 0x80) + 0x11);
        do {
          iVar8 = iVar5;
          if ((pbVar3[-1] == uVar1) &&
             ((ushort)*pbVar3 == *(ushort *)(*(int *)(iVar7 + 0x34) + 0x90))) {
            uVar6 = (int)*(uint *)(iVar7 + 0x40) >> 0x1f;
            bVar9 = 0x3fff < (int)((*(uint *)(iVar7 + 0x40) ^ uVar6) - uVar6);
            goto LAB_00521e37;
          }
          if (((ushort)pbVar3[-1] == *(ushort *)(*(int *)(iVar7 + 0x34) + 0x90)) &&
             (*pbVar3 == uVar1)) {
            uVar6 = (int)*(uint *)(iVar7 + 0x40) >> 0x1f;
            bVar9 = (int)((*(uint *)(iVar7 + 0x40) ^ uVar6) - uVar6) < 0x4000;
            goto LAB_00521e37;
          }
          iVar5 = iVar5 + 1;
          pbVar3 = pbVar3 + 0x24;
        } while (iVar5 < (int)uVar6);
        bVar9 = false;
        iVar8 = 0;
      }
LAB_00521e37:
      FUN_00621600(bVar9);
      FUN_006215a0(iVar8);
      FUN_006214d0(*(undefined4 *)(iVar7 + 0x38));
      FUN_006214d0(*(undefined4 *)(iVar7 + 0x3c));
      if (0xe < DAT_0080171c) {
        FUN_00621520(*(undefined4 *)(iVar7 + 0x40));
      }
    }
  }
  if (0x11 < DAT_0080171c) {
    iVar7 = 0;
    for (iVar2 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar2 != 0;
        iVar2 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar2)) {
      iVar7 = iVar7 + 1;
    }
    FUN_00621520(iVar7);
    if (iVar7 != 0) {
      for (iVar7 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar7 != 0;
          iVar7 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar7)) {
        iVar8 = 0;
        iVar2 = 0;
        piVar4 = (int *)(iVar7 + 0x1c);
        do {
          if (piVar4[-1] == 0) break;
          if (*(short *)(piVar4[-1] + 0x44) != 0xff) {
            iVar8 = iVar8 + 1;
          }
          if (*piVar4 == 0) break;
          if (*(short *)(*piVar4 + 0x44) != 0xff) {
            iVar8 = iVar8 + 1;
          }
          if (piVar4[1] == 0) break;
          if (*(short *)(piVar4[1] + 0x44) != 0xff) {
            iVar8 = iVar8 + 1;
          }
          if (piVar4[2] == 0) break;
          if (*(short *)(piVar4[2] + 0x44) != 0xff) {
            iVar8 = iVar8 + 1;
          }
          iVar2 = iVar2 + 4;
          piVar4 = piVar4 + 4;
        } while (iVar2 < 0x40);
        FUN_00621440(iVar7 + 8,0x10);
        FUN_00621520(iVar8);
        if (iVar8 != 0) {
          iVar2 = 0;
          piVar4 = (int *)(iVar7 + 0x18);
          do {
            iVar8 = *piVar4;
            if (iVar8 == 0) break;
            if (*(short *)(iVar8 + 0x44) != 0xff) {
              FUN_00621600(*(undefined1 *)(iVar8 + 0x44));
            }
            iVar2 = iVar2 + 1;
            piVar4 = piVar4 + 1;
          } while (iVar2 < 0x40);
        }
      }
    }
  }
  return;
}

