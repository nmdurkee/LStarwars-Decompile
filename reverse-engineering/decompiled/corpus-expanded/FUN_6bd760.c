/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd760; label: FUN_006bd760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bd760(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(0);
  iVar2 = 0;
  for (; iVar1 != 0; iVar1 = (**(code **)(*in_ECX + 0x14))(iVar1)) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}

