/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c9df0; label: FUN_006c9df0
 */

undefined4 FUN_006c9df0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x24);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if ((puVar1[3] == *(int *)(param_1 + 4)) && (puVar1[4] == *(int *)(param_1 + 8))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}

