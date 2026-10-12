/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a70e0; label: FUN_005a70e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005a70e0(int param_1,int param_2)

{
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 0) {
    return (uint)(*(char *)(param_1 + 0xd0) != '\0');
  }
  return (uint)(('\x01' << ((byte)param_2 & 0x1f) & *(byte *)(param_1 + 0xd0)) != 0);
}

