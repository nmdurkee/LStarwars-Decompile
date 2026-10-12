/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6be2b0; label: FUN_006be2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_006be2b0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(*(int *)(in_ECX + 0x14) + param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if ((*(uint *)(in_ECX + 0x1c) & 0x40000000) != 0) {
    return (undefined4 *)*puVar1;
  }
  return puVar1;
}

