/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x451c20; label: FUN_00451c20
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00451c20(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if ((param_6 != 0) && (DAT_00855de0 != 0)) {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"end_time=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"blend_out_time=");
          if (iVar1 != 0) {
            fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 0xf);
            _DAT_009514ec = (float)fVar3;
          }
        }
        else {
          fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 9);
          _DAT_009514e8 = (float)fVar3;
          _DAT_009514e8 = _DAT_0095191c + _DAT_009514e8;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
      return 1;
    }
    return 1;
  }
  return 1;
}

