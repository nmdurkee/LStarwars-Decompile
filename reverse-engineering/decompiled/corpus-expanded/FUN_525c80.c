/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525c80; label: FUN_00525c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00525c80(void)

{
  int in_EAX;
  int unaff_EDI;
  
  if ((unaff_EDI != 0) && (in_EAX != 0)) {
    if (*(int *)(in_EAX + 0xb0) != 0) {
      if (*(int *)(in_EAX + 0xb0) == unaff_EDI) {
        return;
      }
      FUN_00525c50();
    }
    *(int *)(in_EAX + 0xb0) = unaff_EDI;
    *(char *)(unaff_EDI + 8) = *(char *)(unaff_EDI + 8) + '\x01';
  }
  return;
}

