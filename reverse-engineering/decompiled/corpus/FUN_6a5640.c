/* Ghidra analysis pseudocode, not original source.
 * ev_84e5cb8303fa38d748e4458d34c9d4265893eb5844f058a0a1436ec0ce38dbe0
 * Entry: 0x6a5640; label: FUN_006a5640
 */

void FUN_006a5640(int param_1,int param_2,int param_3,undefined4 param_4,float param_5)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *unaff_EBX;
  int iVar8;
  
  fVar2 = *(float *)(unaff_EBX[1] + 0x1f0);
  iVar4 = *unaff_EBX;
  iVar8 = 0;
  if (0 < iVar4) {
    do {
      fVar3 = *(float *)(param_2 + iVar8 * 4);
      iVar5 = unaff_EBX[5];
      iVar7 = *(int *)(iVar5 + iVar8 * 4);
      iVar6 = iVar8;
      while ((iVar6 = iVar6 + 1, iVar6 < iVar4 && (*(int *)(iVar5 + 4 + iVar8 * 4) == iVar7))) {
        iVar1 = iVar8 * 4;
        iVar8 = iVar8 + 1;
        if (fVar3 < *(float *)(param_2 + 4 + iVar1)) {
          fVar3 = *(float *)(param_2 + iVar8 * 4);
        }
      }
      if (*(float *)(param_3 + iVar8 * 4) < fVar3 + 6.0) {
        iVar7 = iVar7 >> ((byte)unaff_EBX[8] & 0x1f);
        if (iVar7 < 0x11) {
          if (iVar7 < 0) {
            iVar7 = 0;
          }
        }
        else {
          iVar7 = 0x10;
        }
        FUN_006a5490(*(undefined4 *)(param_1 + iVar7 * 4),fVar3,
                     *(int *)(iVar5 + iVar8 * 4) - unaff_EBX[7],unaff_EBX[10],unaff_EBX[9],
                     fVar2 - param_5);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar4);
  }
  return;
}

