/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0a00; label: FUN_005a0a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0a00(int param_1)

{
  short *psVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    while (iVar2 != 0) {
      puVar3 = *(undefined4 **)(param_1 + 0x18);
      if (puVar3 != (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x18) = *puVar3;
        *puVar3 = 0;
        *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + -1;
        psVar1 = (short *)(*(int *)(param_1 + 0x10) + 2);
        *psVar1 = *psVar1 + -1;
        *puVar3 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc);
        *(undefined4 **)(*(int *)(param_1 + 0x10) + 0xc) = puVar3;
      }
      iVar2 = *(int *)(param_1 + 0x18);
    }
  }
  return;
}

