/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509320; label: FUN_00509320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

