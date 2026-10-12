/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a1d30; label: FUN_006a1d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a1d30(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 0x68);
  if (*(void **)(iVar3 + 0x40) != (void *)0x0) {
    _free(*(void **)(iVar3 + 0x40));
  }
  *(undefined4 *)(iVar3 + 0x40) = 0;
  if (*(void **)(iVar3 + 0x44) != (void *)0x0) {
    _free(*(void **)(iVar3 + 0x44));
  }
  *(undefined4 *)(iVar3 + 0x44) = 0;
  if (*(void **)(iVar3 + 0x48) != (void *)0x0) {
    _free(*(void **)(iVar3 + 0x48));
  }
  *(undefined4 *)(iVar3 + 0x48) = 0;
  if ((*(int *)(param_1 + 0x10) <= *(int *)(param_1 + 0x14) + param_2) &&
     (*(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x14) + param_2 * 2, 0 < *(int *)(iVar1 + 4))) {
    iVar3 = 0;
    do {
      pvVar2 = _realloc(*(void **)(*(int *)(param_1 + 8) + iVar3 * 4),*(int *)(param_1 + 0x10) * 4);
      *(void **)(*(int *)(param_1 + 8) + iVar3 * 4) = pvVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 4));
  }
  iVar3 = 0;
  if (0 < *(int *)(iVar1 + 4)) {
    do {
      *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 4) =
           *(int *)(*(int *)(param_1 + 8) + iVar3 * 4) + *(int *)(param_1 + 0x14) * 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(iVar1 + 4));
  }
  return *(undefined4 *)(param_1 + 0xc);
}

