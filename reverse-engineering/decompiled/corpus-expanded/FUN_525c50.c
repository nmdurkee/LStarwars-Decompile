/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525c50; label: FUN_00525c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00525c50(void)

{
  char *pcVar1;
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0xb0) != 0)) {
    pcVar1 = (char *)(*(int *)(unaff_ESI + 0xb0) + 8);
    *pcVar1 = *pcVar1 + -1;
    if (*(char *)(*(int *)(unaff_ESI + 0xb0) + 8) < '\x02') {
      FUN_00525b80();
    }
    *(undefined4 *)(unaff_ESI + 0xb0) = 0;
  }
  return;
}

