/* Ghidra analysis pseudocode, not original source.
 * ev_16752497ebe96469e4b3deeac467b7e56d3adcbbd74f32adb05b8515faa59936
 * Entry: 0x5cfc00; label: FUN_005cfc00
 */

void FUN_005cfc00(int *param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  byte *pbVar3;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    iVar2 = param_1[1];
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x40) != 0) {
        puVar1 = (uint *)(*(int *)(iVar2 + 0x40) + 0x44);
        *puVar1 = *puVar1 ^ (*(uint *)(*(int *)(iVar2 + 0x40) + 0x44) ^ param_2) & 1;
      }
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[1] + 0x48);
        *puVar1 = *puVar1 | 0x200;
        return;
      }
      puVar1 = (uint *)(param_1[1] + 0x48);
      *puVar1 = *puVar1 & 0xfffffdff;
      return;
    }
    iVar2 = param_1[2];
    if (iVar2 != 0) {
      if (param_2 == 0) {
        *(uint *)(iVar2 + 0xb8) = *(uint *)(iVar2 + 0xb8) & 0xfffffffd;
        *(uint *)(param_1[2] + 0xb8) = *(uint *)(param_1[2] + 0xb8) & 0xfffffdff;
        if ((*(byte *)(*(int *)(*param_1 + 0x110) + 0x76) & 1) != 0) {
          pbVar3 = (byte *)(*(int *)(iVar2 + 0xc0) + *(int *)(*(int *)(*param_1 + 0x110) + 0x48));
          *pbVar3 = *pbVar3 & 0xfe;
        }
      }
      else {
        *(uint *)(iVar2 + 0xb8) = *(uint *)(iVar2 + 0xb8) | 0x202;
        if ((*(byte *)(*(int *)(*param_1 + 0x110) + 0x76) & 1) != 0) {
          pbVar3 = (byte *)(*(int *)(iVar2 + 0xc0) + *(int *)(*(int *)(*param_1 + 0x110) + 0x48));
          *pbVar3 = *pbVar3 | 1;
          return;
        }
      }
    }
  }
  return;
}

