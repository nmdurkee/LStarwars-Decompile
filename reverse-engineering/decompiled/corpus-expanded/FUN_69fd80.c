/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69fd80; label: FUN_0069fd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0069fd80(void)

{
  undefined1 uVar1;
  int in_EAX;
  undefined1 *in_ECX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    uVar1 = FUN_006a3bb0();
    *in_ECX = uVar1;
    in_ECX = in_ECX + 1;
  }
  return;
}

