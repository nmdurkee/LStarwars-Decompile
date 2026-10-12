/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x6460e0; label: FUN_006460e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006460e0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_3c;
  undefined1 local_38 [20];
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_3c;
  iVar6 = 1;
  local_3c = param_1;
  _DAT_008101a4 = 1;
  DAT_029209f8 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00646060,"Instance Orphans/Dupes"
                             );
  if ((DAT_029209f8 != 0) && (DAT_02920970 != 0)) {
    iVar5 = 0;
    iVar3 = 0;
    iVar4 = 0x90;
    iVar2 = DAT_02920970;
    do {
      if (*(short *)(iVar2 + iVar4) == 0x270e) {
        FUN_004f1f40(local_38,iVar3 + 0x10 + iVar2,0x11);
        _sprintf(local_24,"Remove - %s",local_38);
        uVar1 = FUN_00627a80(iVar5,&DAT_008109d8,0,iVar6,FUN_00645dc0,local_24);
        FUN_00618e10(DAT_029209f8,uVar1);
        iVar6 = iVar6 + 1;
        iVar2 = DAT_02920970;
      }
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar4 < 0xa0);
    if (DAT_0291f66c == 0) {
      uVar1 = FUN_00627a80(iVar5,&DAT_008109e8,0,0,0,"Remove All Orphans");
    }
    else {
      uVar1 = FUN_00627a80(iVar5,&DAT_008109d8,0,0,FUN_00645e70,"Remove All Orphans");
    }
    FUN_00618e10(DAT_029209f8,uVar1);
    if (DAT_0291f788 == 0) {
      uVar1 = FUN_00627a80(iVar5,&DAT_008109e8,0,0,0,"Remove Duplicates");
    }
    else {
      uVar1 = FUN_00627a80(iVar5,&DAT_008109d8,0,0,&LAB_00645f40,"Remove Duplicates");
    }
    FUN_00618e10(DAT_029209f8,uVar1);
    iVar6 = local_3c;
    FUN_006279b0(local_3c,DAT_029209f8);
    *(int *)(DAT_029209f8 + 0x14) = *(int *)(iVar6 + 0x14) + 10;
    *(int *)(DAT_029209f8 + 0x18) = *(int *)(iVar6 + 0x18) + 0x28;
  }
  __security_check_cookie(local_4 ^ (uint)&local_3c);
  return;
}

