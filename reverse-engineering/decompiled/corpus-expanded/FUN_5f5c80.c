/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5c80; label: FUN_005f5c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f5c80(int param_1)

{
  _DAT_0097822c = (param_1 + -0x9740a8) / 0x830;
  (&DAT_00978228)[_DAT_0097822c >> 3] =
       (&DAT_00978228)[_DAT_0097822c >> 3] & ~('\x01' << ((byte)_DAT_0097822c & 7));
  return;
}

