/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x556090; label: FUN_00556090
 */

int FUN_00556090(undefined4 param_1,int param_2,float *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = 1e+09;
  iVar2 = 0;
  local_10 = 0;
  if (*(int *)(param_2 + 0x46e0) != 0) {
    iVar3 = 0;
    if (*(char *)(*(int *)(param_2 + 0x128) + 0xf2) != '\0') {
      do {
        bVar1 = *(byte *)(*(int *)(param_2 + 0x46e0) + 0xac + iVar2);
        iVar4 = *(int *)(param_2 + 0x46e0) + iVar2;
        if (((bVar1 & 1) != 0) && ((bVar1 & 0x26) == 0)) {
          local_c = *(undefined4 *)(iVar4 + 0x5c);
          local_8 = *(undefined4 *)(iVar4 + 0x60);
          local_4 = *(undefined4 *)(iVar4 + 100);
          fVar5 = (float10)FUN_005b3c50(param_1,&local_c,0);
          if ((float)fVar5 < local_14) {
            local_14 = (float)fVar5;
            local_10 = iVar4;
          }
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x304;
      } while (iVar3 < (int)(uint)*(byte *)(*(int *)(param_2 + 0x128) + 0xf2));
    }
    if (param_3 != (float *)0x0) {
      *param_3 = local_14;
    }
    return local_10;
  }
  return 0;
}

