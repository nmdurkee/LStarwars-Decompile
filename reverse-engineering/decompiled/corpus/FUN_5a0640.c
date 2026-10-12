/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0640; label: FUN_005a0640
 */

void FUN_005a0640(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) && ((*(byte *)(param_1 + 10) & 4) == 0)) {
    FUN_004f1310(*(int *)(param_1 + 0x14),param_1);
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 4;
  }
  return;
}

