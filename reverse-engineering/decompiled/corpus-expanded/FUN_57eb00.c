/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57eb00; label: FUN_0057eb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057eb00(int param_1)

{
  uint *puVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 4) == 0)) {
    return 0;
  }
  iVar2 = FUN_0057ccb0(param_1);
  if (iVar2 != 0) {
    return 0;
  }
  FUN_00505e50(*(undefined4 *)(param_1 + 4));
  if (DAT_00951c8c != (code *)0x0) {
    (*DAT_00951c8c)(param_1);
  }
  if ((DAT_00951cb0 != 0) && (*(int *)(DAT_00951cb0 + 4) != 0)) {
    FUN_0057ea60(param_1);
  }
  *(float *)(*(int *)(param_1 + 4) + 0x98) = _DAT_00925018 * *(float *)(param_1 + 0x5c);
  FUN_00505f20(*(undefined4 *)(param_1 + 4));
  if ((*(uint *)(param_1 + 0x50) & 0x200) == 0) {
    puVar1 = (uint *)(*(int *)(param_1 + 4) + 0x88);
    *puVar1 = *puVar1 & 0xfffffff7;
  }
  else {
    puVar1 = (uint *)(*(int *)(param_1 + 4) + 0x88);
    *puVar1 = *puVar1 | 8;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  if (*(int *)(param_1 + 0x18c) == -1) {
    FUN_00652400(0);
    FUN_00652b60(*(undefined4 *)(param_1 + 4),(*(char *)(param_1 + 0xee) != '\0') * '\x02' + '\v');
    *(float *)(*(int *)(param_1 + 4) + 0x98) = _DAT_00925018 * *(float *)(param_1 + 0x5c);
    if ((*(byte *)(param_1 + 0x50) & 1) == 0) {
      return 1;
    }
    DAT_00951c58 = 0;
  }
  else {
    iVar2 = FUN_00694240(0x10,*(int *)(param_1 + 0x18c));
    if (iVar2 == 0) {
      FUN_0057a820(*(undefined4 *)(param_1 + 0x18c));
    }
    iVar3 = thunk_FUN_00696040(0x10,1);
    DAT_00803f78 = DAT_0297dc00;
    iVar2 = 1;
    if (iVar3 != 1) {
      iVar2 = FUN_0057a820(iVar3);
    }
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x98) = 0;
    if (((*(byte *)(param_1 + 0x50) & 1) != 0) && (iVar2 == 1)) {
      DAT_00951c58 = 1;
      FUN_00652400(0);
      DAT_00951c2c = 1;
      goto LAB_0057ec7e;
    }
  }
  DAT_00951c2c = 0;
LAB_0057ec7e:
  if ((*(byte *)(param_1 + 0x50) & 1) != 0) {
    FUN_004ba190();
    piVar4 = *(int **)(in_EAX + 0x2ab0);
    _DAT_00951c54 = 0;
    if (0 < piVar4[1]) {
      do {
        iVar2 = *(int *)(*piVar4 + iVar5 * 4);
        if ((*(byte *)(*(int *)(iVar2 + 4) + 0x88) & 2) != 0) {
          if (((iVar2 == param_1) || (*(int *)(iVar2 + 4) == 0)) ||
             ((*(byte *)(iVar2 + 0x50) & 1) == 0)) {
            *(undefined4 *)(*(int *)(*(int *)(**(int **)(in_EAX + 0x2ab0) + iVar5 * 4) + 4) + 0x98)
                 = 0;
            FUN_00500390(*(undefined4 *)(*(int *)(**(int **)(in_EAX + 0x2ab0) + iVar5 * 4) + 4),1);
          }
          else {
            *(undefined4 *)(*(int *)(*(int *)(**(int **)(in_EAX + 0x2ab0) + iVar5 * 4) + 4) + 0x98)
                 = 0;
            FUN_00505e10(*(undefined4 *)(*(int *)(**(int **)(in_EAX + 0x2ab0) + iVar5 * 4) + 4));
          }
        }
        piVar4 = *(int **)(in_EAX + 0x2ab0);
        iVar5 = iVar5 + 1;
      } while (iVar5 < piVar4[1]);
    }
    FUN_0057ce40();
    _DAT_00950760 = 0x3f800000;
    DAT_00951c78 = 1;
    DAT_00951c70 = 0;
    FUN_00564ca0();
    FUN_0057caa0();
  }
  return 1;
}

