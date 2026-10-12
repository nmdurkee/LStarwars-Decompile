/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fb960; label: FUN_004fb960
 */

int FUN_004fb960(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  longlong lVar9;
  
  DAT_0091eea4 = 0;
  iVar3 = FUN_004f9bd0(param_1,param_2,0);
  if (iVar3 != 0) {
    if (*(short *)(param_1 + 0xb2) == 3) {
      do {
        iVar4 = FUN_004f01f0(iVar3);
      } while (iVar4 != 0);
    }
    iVar4 = (iVar3 * 3 + -0x1800) * 0x10;
    if (*(int *)(&DAT_0297dc88 + iVar4) == 0) {
      iVar7 = *(int *)(&DAT_0297dc78 + iVar4);
    }
    else {
      iVar7 = *(int *)(&DAT_0297dc7c + iVar4);
    }
    if (param_4 < iVar7) {
      if (iVar7 != 0) {
        DAT_0091eea4 = 0xffffffff;
      }
    }
    else if (iVar7 != 0) {
      iVar5 = FUN_004faf60(iVar3,param_3,iVar7);
      while (iVar5 < 0) {
        do {
          FUN_004ef7b0();
          iVar5 = (int)*(longlong *)(&DAT_0297dc68 + iVar4);
          uVar1 = *(undefined4 *)(&DAT_0297dc6c + iVar4);
          lVar9 = *(longlong *)(&DAT_0297dc68 + iVar4);
          piVar8 = (int *)((*(int *)(&DAT_0297dc80 + iVar4) + 3) * 0x10 +
                          *(int *)(&DAT_0297dc60 + iVar4));
          iVar2 = *piVar8;
          if (iVar2 < 0x1000) {
            if (iVar2 < 0x400) {
              iVar6 = (iVar2 + -1) * 0x40;
              if (*(int *)(&DAT_008ceb7c + iVar6) == 0) {
                lVar9 = FUN_004ff430(iVar2 + -1,iVar5,uVar1,0);
              }
              else {
                *(int *)(&DAT_008ceb58 + iVar6) = iVar5;
                *(undefined4 *)(&DAT_008ceb5c + iVar6) = uVar1;
              }
            }
            else if (iVar2 < 0x800) {
              iVar2 = iVar2 * 5 + -0x1400;
              iVar5 = iVar5 + *(int *)(&DAT_02983740 + iVar2 * 4);
              *(int *)(&DAT_02983748 + iVar2 * 4) = iVar5;
              lVar9 = (longlong)(iVar5 - *(int *)(&DAT_02983740 + iVar2 * 4));
            }
            else {
              lVar9 = FUN_004f0ae0(iVar2,iVar5,iVar5 >> 0x1f,0);
            }
          }
          else {
            iVar5 = FUN_006dee90(iVar2 + -0x1000,iVar5,0,0);
            lVar9 = (longlong)iVar5;
          }
          *(longlong *)(&DAT_0297dc70 + iVar4) = lVar9;
          *(longlong *)(piVar8 + 2) = lVar9;
        } while ((*(int *)(&DAT_0297dc74 + iVar4) < 1) && (*(int *)(&DAT_0297dc74 + iVar4) < 0));
        iVar5 = FUN_004faf60(iVar3,param_3,iVar7);
      }
      if (*(short *)(param_1 + 0xb2) == 3) {
        do {
          iVar4 = FUN_004f01f0(iVar3);
        } while (iVar4 != 0);
      }
      FUN_004f99e0(iVar3);
      return iVar7;
    }
    FUN_004f99e0(iVar3);
  }
  return 0;
}

