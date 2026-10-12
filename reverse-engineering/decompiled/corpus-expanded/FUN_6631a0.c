/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x6631a0; label: FUN_006631a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006631a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  byte bVar6;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    pfVar5 = (float *)(iVar1 + 400);
    if (*(int *)(param_2 + 0xc) == 1) {
      *pfVar5 = *(float *)(iVar1 + 0x150);
      *(undefined4 *)(iVar1 + 0x194) = *(undefined4 *)(iVar1 + 0x154);
    }
    else {
      *(float *)(iVar1 + 0x150) = *pfVar5;
      *(undefined4 *)(iVar1 + 0x154) = *(undefined4 *)(iVar1 + 0x194);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x198) = *(undefined4 *)(iVar1 + 0x158);
      *(undefined4 *)(iVar1 + 0x19c) = *(undefined4 *)(iVar1 + 0x15c);
    }
    else {
      *(undefined4 *)(iVar1 + 0x158) = *(undefined4 *)(iVar1 + 0x198);
      *(undefined4 *)(iVar1 + 0x15c) = *(undefined4 *)(iVar1 + 0x19c);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1a0) = *(undefined4 *)(iVar1 + 0x160);
      *(undefined4 *)(iVar1 + 0x1a4) = *(undefined4 *)(iVar1 + 0x164);
    }
    else {
      *(undefined4 *)(iVar1 + 0x160) = *(undefined4 *)(iVar1 + 0x1a0);
      *(undefined4 *)(iVar1 + 0x164) = *(undefined4 *)(iVar1 + 0x1a4);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1a8) = *(undefined4 *)(iVar1 + 0x168);
      *(undefined4 *)(iVar1 + 0x1ac) = *(undefined4 *)(iVar1 + 0x16c);
    }
    else {
      *(undefined4 *)(iVar1 + 0x168) = *(undefined4 *)(iVar1 + 0x1a8);
      *(undefined4 *)(iVar1 + 0x16c) = *(undefined4 *)(iVar1 + 0x1ac);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1b0) = *(undefined4 *)(iVar1 + 0x170);
      *(undefined4 *)(iVar1 + 0x1b4) = *(undefined4 *)(iVar1 + 0x174);
    }
    else {
      *(undefined4 *)(iVar1 + 0x170) = *(undefined4 *)(iVar1 + 0x1b0);
      *(undefined4 *)(iVar1 + 0x174) = *(undefined4 *)(iVar1 + 0x1b4);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1b8) = *(undefined4 *)(iVar1 + 0x178);
      *(undefined4 *)(iVar1 + 0x1bc) = *(undefined4 *)(iVar1 + 0x17c);
    }
    else {
      *(undefined4 *)(iVar1 + 0x178) = *(undefined4 *)(iVar1 + 0x1b8);
      *(undefined4 *)(iVar1 + 0x17c) = *(undefined4 *)(iVar1 + 0x1bc);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1c0) = *(undefined4 *)(iVar1 + 0x180);
      *(undefined4 *)(iVar1 + 0x1c4) = *(undefined4 *)(iVar1 + 0x184);
    }
    else {
      *(undefined4 *)(iVar1 + 0x180) = *(undefined4 *)(iVar1 + 0x1c0);
      *(undefined4 *)(iVar1 + 0x184) = *(undefined4 *)(iVar1 + 0x1c4);
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined4 *)(iVar1 + 0x1c8) = *(undefined4 *)(iVar1 + 0x188);
      *(undefined4 *)(iVar1 + 0x1cc) = *(undefined4 *)(iVar1 + 0x18c);
    }
    else {
      *(undefined4 *)(iVar1 + 0x188) = *(undefined4 *)(iVar1 + 0x1c8);
      *(undefined4 *)(iVar1 + 0x18c) = *(undefined4 *)(iVar1 + 0x1cc);
    }
    iVar4 = DAT_02962ae8;
    if (*(int *)(param_2 + 0xc) != 1) {
      iVar4 = DAT_02962ae4;
    }
    iVar2 = *(int *)(iVar4 + 0x4c);
    while (iVar2 != 0) {
      FUN_0061a870(iVar4,iVar2);
      iVar2 = *(int *)(iVar4 + 0x4c);
    }
    iVar4 = 0;
    do {
      if (*(int *)(param_2 + 0xc) == 1) {
        fVar3 = (pfVar5[1] - *(float *)(iVar1 + 0x148)) /
                (*(float *)(iVar1 + 0x14c) - *(float *)(iVar1 + 0x148));
        FUN_0061a810(DAT_02962ae8,*pfVar5,fVar3,fVar3,fVar3);
        bVar6 = (byte)((ushort)((ushort)NAN(*pfVar5) << 10) >> 8) |
                (byte)((ushort)((ushort)(*pfVar5 == 1.0) << 0xe) >> 8);
      }
      else {
        fVar3 = (pfVar5[-0xf] - *(float *)(iVar1 + 0x148)) /
                (*(float *)(iVar1 + 0x14c) - *(float *)(iVar1 + 0x148));
        FUN_0061a810(DAT_02962ae4,pfVar5[-0x10],fVar3,fVar3,fVar3);
        bVar6 = (byte)((ushort)((ushort)NAN(pfVar5[-0x10]) << 10) >> 8) |
                (byte)((ushort)((ushort)(pfVar5[-0x10] == 1.0) << 0xe) >> 8);
      }
      if ((POPCOUNT(bVar6) & 1U) != 0) break;
      iVar4 = iVar4 + 1;
      pfVar5 = pfVar5 + 2;
    } while (iVar4 < 8);
    FUN_00600260(iVar1);
  }
  return;
}

