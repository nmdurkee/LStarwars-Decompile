/* Ghidra pseudocode, not original source.
 * ev_334294c16a8347b4bc11d90e134269a6e2c30475b5c30bcaa57a53f4585ea308
 * Entry: 0x6d4f60; label: FUN_006d4f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d4f60(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = 0;
  pcVar3 = (char *)(in_ECX + 0x67f1);
  iVar4 = param_2;
  iVar5 = param_2;
  iVar6 = param_2;
  while( true ) {
    if (uVar2 < 0x20) {
      iVar6 = (int)pcVar3[-1];
      iVar4 = (int)*pcVar3;
      iVar5 = (int)pcVar3[1];
    }
    if (((param_1 == iVar6) &&
        (((iVar1 = iVar5, param_1 == 3 || (iVar1 = iVar4, param_1 == 1)) || (param_1 == 2)))) &&
       (iVar1 == param_2)) break;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 6;
    if (0x1f < (int)uVar2) {
      return 0xffffffff;
    }
  }
  return uVar2;
}

