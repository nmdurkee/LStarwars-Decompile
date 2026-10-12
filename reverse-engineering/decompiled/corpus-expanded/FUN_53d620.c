/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d620; label: FUN_0053d620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d620(void)

{
  int in_ECX;
  
  if (1 < *(uint *)(in_ECX + 0x4b0)) {
    *(uint *)(in_ECX + 0x4b0) = *(uint *)(in_ECX + 0x4b0) - 1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x4b0) = 0;
  return;
}

