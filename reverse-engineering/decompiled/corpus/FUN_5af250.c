/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5af250; label: FUN_005af250
 */

void FUN_005af250(int param_1,undefined4 param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = param_1;
  iVar4 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x13c) != 0)) {
    FUN_0055fbb0(param_1);
    iVar3 = *(int *)(param_1 + 0x13c);
    iVar5 = 0;
    param_1 = 0;
    if (0 < *(int *)(iVar3 + 0x6c)) {
      do {
        iVar3 = *(int *)(iVar3 + 0x70) + iVar4;
        if (*(char *)(iVar3 + 0x1a) != '\0') {
          FUN_005d90c0(iVar3,1);
          if (((param_3 != 0) && (iVar5 < 0x20)) &&
             ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x13c) + 0x70) + 0x1c + iVar4) & 1) != 0)) {
            puVar1 = (uint *)(param_3 + ((int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5) * 4);
            *puVar1 = *puVar1 | 1 << ((byte)iVar5 & 0x1f);
          }
          iVar5 = iVar5 + 1;
        }
        iVar3 = *(int *)(iVar2 + 0x13c);
        param_1 = param_1 + 1;
        iVar4 = iVar4 + 0x20;
      } while (param_1 < *(int *)(iVar3 + 0x6c));
    }
  }
  return;
}

