/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558570; label: FUN_00558570
 */

int FUN_00558570(int *param_1,undefined4 param_2,int param_3,float *param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_10;
  undefined1 local_c [12];
  
  piVar2 = param_1;
  iVar4 = 0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = param_1 + 2;
  param_1 = (int *)0x4e6e6b28;
  iVar3 = *piVar2;
  local_10 = 0;
  if ((short)*piVar1 != 0) {
    do {
      if ((((param_5 == 0xffffffff) || (*(byte *)(iVar3 + 0x91) == param_5)) &&
          ((*(uint *)(iVar3 + 0x94) & 2) != 0)) &&
         (((*(uint *)(iVar3 + 0x94) & 1) != 0 && ((*(byte *)(iVar3 + 0x9c) & 0x80) == 0)))) {
        if ((param_3 == 0) || (*(int *)(iVar3 + 0x34) == 0)) {
          fVar5 = (float10)FUN_005b3c50(param_2,iVar3 + 0x10,0);
        }
        else {
          FUN_005a0b00(*(int *)(iVar3 + 0x34),local_c,2,1,0);
          fVar5 = (float10)FUN_005b3c50(param_2,local_c,0);
        }
        if ((float)fVar5 < (float)param_1) {
          param_1 = (int *)(float)fVar5;
          local_10 = iVar3;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xa0;
    } while (iVar4 < (int)(uint)*(ushort *)(piVar2 + 2));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = (float)param_1;
  }
  return local_10;
}

