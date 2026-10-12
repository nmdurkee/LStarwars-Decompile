/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64b160; label: FUN_0064b160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0064b160(int param_1)

{
  if (-1 < param_1) {
    return (float10)((float)(&DAT_02913b48)[param_1 * 0x5e] + (float)(&DAT_02913b44)[param_1 * 0x5e]
                    );
  }
  return (float10)0;
}

