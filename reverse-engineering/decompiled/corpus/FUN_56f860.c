/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f860; label: FUN_0056f860
 */

void FUN_0056f860(int param_1,undefined4 param_2,void *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  if (param_3 != (void *)0x0) {
    _memset((void *)((int)param_3 + 0x80),-1,0x40);
    _memset((void *)((int)param_3 + 0x40),-1,0x40);
    _memset(param_3,0,0x40);
    _memset((void *)((int)param_3 + 0xc0),0,0x40);
    if (param_1 != 0) {
      iVar2 = **(int **)(param_1 + 0x50b8);
      if ((iVar2 != 0) && (iVar5 = 0, 0 < (*(int **)(param_1 + 0x50b8))[2])) {
        pbVar4 = (byte *)(iVar2 + 0x17);
        do {
          if (0x1ff < iVar5) {
            return;
          }
          iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
          uVar3 = 1 << ((byte)iVar5 & 0x1f);
          if ((*pbVar4 & 4) == 0) {
            puVar1 = (uint *)((int)param_3 + iVar2 * 4 + 0x80);
            *puVar1 = *puVar1 & ~uVar3;
          }
          if ((*pbVar4 & 2) == 0) {
            puVar1 = (uint *)((int)param_3 + iVar2 * 4 + 0x40);
            *puVar1 = *puVar1 & ~uVar3;
          }
          if ((*pbVar4 & 8) != 0) {
            puVar1 = (uint *)((int)param_3 + iVar2 * 4);
            *puVar1 = *puVar1 | uVar3;
          }
          iVar5 = iVar5 + 1;
          pbVar4 = pbVar4 + 0x2c;
        } while (iVar5 < *(int *)(*(int *)(param_1 + 0x50b8) + 8));
      }
    }
  }
  return;
}

