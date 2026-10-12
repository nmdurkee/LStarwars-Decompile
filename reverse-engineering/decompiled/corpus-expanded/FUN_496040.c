/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x496040; label: FUN_00496040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496040(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  float local_14;
  
  iVar2 = FUN_0055c780(PTR_DAT_00802c54);
  local_14 = 1.5;
  if (iVar2 == 0) {
    if (DAT_0093b338 != 0) {
      iVar7 = (int)DAT_008808d0;
      iVar8 = (int)DAT_008808f0;
      goto LAB_0049613b;
    }
    if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
      iVar7 = (int)DAT_0088082c;
      iVar8 = (int)DAT_00880774;
      goto LAB_0049613b;
    }
    uVar3 = *(undefined4 *)(DAT_00926c20 + DAT_008806dc * 4);
    if (DAT_0093b324 == 0) {
      if (DAT_0093b2a8 == 0) {
        iVar8 = (int)DAT_008808f0;
      }
      else {
        iVar8 = (int)DAT_008808f4;
      }
    }
    else {
      iVar7 = 0;
      if (DAT_00802af8 == -1) goto LAB_00496146;
      if ((*(int *)(&DAT_007f9f5c + DAT_007fa198 * 4) < 1) ||
         ((int)(&DAT_00879544)[DAT_00802af8 == 0] <= (int)(&DAT_00879544)[DAT_00802af8])) {
        iVar8 = (int)DAT_008807b4;
      }
      else {
        iVar8 = (int)DAT_008807b0;
      }
    }
  }
  else {
    iVar7 = (int)DAT_008806dc;
    iVar8 = (int)DAT_008808f0;
    local_14 = 2.0;
LAB_0049613b:
    uVar3 = *(undefined4 *)(DAT_00926c20 + iVar7 * 4);
  }
  iVar7 = *(int *)(DAT_00926c20 + iVar8 * 4);
LAB_00496146:
  if (((DAT_00921d24 == 0) &&
      (FUN_0050d910(uVar3,_DAT_0095137c,*(float *)(param_1 + 0x98) - _DAT_00800994 * local_14,
                    0x3f800000,_DAT_0080098c,_DAT_0080098c,_DAT_0080098c,DAT_00951378,DAT_007facbc,
                    DAT_007facbd,DAT_0087b728,0x3fd9999a,1,0,0,_DAT_00921d60), iVar7 != 0)) &&
     (*(int *)(param_1 + 0x34) == (int)*(short *)(param_1 + 0xe))) {
    FUN_005b7d30(_DAT_00925030,0x3f000000);
    uVar3 = FUN_006e6b90();
    uVar4 = FUN_006e6b90();
    uVar5 = FUN_006e6b90();
    FUN_006e6b90();
    uVar6 = FUN_006e6b90();
    if (iVar2 == 0) {
      fVar1 = 1.0;
    }
    else {
      fVar1 = 2.0;
    }
    FUN_0050d910(iVar7,_DAT_0095137c,
                 _DAT_00800994 * local_14 + *(float *)(param_1 + 0x98) + _DAT_00800994 * fVar1,
                 0x3f800000,_DAT_0080098c,_DAT_0080098c,_DAT_0080098c,DAT_00951378,uVar3,uVar4,uVar5
                 ,0x3fd9999a,1,0,0,uVar6);
  }
  if (iVar2 == 0) {
    FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880844 * 4));
    FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880854 * 4));
    return;
  }
  FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_008806e0 * 4));
  FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880734 * 4));
  FUN_00574de0(param_1,*(undefined4 *)(DAT_00926c20 + DAT_00880870 * 4));
  return;
}

