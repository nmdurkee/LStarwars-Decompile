/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x600be0; label: FUN_00600be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00600be0(int *param_1,int param_2)

{
  uint *puVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(int *)(param_2 + 0x110) == 0) {
    if (0 < (short)param_1[3]) {
      do {
        puVar1 = (uint *)(*(short *)(*param_1 + iVar3 * 2) * 0x50 + 0x44 + *(int *)(param_2 + 0x20))
        ;
        *puVar1 = *puVar1 | 4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (short)param_1[3]);
    }
  }
  else if (0 < (short)param_1[3]) {
    do {
      sVar2 = *(short *)(*param_1 + iVar3 * 2);
      iVar3 = iVar3 + 1;
      (&DAT_0280a2f0)[(int)sVar2 >> 3] =
           (&DAT_0280a2f0)[(int)sVar2 >> 3] | '\x01' << ((byte)sVar2 & 7);
    } while (iVar3 < (short)param_1[3]);
    return;
  }
  return;
}

