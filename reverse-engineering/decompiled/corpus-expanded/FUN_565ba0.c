/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x565ba0; label: FUN_00565ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565ba0(void)

{
  if (DAT_00950740 != '\0') {
    DAT_00950740 = '\0';
    FUN_005d4290(1);
    FUN_005d5220(DAT_0095076c);
    FUN_005f3950();
    _DAT_00950774 = 0;
  }
  return;
}

