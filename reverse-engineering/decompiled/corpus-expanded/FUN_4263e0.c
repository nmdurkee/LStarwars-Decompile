/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4263e0; label: FUN_004263e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004263e0(void)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  
  if (DAT_008569a8 != 0) {
    FUN_004252c0();
    DAT_008569a8 = 0;
    return;
  }
  iVar1 = FUN_00424810();
  uVar5 = 0x70;
  pbVar2 = (byte *)&DAT_0086669c;
  pbVar4 = (byte *)&DAT_0086e4ec;
  do {
    if (*(int *)pbVar4 != *(int *)pbVar2) goto LAB_00426433;
    uVar5 = uVar5 - 4;
    pbVar2 = pbVar2 + 4;
    pbVar4 = pbVar4 + 4;
  } while (3 < uVar5);
  if (uVar5 == 0) {
LAB_00426484:
    iVar3 = 0;
  }
  else {
LAB_00426433:
    iVar6 = (uint)*pbVar4 - (uint)*pbVar2;
    if (iVar6 == 0) {
      if (uVar5 == 1) goto LAB_00426484;
      iVar6 = (uint)pbVar4[1] - (uint)pbVar2[1];
      if (iVar6 == 0) {
        if (uVar5 == 2) goto LAB_00426484;
        iVar6 = (uint)pbVar4[2] - (uint)pbVar2[2];
        if (iVar6 == 0) {
          if ((uVar5 == 3) || (iVar6 = (uint)pbVar4[3] - (uint)pbVar2[3], iVar6 == 0))
          goto LAB_00426484;
        }
      }
    }
    iVar3 = 1;
    if (iVar6 < 1) {
      iVar3 = -1;
    }
  }
  if (iVar3 == 0) {
    pbVar2 = (byte *)&DAT_008666b0;
    pbVar4 = (byte *)&DAT_0086e500;
    uVar5 = 0x20;
    do {
      if (*(int *)pbVar4 != *(int *)pbVar2) goto LAB_004264b8;
      uVar5 = uVar5 - 4;
      pbVar2 = pbVar2 + 4;
      pbVar4 = pbVar4 + 4;
    } while (3 < uVar5);
    if (uVar5 == 0) {
LAB_00426509:
      iVar3 = 0;
    }
    else {
LAB_004264b8:
      iVar6 = (uint)*pbVar4 - (uint)*pbVar2;
      if (iVar6 == 0) {
        if (uVar5 == 1) goto LAB_00426509;
        iVar6 = (uint)pbVar4[1] - (uint)pbVar2[1];
        if (iVar6 == 0) {
          if (uVar5 == 2) goto LAB_00426509;
          iVar6 = (uint)pbVar4[2] - (uint)pbVar2[2];
          if (iVar6 == 0) {
            if ((uVar5 == 3) || (iVar6 = (uint)pbVar4[3] - (uint)pbVar2[3], iVar6 == 0))
            goto LAB_00426509;
          }
        }
      }
      iVar3 = 1;
      if (iVar6 < 1) {
        iVar3 = -1;
      }
    }
    if (((iVar3 == 0) && (DAT_0086e520 == DAT_008666d0)) &&
       (DAT_00856900 = 0, DAT_0086e558 == DAT_00866708)) goto LAB_00426536;
  }
  DAT_00856900 = 1;
LAB_00426536:
  if (iVar1 == 0) {
    return;
  }
  FUN_00681f40("menuBack",0);
  DAT_008569ac = 1;
  if ((DAT_0093b338 == 0) && (DAT_00856900 != 0)) {
    FUN_00479da0();
    FUN_004cf4b0();
    iVar1 = FUN_0050c000();
    if (iVar1 == 0) {
      DAT_008569a8 = 1;
      FUN_00509830(1000,0xffffffff,0xffffffff);
      return;
    }
  }
  FUN_004252c0();
  return;
}

