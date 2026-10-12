/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c58a0; label: FUN_006c58a0
 */

void FUN_006c58a0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    for (puVar2 = *(undefined4 **)puVar1[2]; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if ((int *)puVar2[3] != (int *)0x0) {
        (**(code **)(*(int *)puVar2[3] + 0x14))(param_1,puVar2,&DAT_0081fd1c,&DAT_0081fd2c);
      }
    }
  }
  return;
}

