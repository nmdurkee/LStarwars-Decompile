/* Ghidra analysis pseudocode, not original source.
 * ev_a85358c7a67f9df9af49bd13a9e5d6f2df9e1c4faca93f034535aa61df0d1386
 * Entry: 0x5f8ae0; label: FUN_005f8ae0
 */

uint FUN_005f8ae0(int param_1)

{
  if ((param_1 != DAT_02854bc8) && (param_1 != DAT_02854bcc)) {
    if (param_1 != 0) {
      return (uint)*(ushort *)(param_1 + 0x14);
    }
    return 0;
  }
  return DAT_02976700;
}

