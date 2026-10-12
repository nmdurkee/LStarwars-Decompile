/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566650; label: FUN_00566650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00566650(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00802f68)[iVar1 * 2] == param_1) {
      return (&DAT_00802f6c)[iVar1 * 2];
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return 0;
}

