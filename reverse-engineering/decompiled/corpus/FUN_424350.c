/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x424350; label: FUN_00424350
 */

void FUN_00424350(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    puVar3 = (undefined1 *)(param_1 + 0xa6e);
    puVar4 = &DAT_0085692c;
    puVar2 = (undefined4 *)(param_1 + 0xa70);
    iVar1 = param_1 + 0x178;
    param_1 = 2;
    do {
      *puVar4 = 0;
      FUN_0062e650(iVar1,0xffffffff);
      puVar3[-2] = 0;
      *puVar2 = 0;
      *puVar3 = 2;
      puVar4 = puVar4 + 1;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + 0x48;
      puVar3 = puVar3 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}

