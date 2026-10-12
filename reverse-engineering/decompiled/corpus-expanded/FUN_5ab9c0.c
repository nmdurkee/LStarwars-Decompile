/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab9c0; label: FUN_005ab9c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab9c0(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != 0) {
    FUN_005a15e0(*(undefined4 *)(unaff_ESI + 0x18));
    *(ushort *)(unaff_ESI + 0x13a) =
         *(ushort *)(unaff_ESI + 0x13a) ^
         (byte)((unaff_EDI != 0) * '\x04' ^ *(byte *)(unaff_ESI + 0x13a)) & 4;
  }
  return;
}

