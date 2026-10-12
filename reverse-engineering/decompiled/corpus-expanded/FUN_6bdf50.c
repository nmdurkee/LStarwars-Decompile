/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bdf50; label: FUN_006bdf50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

