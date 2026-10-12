/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x451c20; label: FUN_00451c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

