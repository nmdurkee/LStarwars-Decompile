/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x616230; label: FUN_00616230
 */

undefined4 FUN_00616230(ushort *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_EDI;
  short sVar5;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  undefined **local_24 [2];
  undefined4 local_1c;
  int *local_4;
  
  iVar2 = *(ushort *)((int)param_2 + 0x16) + 10;
  if ((*(byte *)((int)param_2 + 0xe) & 1) == 0) {
    piVar3 = (int *)FUN_00615f40(iVar2);
  }
  else {
    piVar3 = (int *)FUN_00615e90(iVar2);
  }
  FUN_006c0780();
  local_30 = (uint)param_1[1];
  local_1c = 2;
  local_24[0] = &PTR_LAB_0076ac0c;
  local_34 = FUN_006be780(*(undefined4 *)(param_1 + 8));
  local_38 = (uint)*param_1;
  local_34 = local_34 & 0xffff;
  local_2c[0] = (uint)*(ushort *)(param_2 + 3);
  param_4 = CONCAT31(param_4._1_3_,2);
  if (piVar3[1] != 0) {
    FUN_004ef660(piVar3[3] + piVar3[1],&param_4,1);
    piVar3[3] = piVar3[3] + 1;
  }
  if (piVar3[1] != 0) {
    FUN_004ef660(piVar3[3] + piVar3[1],&local_30,2);
    if (*piVar3 != 0) {
      FUN_00621180(piVar3[3] + piVar3[1]);
    }
    piVar3[3] = piVar3[3] + 2;
  }
  if (piVar3[1] != 0) {
    FUN_004ef660(piVar3[3] + piVar3[1],&local_34,2);
    if (*piVar3 != 0) {
      FUN_00621180(piVar3[3] + piVar3[1]);
    }
    piVar3[3] = piVar3[3] + 2;
  }
  if (piVar3[1] != 0) {
    FUN_004ef660(piVar3[3] + piVar3[1],local_2c,2);
    if (*piVar3 != 0) {
      FUN_00621180(piVar3[3] + piVar3[1]);
    }
    piVar3[3] = piVar3[3] + 2;
  }
  if (piVar3[1] != 0) {
    FUN_004ef660(piVar3[3] + piVar3[1],&local_38,2);
    if (*piVar3 != 0) {
      FUN_00621180(piVar3[3] + piVar3[1]);
    }
    piVar3[3] = piVar3[3] + 2;
  }
  if (piVar3[1] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = piVar3[3] - piVar3[2];
  }
  sVar5 = (short)&local_38;
  local_4 = piVar3;
  iVar4 = (**(code **)(*param_2 + 4))
                    (local_24,0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 6),param_3);
  if ((iVar4 == 0) && (piVar3[1] != 0)) {
    piVar3[3] = piVar3[3] + -9;
  }
  piVar1 = (int *)(unaff_EDI + 0xd8ec + sVar5 * 4);
  if (*(int *)(unaff_EDI + 0xd8ec + sVar5 * 4) != 0) {
    if (piVar3[1] == 0) {
      piVar3 = (int *)(*piVar1 + 8);
      *piVar3 = *piVar3 - iVar2;
      return 1;
    }
    piVar1 = (int *)(*piVar1 + 8);
    *piVar1 = *piVar1 + ((piVar3[3] - piVar3[2]) - iVar2);
  }
  return 1;
}

