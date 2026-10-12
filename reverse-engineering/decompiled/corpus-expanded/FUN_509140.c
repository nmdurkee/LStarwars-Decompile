/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509140; label: FUN_00509140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00509140(undefined4 param_1)

{
  int in_ECX;
  
  FUN_006daf70(param_1);
  FUN_006db1c0();
  if (DAT_00826494 == 3) {
    DAT_0297dbd0 = *(undefined4 *)(in_ECX + 0x62c);
    return;
  }
  DAT_0297dbd0 = DAT_00826494;
  return;
}

