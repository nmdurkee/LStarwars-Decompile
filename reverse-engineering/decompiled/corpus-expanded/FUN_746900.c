/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746900; label: FUN_00746900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00746900(byte *param_1)

{
  byte bVar1;
  
  if (((byte)(&DAT_0297daa0)[*param_1] >> 1 & 1) != 0) {
    bVar1 = param_1[1];
    while( true ) {
      if (bVar1 == 0) {
        return 1;
      }
      if (((byte)(&DAT_0297daa0)[bVar1] >> 1 & 1) == 0) break;
      bVar1 = param_1[2];
      param_1 = param_1 + 1;
    }
  }
  return 0;
}

