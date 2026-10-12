/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8390; label: FUN_005a8390
 */

void FUN_005a8390(int *param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  DAT_0095df20 = param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      uVar2 = FUN_0055b1c0(*param_1);
      *(undefined2 *)(param_1 + 4) = uVar2;
      param_1 = param_1 + 5;
      iVar1 = *param_1;
    }
  }
  return;
}

