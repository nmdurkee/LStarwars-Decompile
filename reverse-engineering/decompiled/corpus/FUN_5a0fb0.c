/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0fb0; label: FUN_005a0fb0
 */

undefined4 FUN_005a0fb0(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    return 1;
  }
  for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if (puVar1[4] != 0) {
      *(uint *)(puVar1[4] + 0x50) = *(uint *)(puVar1[4] + 0x50) & 0xfffffffe;
      *(uint *)(puVar1[4] + 0x50) = *(uint *)(puVar1[4] + 0x50) & 0xfffffffb;
      *(undefined4 *)(puVar1[4] + 0x4c) = puVar1[6];
      *(undefined4 *)(puVar1[4] + 0x40) = 0x3f800000;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      if ((*(byte *)(param_1 + 10) & 4) != 0) {
        FUN_004f1410(*(int *)(param_1 + 0x14),param_1);
        *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xfffb;
      }
      FUN_005a0670(param_1);
    }
  }
  return 1;
}

