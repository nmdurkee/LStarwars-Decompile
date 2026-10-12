/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d8370; label: FUN_005d8370
 */

void FUN_005d8370(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = DAT_009716a0;
  if (DAT_0097396c != 0) {
    if ((param_1 != -1) || (param_2 != 0)) {
      iVar5 = (&DAT_009716a4)[param_1];
      puVar4 = (uint *)(*(int *)(iVar5 + 0x20) + param_2 * 4);
      *puVar4 = *puVar4 ^ 1;
      *(undefined4 *)
       (*(int *)(iVar5 + 8 + (uint)(*(int *)(*(int *)(iVar5 + 0x20) + param_2 * 4) == 0) * 4) +
       param_2 * 4) = 0;
      return;
    }
    iVar6 = 0;
    piVar1 = (int *)(DAT_009716a0 + 4);
    if (0 < *(int *)(DAT_009716a0 + 4)) {
      piVar2 = (int *)(DAT_009716a0 + 0x20);
      do {
        puVar4 = (uint *)(*piVar2 + iVar6 * 4);
        *puVar4 = *puVar4 ^ 1;
        iVar3 = iVar6 * 4;
        iVar6 = iVar6 + 1;
        *(undefined4 *)
         (*(int *)(iVar5 + 8 + (uint)(*(int *)(*piVar2 + iVar3) == 0) * 4) + -4 + iVar6 * 4) = 0;
      } while (iVar6 < *piVar1);
    }
  }
  return;
}

