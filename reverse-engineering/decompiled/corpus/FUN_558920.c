/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558920; label: FUN_00558920
 */

int FUN_00558920(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    iVar3 = *param_1;
    iVar2 = 0;
    if ((short)param_1[2] != 0) {
      do {
        iVar1 = FUN_004f8b10(iVar3,param_2);
        if (iVar1 == 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0xa0;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 2));
    }
  }
  return iVar3;
}

