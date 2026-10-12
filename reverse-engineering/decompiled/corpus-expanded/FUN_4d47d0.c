/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d47d0; label: FUN_004d47d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d47d0(void)

{
  int in_EAX;
  undefined4 *unaff_ESI;
  
  if ((in_EAX != 0) && (unaff_ESI != (undefined4 *)0x0)) {
    FUN_004f1410(in_EAX + 0x77d8);
    *unaff_ESI = 0;
    FUN_004f1310(in_EAX + 0x77d0);
  }
  return;
}

