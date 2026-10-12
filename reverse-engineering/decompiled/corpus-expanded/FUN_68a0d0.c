/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x68a0d0; label: FUN_0068a0d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0068a0d0(int param_1)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  int local_18;
  undefined1 local_c [12];
  
  iVar7 = 0;
  pcVar2 = "Change Instance (Filtered)";
  if (DAT_029629d4 == 0) {
    pcVar2 = "Change Instance";
  }
  DAT_02962994 = FUN_00619250(0x46,0x46,0xdc,0xfa,DAT_02912e80,FUN_0065ec60,pcVar2);
  if (DAT_02962994 == 0) {
    return;
  }
  if (DAT_02962114 == 0) {
    return;
  }
  bVar1 = false;
  local_18 = 1;
  iVar3 = FUN_005cfed0(DAT_02962114);
  if (0 < iVar3) {
    uVar6 = 0;
    do {
      FUN_005da860(local_c,DAT_02962114,iVar7);
      iVar4 = FUN_005cfac0(local_c);
      if (iVar4 != 0) {
        uVar6 = FUN_005cfa50(local_c);
      }
      bVar8 = *(int *)(DAT_02921884 * 0x50 + DAT_02962a14) == iVar7;
      FUN_005da860(local_c,DAT_02962114,iVar7);
      iVar4 = FUN_005cfac0(local_c);
      if (iVar4 != 0) {
        uVar6 = FUN_005cfa50(local_c);
      }
      if (DAT_029629d4 == 0) {
LAB_0068a200:
        uVar5 = FUN_00627b80(iVar7,&DAT_008109d8,bVar8,1,FUN_00689fe0,uVar6);
        FUN_00618e10(DAT_02962994,uVar5);
        local_18 = local_18 + 1;
        if (bVar8) {
          *(undefined4 *)(DAT_02962994 + 8) = DAT_02900c84;
          bVar1 = true;
        }
      }
      else {
        uVar5 = FUN_004f1ff0(s_GRASS_00810a78);
        iVar4 = FUN_004f2130(s_GRASS_00810a78,uVar6,uVar5);
        if ((iVar4 == 0) || (bVar8)) goto LAB_0068a200;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3);
    if (local_18 != 1) goto LAB_0068a27e;
  }
  uVar6 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"All Instances Filtered");
  FUN_00618e10(DAT_02962994,uVar6);
LAB_0068a27e:
  FUN_006279b0(param_1,DAT_02962994);
  *(int *)(DAT_02962994 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02962994 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  if (bVar1) {
    *(undefined4 *)(DAT_02962994 + 0xc) = *(undefined4 *)(DAT_02962994 + 8);
  }
  return;
}

