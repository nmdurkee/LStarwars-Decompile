/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57edc0; label: FUN_0057edc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057edc0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_0057c9c0(*(undefined4 *)(param_1 + 0x2ab0));
  _DAT_00950760 = 0;
  DAT_00951be8 = 0;
  DAT_00951c58 = 0;
  piVar3 = *(int **)(param_1 + 0x2ab0);
  DAT_00951c2c = 0;
  if (piVar3 == (int *)0x0) {
    _DAT_00950760 = 0;
    DAT_00951be8 = 0;
    DAT_00951c2c = 0;
    DAT_00951c58 = 0;
    DAT_00951c70 = 0;
    DAT_00951c7c = 0;
    return;
  }
  if (DAT_008765c4 == 0) {
    _DAT_00950760 = 0;
    DAT_00951be8 = 0;
    DAT_00951c2c = 0;
    DAT_00951c58 = 0;
    DAT_00951c70 = 0;
    DAT_00951c7c = 0;
    return;
  }
  if ((((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 0xe0) == 0) &&
      (*(int *)(param_1 + 0x130) != 0)) &&
     ((*(byte *)(*(int *)(param_1 + 0x130) + 0x2800) & 2) != 0)) {
    _DAT_00950760 = 0;
    DAT_00951be8 = 0;
    DAT_00951c2c = 0;
    DAT_00951c58 = 0;
    DAT_00951c70 = 0;
    DAT_00951c7c = 0;
    return;
  }
  iVar2 = 0;
  if (((DAT_00951cb0 != 0) && (iVar4 = *(int *)(DAT_00951cb0 + 4), iVar4 != 0)) && (0 < piVar3[1]))
  {
    if ((*(char *)(iVar4 + 4) != '\0') && (iVar2 = FUN_0057c970(piVar3,iVar4 + 4), iVar2 != 0))
    goto LAB_0057ee97;
    piVar3 = *(int **)(param_1 + 0x2ab0);
    iVar2 = *(int *)*piVar3;
    if (iVar2 != 0) goto LAB_0057ee97;
  }
  iVar4 = 0;
  do {
    if (piVar3[1] <= iVar4) {
      if (iVar2 == 0) {
        DAT_00951c70 = 0;
        DAT_00951c7c = 0;
        return;
      }
      break;
    }
    iVar1 = *(int *)(*piVar3 + iVar4 * 4);
    if ((*(uint *)(iVar1 + 0x50) & 0x1000) == 0) {
      iVar4 = iVar4 + 1;
      iVar1 = iVar2;
    }
    iVar2 = iVar1;
  } while (iVar2 == 0);
LAB_0057ee97:
  iVar2 = FUN_0057eb00(iVar2);
  if (iVar2 != 0) {
    _DAT_00950760 = 0x3f800000;
  }
  DAT_00951c7c = 0;
  DAT_00951c70 = 0;
  return;
}

