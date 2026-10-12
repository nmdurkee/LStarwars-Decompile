/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8ae0; label: FUN_005f8ae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

