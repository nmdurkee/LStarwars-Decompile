/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x613f40; label: FUN_00613f40
 */

void FUN_00613f40(int *param_1)

{
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  short local_48 [2];
  short local_44 [2];
  short local_40 [2];
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined **local_24;
  undefined4 local_1c;
  int *piStack_18;
  undefined4 uStack_c;
  undefined4 local_4;
  
  FUN_006c0780();
  local_1c = 1;
  local_24 = &PTR_LAB_0076abe8;
  local_4 = 0;
  local_3c = 0;
  if (param_1[1] != 0) {
    FUN_004ef660(local_44,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_44);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_48,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_48);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(local_40,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(local_40);
    }
    param_1[2] = param_1[2] + 2;
  }
  if (param_1[1] != 0) {
    FUN_004ef660(&local_38,param_1[2] + param_1[1],2);
    if (*param_1 != 0) {
      FUN_00621180(&local_38);
    }
    param_1[2] = param_1[2] + 2;
  }
  iVar3 = FUN_006be7f0((int)local_48[0]);
  puVar1 = (ushort *)(in_ECX + (local_44[0] + 2) * 0x18);
  *puVar1 = (ushort)local_38 | 8;
  for (piVar2 = *(int **)(in_ECX + 0xd1b4 + local_48[0] * 0xc);
      (piVar2 != (int *)0x0 && ((uint)*(ushort *)(piVar2 + 3) != (int)local_40[0]));
      piVar2 = (int *)piVar2[1]) {
    local_3c = local_3c + (uint)*(ushort *)(piVar2 + 5);
  }
  if ((*(int *)(puVar1 + 6) != 0) && (*(int *)(puVar1 + 8) == iVar3)) {
    if ((local_38 & 2) != 0) {
      *(ushort *)((int)piVar2 + 0xe) = *(ushort *)((int)piVar2 + 0xe) | 8;
    }
    local_34 = *(int *)(puVar1 + 10) + local_3c;
    local_30 = local_34 + (uint)*(ushort *)(piVar2 + 5);
    local_2c = local_34;
    (**(code **)*piVar2)(*(undefined4 *)(puVar1 + 8),*(undefined4 *)(puVar1 + 6),&local_34,1,0);
    piStack_18 = param_1;
    (**(code **)(*piVar2 + 4))
              (&local_38,uStack_c,*(undefined4 *)(puVar1 + 8),*(undefined4 *)(puVar1 + 6),local_48,
               puVar1);
    return;
  }
  if (param_1[1] != 0) {
    param_1[2] = param_1[2] + (uint)*(ushort *)((int)piVar2 + 0x16);
  }
  return;
}

