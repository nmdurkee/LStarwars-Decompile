/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ea050; label: FUN_004ea050
 */

int FUN_004ea050(float param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar3 = (int)param_1;
  iVar4 = 0;
  if (((param_1 != 0.0) && ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0)) &&
     (*(char *)((int)param_1 + 0x28b) == '\0')) {
    param_1 = 225.0;
    iVar5 = 0;
    do {
      piVar1 = *(int **)((int)&DAT_0087a970 + iVar5);
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        iVar2 = *piVar1;
        if ((((*(uint *)(iVar2 + 0x94) & 0x800000) != 0) &&
            (((*(uint *)(iVar2 + 0x94) & 1) == 0 && (*(int *)((int)&DAT_0087a90c + iVar5) != 0))))
           && (*(int *)(*(int *)(*(int *)((int)&DAT_0087a90c + iVar5) + 0x34) + 0xc) != 0)) {
          fVar6 = (float10)FUN_005b3c50(iVar3 + 0x80,iVar2 + 0x4c,0);
          if ((float)fVar6 < param_1) {
            iVar4 = iVar2;
            param_1 = (float)fVar6;
          }
        }
      }
      iVar5 = iVar5 + 4;
    } while (iVar5 < 0x18);
    return iVar4;
  }
  return 0;
}

