/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65ea70; label: FUN_0065ea70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065ea70(int param_1)

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
  pcVar2 = "Base Instance Select (Filtered)";
  if (DAT_029629d4 == 0) {
    pcVar2 = "Base Instance Select";
  }
  DAT_02962990 = FUN_00619250(0x46,0x46,0xdc,0xfa,DAT_02912e80,FUN_0065ea50,pcVar2);
  if (DAT_02962990 == 0) {
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
      bVar8 = DAT_029211ec == iVar7;
      if (DAT_029629d4 == 0) {
LAB_0065eb61:
        uVar5 = FUN_00627b80(iVar7,&DAT_008109d8,bVar8,1,FUN_0065ea10,uVar6);
        FUN_00618e10(DAT_02962990,uVar5);
        local_18 = local_18 + 1;
        if (bVar8) {
          *(undefined4 *)(DAT_02962990 + 8) = DAT_02900c84;
          bVar1 = true;
        }
      }
      else {
        uVar5 = FUN_004f1ff0(s_GRASS_00810a78);
        iVar4 = FUN_004f2130(s_GRASS_00810a78,uVar6,uVar5);
        if ((iVar4 == 0) || (bVar8)) goto LAB_0065eb61;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar3);
    if (local_18 != 1) goto LAB_0065ebe0;
  }
  uVar6 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"All Instances Filtered");
  FUN_00618e10(DAT_02962990,uVar6);
LAB_0065ebe0:
  uVar6 = FUN_00627b80(0xffffffff,&DAT_008109d8,DAT_029211ec == -1,1,FUN_0065ea10,&DAT_00763b90);
  FUN_00618e50(DAT_02962990,uVar6);
  FUN_006279b0(param_1,DAT_02962990);
  *(int *)(DAT_02962990 + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02962990 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  if (bVar1) {
    *(undefined4 *)(DAT_02962990 + 0xc) = *(undefined4 *)(DAT_02962990 + 8);
  }
  return;
}

