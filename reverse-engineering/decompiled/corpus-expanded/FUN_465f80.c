/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x465f80; label: FUN_00465f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465f80(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != 0) {
    FUN_005a15e0(*(undefined4 *)(unaff_ESI + 0x1c));
    *(ushort *)(unaff_ESI + 0x2a) =
         *(ushort *)(unaff_ESI + 0x2a) ^
         (byte)((unaff_EDI != 0) * '\x02' ^ *(byte *)(unaff_ESI + 0x2a)) & 2;
  }
  return;
}

