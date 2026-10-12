/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611480; label: FUN_00611480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00611480(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  int local_8;
  
  if (*(char *)(in_ECX + 0x10) == '\0') {
    iVar2 = (**(code **)(*DAT_028572e0 + 0x58))(param_1,param_2,param_3);
    return iVar2;
  }
  if (*(int *)(in_ECX + 0x24) == 1) {
    fVar4 = (float10)FUN_005b9dd0();
    if (fVar4 < (float10)*(float *)(in_ECX + 0x34)) {
      return param_2;
    }
  }
  else if (*(int *)(in_ECX + 0x24) == 2) {
    if ((*(int *)(in_ECX + 0x30) == 0) &&
       (fVar4 = (float10)FUN_005b9dd0(), fVar4 < (float10)*(float *)(in_ECX + 0x34))) {
      iVar2 = *(int *)(in_ECX + 0x28);
      FUN_005b9dd0();
      iVar1 = FUN_006e6b90();
      *(int *)(in_ECX + 0x30) = iVar1 + iVar2;
    }
    if (0 < *(int *)(in_ECX + 0x30)) {
      *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -1;
      return param_2;
    }
  }
  if (*(int *)(in_ECX + 0x17c8) <= *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  iVar2 = FUN_00611150(param_3,param_2);
  if (iVar2 == 0) {
    iVar2 = FUN_00633440(0x24,1);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = (undefined4 *)FUN_00611190(param_3);
    }
    iVar2 = FUN_00617a00();
    if (*(int *)(in_ECX + 0x18) < 1) {
      puVar3[7] = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x14);
      fVar4 = (float10)FUN_005b9dd0();
      local_8 = (int)(longlong)ROUND(fVar4 * (float10)(*(int *)(in_ECX + 0x18) - iVar1));
      puVar3[7] = local_8 + iVar1 + iVar2;
    }
    puVar3[8] = iVar2;
    puVar3[6] = *(int *)(in_ECX + 0x3c) + iVar2;
    *puVar3 = 0;
    puVar3[1] = *(undefined4 *)(in_ECX + 8);
    if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
      **(undefined4 **)(in_ECX + 8) = puVar3;
    }
    *(undefined4 **)(in_ECX + 8) = puVar3;
    if (*(int *)(in_ECX + 4) == 0) {
      *(undefined4 **)(in_ECX + 4) = puVar3;
    }
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  }
  FUN_00610c10(param_1,param_2);
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + param_2;
  return param_2;
}

