/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd6f0; label: FUN_006bd6f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006bd6f0(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))(0);
  iVar4 = 0;
  while ((piVar1 != (int *)0x0 && (iVar4 < param_2))) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(unaff_retaddr);
    iVar3 = FUN_004f8a70(uVar2);
    if (iVar3 != 0) {
      *(int **)(param_1 + iVar4 * 4) = piVar1;
      iVar4 = iVar4 + 1;
    }
    piVar1 = (int *)(**(code **)(*in_ECX + 0x14))(piVar1);
  }
  return iVar4;
}

