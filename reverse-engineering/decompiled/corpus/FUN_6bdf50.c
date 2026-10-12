/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bdf50; label: FUN_006bdf50
 */

void FUN_006bdf50(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 8) + 0xc);
  FUN_005d1740(DAT_02973a78);
  FUN_005d1750(DAT_0081f99c,DAT_0081f99c);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    if ((int *)puVar1[3] != (int *)0x0) {
      (**(code **)(*(int *)puVar1[3] + 4))();
    }
    if (puVar1 == *(undefined4 **)(*(int *)(param_1 + 8) + 0x10)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}

