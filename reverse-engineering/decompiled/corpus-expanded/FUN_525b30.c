/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525b30; label: FUN_00525b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00525b30(void)

{
  int iVar1;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x31b84);
  if (iVar1 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x31b84,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x31b8c,iVar1);
  }
  return iVar1;
}

