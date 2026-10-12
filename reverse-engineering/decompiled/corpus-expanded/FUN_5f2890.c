/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f2890; label: FUN_005f2890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f2890(int param_1)

{
  _DAT_0097822c = (param_1 + -0x9740a8) / 0x830;
  (&DAT_00978228)[_DAT_0097822c >> 3] =
       (&DAT_00978228)[_DAT_0097822c >> 3] & ~('\x01' << ((byte)_DAT_0097822c & 7));
  return;
}

