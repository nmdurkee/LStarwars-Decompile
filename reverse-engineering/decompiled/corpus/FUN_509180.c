/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x509180; label: FUN_00509180
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

