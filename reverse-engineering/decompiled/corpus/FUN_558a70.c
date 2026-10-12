/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x558a70; label: FUN_00558a70
 */

undefined4 FUN_00558a70(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if ((((*(uint *)(param_2 + 0x94) & 2) != 0) && ((*(uint *)(param_2 + 0x94) & 1) != 0)) &&
     (-1 < (char)*(uint *)(param_2 + 0x9c))) {
    uVar1 = *(uint *)(param_2 + 0x68);
    if ((uVar1 & 0x800) == 0) {
      if ((uVar1 & 0x1000) == 0) {
        return 0;
      }
      if (*(short *)(param_2 + 0x88) != -1) {
        if ((uVar1 & 0x200) == 0) {
          FUN_0056a8c0(param_1,(int)*(short *)(param_2 + 0x88),param_2 + 0x28);
        }
        else if (*(int *)(param_2 + 0x34) != 0) {
          for (puVar2 = *(undefined4 **)(*(int *)(param_2 + 0x34) + 0x18);
              puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
            iVar3 = FUN_005cf9e0(puVar2 + 1);
            if (iVar3 != 0) {
              FUN_0056a8c0(param_1,(int)*(short *)(param_2 + 0x88),iVar3);
            }
          }
        }
      }
      FUN_005a11f0(*(undefined4 *)(param_2 + 0x34));
      FUN_00557690();
      FUN_005a15e0(*(undefined4 *)(param_2 + 0x34),0);
      *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x80;
    }
    else {
      *(uint *)(param_2 + 0x9c) = *(uint *)(param_2 + 0x9c) | 0x40;
    }
    if ((param_4 != -1) && ((*(byte *)((&DAT_0093d7f0)[param_4] + 0x1fc) & 0x80) != 0)) {
      FUN_0054a8a0(**(undefined4 **)((&DAT_0093d7f0)[param_4] + 0xca4),0x3dcccccd,0);
    }
    return 1;
  }
  return 0;
}

