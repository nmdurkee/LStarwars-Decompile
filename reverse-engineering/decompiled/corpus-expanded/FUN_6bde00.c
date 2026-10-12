/* Ghidra pseudocode, not original source.
 * ev_4005f8bc77e113ad185f3b0c9eec9d65d23a3485fd73b1b18a7c340409abf10a
 * Entry: 0x6bde00; label: FUN_006bde00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

