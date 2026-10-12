/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c5cd0; label: FUN_006c5cd0
 */

undefined4 FUN_006c5cd0(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  for (puVar1 = *(undefined4 **)(in_ECX + 0xc); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[3] != 0) {
      (**(code **)(*(int *)puVar1[3] + 8))(param_1);
    }
  }
  return 0;
}

