/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fb550; label: FUN_004fb550
 */

int FUN_004fb550(int param_1,void *param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  if (0xfff < param_1) {
    iVar4 = FUN_006dee50(param_1 + -0x1000,param_2,param_3,0);
    return iVar4;
  }
  if (0x3ff < param_1) {
    iVar4 = FUN_004fb4f0();
    return iVar4;
  }
  iVar4 = (param_1 + -1) * 0x40;
  if (*(int *)(&DAT_008ceb7c + iVar4) == 0) {
    iVar4 = FUN_004ff3b0();
    return iVar4;
  }
  if (*(int *)(&DAT_008ceb88 + iVar4) == 0) {
    FUN_004f0230();
  }
  param_1 = 0;
  do {
    if ((int)param_3 < 1) {
      return param_1;
    }
    iVar2 = *(int *)(&DAT_008ceb5c + iVar4);
    uVar7 = *(uint *)(&DAT_008ceb58 + iVar4);
    if (*(int *)(&DAT_008ceb6c + iVar4) < iVar2) {
      return param_1;
    }
    if ((*(int *)(&DAT_008ceb6c + iVar4) <= iVar2) && (*(uint *)(&DAT_008ceb68 + iVar4) <= uVar7)) {
      return param_1;
    }
    iVar6 = *(int *)(&DAT_008ceb74 + iVar4);
    uVar5 = *(uint *)(&DAT_008ceb70 + iVar4);
    if ((iVar2 < iVar6) || ((iVar2 <= iVar6 && (uVar7 < uVar5)))) {
LAB_004fb60c:
      if ((uVar7 != *(uint *)(&DAT_008ceb60 + iVar4)) || (iVar2 != *(int *)(&DAT_008ceb64 + iVar4)))
      {
        FUN_004ff430(*(undefined4 *)(&DAT_008ceb50 + iVar4),uVar7,iVar2,0);
        *(undefined4 *)(&DAT_008ceb60 + iVar4) = *(undefined4 *)(&DAT_008ceb58 + iVar4);
        *(undefined4 *)(&DAT_008ceb64 + iVar4) = *(undefined4 *)(&DAT_008ceb5c + iVar4);
      }
      uVar5 = FUN_004ff3b0(*(undefined4 *)(&DAT_008ceb50 + iVar4),
                           *(int *)(&DAT_008ceb88 + iVar4) + 8,0x400);
      uVar7 = *(uint *)(&DAT_008ceb60 + iVar4);
      *(uint *)(&DAT_008ceb78 + iVar4) = uVar5;
      *(uint *)(&DAT_008ceb70 + iVar4) = uVar7;
      *(int *)(&DAT_008ceb74 + iVar4) = *(int *)(&DAT_008ceb64 + iVar4);
      *(uint *)(&DAT_008ceb60 + iVar4) = uVar5 + uVar7;
      *(uint *)(&DAT_008ceb64 + iVar4) =
           ((int)uVar5 >> 0x1f) + *(int *)(&DAT_008ceb64 + iVar4) + (uint)CARRY4(uVar5,uVar7);
    }
    else {
      uVar3 = *(uint *)(&DAT_008ceb78 + iVar4);
      iVar6 = ((int)uVar3 >> 0x1f) + iVar6 + (uint)CARRY4(uVar3,uVar5);
      if ((iVar6 <= iVar2) && ((iVar6 < iVar2 || (uVar3 + uVar5 <= uVar7)))) goto LAB_004fb60c;
    }
    uVar7 = (*(int *)(&DAT_008ceb78 + iVar4) - *(int *)(&DAT_008ceb58 + iVar4)) +
            *(int *)(&DAT_008ceb70 + iVar4);
    if ((int)param_3 <= (int)uVar7) {
      uVar7 = param_3;
    }
    if (uVar7 != 0) {
      _memcpy(param_2,(void *)((*(int *)(&DAT_008ceb88 + iVar4) - *(int *)(&DAT_008ceb70 + iVar4)) +
                               8 + *(int *)(&DAT_008ceb58 + iVar4)),uVar7);
    }
    param_2 = (void *)((int)param_2 + uVar7);
    param_1 = param_1 + uVar7;
    param_3 = param_3 - uVar7;
    puVar1 = (uint *)(&DAT_008ceb58 + iVar4);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + uVar7;
    *(uint *)(&DAT_008ceb5c + iVar4) =
         *(int *)(&DAT_008ceb5c + iVar4) + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar5,uVar7);
  } while( true );
}

