/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509010; label: FUN_00509010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00509010(void)

{
  int unaff_ESI;
  
  if (DAT_0297ae1c == 0) {
    FUN_006ded20();
  }
  return *(undefined4 *)(&DAT_0297ad80 + unaff_ESI * 4);
}

