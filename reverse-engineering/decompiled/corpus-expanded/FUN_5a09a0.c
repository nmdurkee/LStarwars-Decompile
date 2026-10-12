/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a09a0; label: FUN_005a09a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a09a0(int param_1,undefined4 *param_2)

{
  short *psVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    puVar3 = *(undefined4 **)(param_1 + 0x18);
    if (param_2 == *(undefined4 **)(param_1 + 0x18)) {
      *(undefined4 *)(param_1 + 0x18) = *param_2;
    }
    else {
      do {
        puVar2 = puVar3;
        if (puVar2 == (undefined4 *)0x0) goto LAB_005a09d5;
        puVar3 = (undefined4 *)*puVar2;
      } while ((undefined4 *)*puVar2 != param_2);
      *puVar2 = *param_2;
    }
LAB_005a09d5:
    *param_2 = 0;
    *(char *)(param_1 + 8) = *(char *)(param_1 + 8) + -1;
    psVar1 = (short *)(*(int *)(param_1 + 0x10) + 2);
    *psVar1 = *psVar1 + -1;
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc);
    *(undefined4 **)(*(int *)(param_1 + 0x10) + 0xc) = param_2;
  }
  return;
}

