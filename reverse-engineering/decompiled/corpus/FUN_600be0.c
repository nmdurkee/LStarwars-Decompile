/* Ghidra analysis pseudocode, not original source.
 * ev_17b66c49ee27a79138b1f69ed50983bbb8f85fa72fbf9f24d2924e74b686a814
 * Entry: 0x600be0; label: FUN_00600be0
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

