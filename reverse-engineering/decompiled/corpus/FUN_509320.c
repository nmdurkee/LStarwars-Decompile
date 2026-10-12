/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x509320; label: FUN_00509320
 */

undefined4 FUN_00509320(void)

{
  int iVar1;
  
  iVar1 = 0;
  while (((iVar1 == 0 || (DAT_02976c04 == '\0')) || ((&DAT_02976c08)[iVar1] == -1))) {
    iVar1 = iVar1 + 1;
    if (iVar1 == 5) {
      return 0;
    }
  }
  if (DAT_02976c00 == 6) {
    return 0;
  }
  return 1;
}

