/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x5273c0; label: FUN_005273c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005273c0(void)

{
  int iVar1;
  
  if ((*(int *)(DAT_009238e4 + 100) != 0) &&
     (iVar1 = *(int *)(*(int *)(DAT_009238e4 + 100) + 0x138c), iVar1 != 0)) {
    FUN_00620f10(iVar1 + 0x5c);
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

