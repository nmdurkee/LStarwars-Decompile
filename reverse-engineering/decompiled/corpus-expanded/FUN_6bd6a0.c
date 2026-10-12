/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd6a0; label: FUN_006bd6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006bd6a0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))(0);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    uVar2 = (**(code **)(*piVar1 + 0xc))();
    iVar3 = FUN_004f8b10(unaff_retaddr,uVar2);
    if (iVar3 == 0) break;
    piVar1 = (int *)(**(code **)(*in_ECX + 0x14))(piVar1);
  }
  return piVar1;
}

