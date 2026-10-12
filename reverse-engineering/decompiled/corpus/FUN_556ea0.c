/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x556ea0; label: FUN_00556ea0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00556ea0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x46e0) != 0)) && (param_3 != 0)) {
    iVar1 = 0;
    if (*(char *)(*(int *)(param_1 + 0x128) + 0xf2) != '\0') {
      iVar2 = 0;
      do {
        if ((*(byte *)(*(int *)(param_1 + 0x46e0) + 0xac + iVar2) & 1) != 0) {
          FUN_005553e0();
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x304;
      } while (iVar1 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xf2));
    }
    FUN_005568e0(param_1,0,_DAT_00925018);
  }
  return;
}

