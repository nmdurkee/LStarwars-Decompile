/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd630; label: FUN_006bd630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bd630(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x20))();
  if (iVar1 != 0) {
    return iVar1 + 0x30;
  }
  return 0;
}

