/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x5573e0; label: FUN_005573e0
 */

void FUN_005573e0(undefined4 param_1,int *param_2)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    if ((short)param_2[2] != 0) {
      puVar2 = (uint *)(*param_2 + 0x9c);
      do {
        if ((*puVar2 & 2) != 0) {
          uVar1 = FUN_0056aa40(param_1,(int)(short)puVar2[-5]);
          *puVar2 = *puVar2 & 0xfffffffd;
          *(undefined2 *)(puVar2 + -5) = uVar1;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 0x28;
      } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

