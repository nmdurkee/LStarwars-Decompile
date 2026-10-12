/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cf0b0; label: FUN_004cf0b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cf0b0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 != 0) {
    *(undefined1 *)(iVar1 + 0x4e) = 1;
    *(undefined1 *)(iVar1 + 0x4f) = 0;
    return;
  }
  *(undefined1 *)(iVar1 + 0x4e) = 0;
  return;
}

