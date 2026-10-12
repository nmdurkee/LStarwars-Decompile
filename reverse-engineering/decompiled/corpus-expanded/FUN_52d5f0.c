/* Ghidra pseudocode, not original source.
 * ev_cdff09935bddc4594064dfeb1f42a846ac78fe961445b4150dea7d25416822c1
 * Entry: 0x52d5f0; label: FUN_0052d5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052d5f0(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    iVar3 = FUN_0051ad80(0,param_1,param_2);
    iVar4 = FUN_0051ad80(0,param_1,param_3);
    if ((iVar3 != 0) && (iVar4 != 0)) {
      uVar2 = (iVar4 - *(int *)(param_1 + 0x7c)) / 0x5c;
      iVar4 = 0;
      if (*(byte *)(iVar3 + 0x28) != 0) {
        piVar6 = *(int **)(iVar3 + 0x34);
        while (*(byte *)(*piVar6 + 0x10) != uVar2) {
          if (*(byte *)(*piVar6 + 0x11) == uVar2) {
            iVar5 = 0;
            goto LAB_0052d68a;
          }
          iVar4 = iVar4 + 1;
          piVar6 = piVar6 + 1;
          if ((int)(uint)*(byte *)(iVar3 + 0x28) <= iVar4) {
            return;
          }
        }
        iVar5 = 1;
LAB_0052d68a:
        iVar3 = (*(int **)(iVar3 + 0x34))[iVar4];
        if (iVar3 != 0) {
          if (param_4 != 0) {
            puVar1 = (uint *)(iVar3 + iVar5 * 4);
            *puVar1 = *puVar1 | 0x80000000;
            return;
          }
          puVar1 = (uint *)(iVar3 + iVar5 * 4);
          *puVar1 = *puVar1 & 0x7fffffff;
        }
      }
    }
  }
  return;
}

