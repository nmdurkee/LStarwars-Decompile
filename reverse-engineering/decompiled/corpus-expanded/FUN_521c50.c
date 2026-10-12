/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521c50; label: FUN_00521c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00521c50(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x41200);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) break;
    iVar1 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar1);
  }
  return iVar1;
}

