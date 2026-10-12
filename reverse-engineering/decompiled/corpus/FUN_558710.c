/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558710; label: FUN_00558710
 */

void FUN_00558710(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 != (int *)0x0) && ((short)param_4[2] != 0)) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = FUN_004f1ff0(*param_4 + iVar3);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*param_4 + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xa0;
    } while (iVar2 < (int)(uint)*(ushort *)(param_4 + 2));
  }
  return;
}

