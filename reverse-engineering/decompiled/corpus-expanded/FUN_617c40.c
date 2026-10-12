/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617c40; label: FUN_00617c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00617c40(int param_1)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX - param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

