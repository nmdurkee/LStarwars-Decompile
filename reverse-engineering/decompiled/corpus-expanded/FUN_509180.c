/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509180; label: FUN_00509180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00509180(void)

{
  uint uVar1;
  int *in_ECX;
  
  if (*in_ECX != DAT_00826494) {
    return CONCAT31((int3)((uint)*in_ECX >> 8),1);
  }
  uVar1 = 1;
  if ((((in_ECX[1] == 1) == (bool)DAT_008264c4) && ((in_ECX[2] == 1) == (bool)DAT_008264b8)) &&
     ((in_ECX[3] == 1) == (bool)DAT_008264c6)) {
    uVar1 = (uint)((in_ECX[4] == 1) != (bool)DAT_008264c8);
  }
  return uVar1;
}

