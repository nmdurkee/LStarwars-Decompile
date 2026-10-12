/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bde00; label: FUN_006bde00
 */

void FUN_006bde00(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  FUN_0061ec10(*(undefined4 *)(in_ECX + 8));
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 8); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((undefined4 *)puVar1[3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar1[3])(1);
      }
    }
  }
  FUN_00624220(*(undefined4 *)(in_ECX + 8));
  return;
}

