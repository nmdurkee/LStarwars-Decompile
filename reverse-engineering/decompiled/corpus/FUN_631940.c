/* Ghidra analysis pseudocode, not original source.
 * ev_e26d15e716f54b37dc9752c5bbece96131eaa1b0064d3ed9476ea38cc0029dc6
 * Entry: 0x631940; label: FUN_00631940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00631940(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 unaff_retaddr;
  int in_stack_00000014;
  
  piVar5 = param_1;
  _memset(param_1,0,0x48);
  piVar5[0xb] = 0x3f800000;
  piVar5[0xc] = 0;
  piVar5[10] = 0;
  piVar5[0xd] = in_stack_00000014;
  param_1 = (int *)0x0;
  param_1 = (int *)FUN_004f5240();
  _BinkSetSoundTrack_8(1,&param_1);
  iVar6 = _BinkOpen_8(unaff_retaddr,0x4000);
  *piVar5 = iVar6;
  if (iVar6 != 0) {
    iVar8 = 0;
    iVar10 = 0;
    if (*(int *)(iVar6 + 0xd0) != 0) {
      piVar9 = *(int **)(iVar6 + 0x250);
      do {
        if (*piVar9 == unaff_EBP) goto LAB_00631a03;
        iVar8 = iVar8 + 1;
        piVar9 = piVar9 + 1;
      } while (iVar8 != *(int *)(iVar6 + 0xd0));
      iVar10 = *(int *)(iVar6 + 0xd0);
    }
    if (iVar10 != 0) {
      unaff_EBP = **(int **)(iVar6 + 0x250);
      _BinkClose_4(iVar6);
      _BinkSetSoundTrack_8(1,&stack0xfffffff0);
      iVar6 = _BinkOpen_8(unaff_retaddr,0x4000);
      *piVar5 = iVar6;
    }
LAB_00631a03:
    if (*piVar5 != 0) {
      _DAT_0080fc64 = unaff_retaddr;
      uVar7 = FUN_006e6b90();
      _BinkSetVolume_12(*piVar5,unaff_EBP,uVar7);
      iVar6 = FUN_006332f0(DAT_029131cc,*(undefined4 *)*piVar5,((undefined4 *)*piVar5)[1],0,0x100);
      piVar5[2] = iVar6;
      if (unaff_ESI == 0) {
        piVar5[7] = DAT_02976700;
        piVar5[8] = DAT_02976704;
        FUN_005fb810();
        piVar9 = (int *)*piVar5;
        piVar5[6] = 0;
        fVar1 = (float)*piVar9;
        if (*piVar9 < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        fVar2 = (float)piVar9[1];
        if (piVar9[1] < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        switch(DAT_00826494) {
        default:
          fVar3 = 1.3333334;
          break;
        case 1:
          fVar3 = 1.7777778;
          break;
        case 2:
          fVar3 = 1.6;
          break;
        case 3:
          fVar3 = _DAT_02976bf8;
        }
        fVar4 = (fVar1 / fVar2) / fVar3;
        if (1.0 < fVar4) {
          fVar4 = 1.0;
        }
        fVar3 = fVar3 / (fVar1 / fVar2);
        if (1.0 < fVar3) {
          fVar3 = 1.0;
        }
        fVar1 = (float)*piVar9;
        if (*piVar9 < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        piVar5[0x10] = (int)(((float)piVar5[7] / fVar1) * fVar4);
        fVar1 = (float)piVar9[1];
        if (piVar9[1] < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        piVar5[0x11] = (int)(fVar3 * ((float)piVar5[8] / fVar1));
        fVar1 = (float)*piVar9;
        if (*piVar9 < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        piVar5[0xe] = (int)(((float)piVar5[7] - fVar1 * (float)piVar5[0x10]) * 0.5 + 0.5);
        fVar1 = (float)piVar9[1];
        if (piVar9[1] < 0) {
          fVar1 = fVar1 + 4.2949673e+09;
        }
        piVar5[0xf] = (int)(((float)piVar5[8] - fVar1 * (float)piVar5[0x11]) * 0.5 + 0.5);
        return 1;
      }
      iVar6 = *(int *)*piVar5;
      piVar5[7] = iVar6;
      iVar10 = ((int *)*piVar5)[1];
      piVar5[8] = iVar10;
      iVar6 = FUN_006056f0(iVar6,iVar10,1,1,2);
      piVar5[6] = iVar6;
      FUN_005fb870(iVar6,0,0);
      piVar9 = (int *)*piVar5;
      piVar5[0xe] = 0x3f000000;
      piVar5[0xf] = 0x3f000000;
      fVar1 = (float)*piVar9;
      if (*piVar9 < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      piVar5[0x10] = (int)((float)piVar5[7] / fVar1);
      fVar1 = (float)piVar9[1];
      if (piVar9[1] < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      piVar5[0x11] = (int)((float)piVar5[8] / fVar1);
      return 1;
    }
  }
  return 0;
}

