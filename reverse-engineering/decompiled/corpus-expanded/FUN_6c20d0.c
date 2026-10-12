/* Ghidra pseudocode, not original source.
 * ev_8705922c1b0f5911d8582e9aa5172c8d40ef9c41de03e321ff79e08d51867777
 * Entry: 0x6c20d0; label: thunk_FUN_006bde00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_006bde00(void)

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

