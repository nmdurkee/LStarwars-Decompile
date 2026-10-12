/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a1230; label: FUN_005a1230
 */

undefined4 FUN_005a1230(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[4] != 0) {
        *(uint *)(puVar1[4] + 0x50) = *(uint *)(puVar1[4] + 0x50) & 0xfffffffe;
        *(undefined4 *)(puVar1[4] + 0x4c) = puVar1[6];
      }
    }
  }
  return 1;
}

