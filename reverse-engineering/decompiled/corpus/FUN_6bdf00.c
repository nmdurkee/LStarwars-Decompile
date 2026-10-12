/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bdf00; label: FUN_006bdf00
 */

void FUN_006bdf00(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = (undefined4 *)**(undefined4 **)(in_ECX + 8); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if ((int *)puVar1[3] != (int *)0x0) {
      (**(code **)(*(int *)puVar1[3] + 0x14))(param_1,puVar1,&DAT_0081fd1c,&DAT_0081fd2c);
    }
  }
  return;
}

