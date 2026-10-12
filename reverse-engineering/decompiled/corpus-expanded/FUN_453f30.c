/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x453f30; label: FUN_00453f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00453f30(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float10 fVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char *local_18;
  char *local_14;
  char *local_10;
  undefined1 local_c [12];
  
  if (((param_3 == 0) || (piVar1 = *(int **)(param_3 + 0xd0), piVar1 == (int *)0x0)) ||
     (*piVar1 == 0)) {
    return 1;
  }
  iVar7 = *piVar1;
  if (((((*(int *)(DAT_0093d810 + 0x1040) == 0) ||
        (iVar5 = *(int *)(*(int *)(DAT_0093d810 + 0x1040) + 4), iVar5 == 0)) ||
       (iVar3 = DAT_0093d810, *(short *)(iVar5 + 0x1064) != DAT_007f191c)) &&
      (((DAT_0093d814 == 0 || (*(int *)(DAT_0093d814 + 0x1040) == 0)) ||
       ((iVar5 = *(int *)(*(int *)(DAT_0093d814 + 0x1040) + 4), iVar5 == 0 ||
        (iVar3 = DAT_0093d814, *(short *)(iVar5 + 0x1064) != DAT_007f191c)))))) ||
     ((iVar5 == 0 || (iVar3 == 0)))) {
    if (*(undefined4 **)(iVar7 + 0x1040) != (undefined4 *)0x0) {
      **(undefined4 **)(iVar7 + 0x1040) = 0;
      *(undefined4 *)(iVar7 + 0x1040) = 0;
    }
    uVar9 = *(undefined4 *)(param_3 + 0x180);
    uVar8 = 4;
    iVar7 = 0;
    uVar4 = 0;
    iVar5 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(iVar7 + 0x1040);
    if ((puVar2 != (undefined4 *)0x0) && (puVar2[1] != iVar5)) {
      *puVar2 = 0;
      *(undefined4 *)(iVar7 + 0x1040) = 0;
    }
    if (*(int *)(iVar7 + 0x1040) == 0) {
      fVar6 = (float10)FUN_005b3cf0(iVar7 + 0x80,iVar5 + 0x80,local_c);
      if ((float)fVar6 < _DAT_007f1050 * _DAT_007f1050 * 0.5) {
        uVar4 = FUN_00408880(iVar7,iVar5,1);
        *(undefined4 *)(iVar7 + 0x1040) = uVar4;
      }
      if (*(int *)(iVar7 + 0x1040) == 0) {
        uVar9 = 0;
        iVar7 = iVar5 + 0x420;
        uVar4 = *(undefined4 *)(iVar5 + 1000);
        uVar8 = 1;
        iVar5 = iVar5 + 0x438;
        goto LAB_004540ec;
      }
    }
    iVar5 = *(int *)(iVar7 + 0x36c);
    if (iVar5 == 0) {
      iVar7 = iVar3 + 0x420;
      uVar9 = 0x42c60000;
      uVar8 = 2;
      uVar4 = *(undefined4 *)(iVar3 + 1000);
      iVar5 = iVar3 + 0x438;
    }
    else {
      iVar7 = iVar5 + 0x20;
      uVar9 = 0;
      iVar5 = iVar5 + 0x10;
      uVar8 = 1;
      uVar4 = 0;
    }
  }
LAB_004540ec:
  FUN_0052fcb0(param_3,iVar5,uVar4,iVar7,uVar8,uVar9);
  local_18 = "goalrange 10";
  local_14 = "firerange 15";
  local_10 = "fireinterval 1.5";
  FUN_00447f00(param_1,param_2,param_3,&local_18,3,param_6,param_7);
  return 0;
}

