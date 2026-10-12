/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x645980; label: FUN_00645980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00645980(int param_1)

{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int local_20;
  undefined4 local_1c;
  undefined1 local_c [12];
  
  iVar9 = 0;
  bVar2 = false;
  _DAT_008101a4 = 0;
  pcVar3 = "World Scene (Filtered)";
  if (DAT_02920994 == 0) {
    pcVar3 = "World Scene";
  }
  DAT_029209b8 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00645960,pcVar3);
  if (DAT_029209b8 == 0) {
    return;
  }
  if (DAT_02962114 == 0) {
    return;
  }
  if (DAT_02920970 == 0) {
    return;
  }
  local_20 = 1;
  iVar4 = FUN_005da840(DAT_02962114);
  if (0 < iVar4) {
    do {
      iVar8 = 0;
      bVar1 = false;
      local_1c = 0;
      FUN_005da860(local_c,DAT_02962114,iVar9);
      iVar5 = FUN_005cfac0(local_c);
      if (iVar5 != 0) {
        local_1c = FUN_005cfa50(local_c);
      }
      iVar5 = 0;
      if (0 < *(char *)(DAT_02920970 + 0xb0)) {
        psVar7 = (short *)(DAT_02920970 + 0x90);
        do {
          if ((*psVar7 == iVar9) && (*(char *)(DAT_02920970 + 0xa0 + iVar5) == '\0')) {
            iVar8 = 1;
            bVar1 = true;
          }
          iVar5 = iVar5 + 1;
          psVar7 = psVar7 + 1;
        } while (iVar5 < *(char *)(DAT_02920970 + 0xb0));
      }
      if (DAT_02920994 == 0) {
LAB_00645ac5:
        uVar6 = FUN_00627bc0(iVar9,&DAT_008109d8,iVar8,local_20,FUN_006457f0,local_1c);
        FUN_00618e10(DAT_029209b8,uVar6);
        local_20 = local_20 + 1;
        if ((iVar8 != 0) && (!bVar2)) {
          bVar2 = true;
          *(undefined4 *)(DAT_029209b8 + 8) = DAT_02900c84;
        }
      }
      else {
        uVar6 = FUN_004f1ff0(&DAT_008101a8);
        iVar5 = FUN_004f2130(&DAT_008101a8,local_1c,uVar6);
        if ((iVar5 == 0) || (bVar1)) goto LAB_00645ac5;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar4);
    if (local_20 != 1) goto LAB_00645b51;
  }
  uVar6 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"All Instances Filtered");
  FUN_00618e10(DAT_029209b8,uVar6);
LAB_00645b51:
  FUN_006279b0(param_1,DAT_029209b8);
  *(int *)(DAT_029209b8 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_029209b8 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}

