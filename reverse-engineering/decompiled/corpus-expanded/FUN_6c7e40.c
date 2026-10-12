/* Ghidra pseudocode, not original source.
 * ev_edb2d62139c6989f7d22bdb2eed4f22c2d5b161c90fb53b9f9b1b5e378e66a68
 * Entry: 0x6c7e40; label: FUN_006c7e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006c7e40(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 8);
  iVar3 = 0;
  while ((iVar1 != 0 && (iVar3 < param_3))) {
    iVar2 = FUN_004f8a70(iVar1 + 0xc,param_1);
    if (iVar2 != 0) {
      *(int *)(param_2 + iVar3 * 4) = iVar1;
      iVar3 = iVar3 + 1;
    }
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar3;
}

