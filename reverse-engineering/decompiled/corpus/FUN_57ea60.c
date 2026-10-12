/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57ea60; label: FUN_0057ea60
 */

void FUN_0057ea60(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if ((((DAT_00951cb0 != 0) && (*(int *)(DAT_00951cb0 + 4) != 0)) && (*(int *)(param_1 + 0x48) != 0)
      ) && (iVar3 = 0, *(char *)(param_1 + 0x4c) != '\0')) {
    iVar4 = 0;
    do {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x48) + 0xc + iVar4);
      iVar2 = *(int *)(param_1 + 0x48) + iVar4;
      if ((bVar1 & 1) == 0) {
        if ((bVar1 & 2) == 0) {
          if ((bVar1 & 4) != 0) {
            fVar5 = (float10)FUN_005e9650(iVar2);
            iVar2 = FUN_005d0420(*(int *)(param_1 + 0x48) + iVar4);
            if (iVar2 != 0) {
              *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) | 1;
              *(float *)(iVar2 + 0x4c) = (float)fVar5;
            }
          }
        }
        else {
          FUN_005cfc00(iVar2,0);
        }
      }
      else {
        FUN_005cfc00(iVar2,1);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x4c));
  }
  return;
}

