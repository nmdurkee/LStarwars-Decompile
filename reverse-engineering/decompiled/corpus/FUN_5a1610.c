/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1610; label: FUN_005a1610
 */

void FUN_005a1610(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      FUN_00552760(puVar1 + 1,*(undefined4 *)(puVar1[4] + 0x4c));
    }
  }
  return;
}

