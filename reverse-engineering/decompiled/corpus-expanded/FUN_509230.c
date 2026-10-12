/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509230; label: FUN_00509230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00509230(void)

{
  undefined4 *in_ECX;
  
  FUN_006daf70(*in_ECX);
  FUN_006db1c0();
  DAT_0297dbd0 = DAT_00826494;
  if (DAT_00826494 == 3) {
    DAT_0297dbd0 = DAT_02976bf4;
  }
  FUN_006db040(in_ECX[1] == 1);
  FUN_006db010(in_ECX[2] == 1);
  FUN_006db060(in_ECX[3] == 1);
  FUN_006db090(in_ECX[4] == 1);
  FUN_006db1c0();
  return;
}

