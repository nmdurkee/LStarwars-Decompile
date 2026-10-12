/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b31f0; label: FUN_006b31f0
 */

undefined4 * FUN_006b31f0(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *_Dst;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int local_8;
  
  local_8 = 0;
  _Dst = _calloc(1,0x714);
  iVar1 = *(int *)((int)param_1 + 0x1c);
  uVar2 = FUN_006a3bb0(param_2,0x18);
  *_Dst = uVar2;
  uVar2 = FUN_006a3bb0(param_2,0x18);
  _Dst[1] = uVar2;
  iVar3 = FUN_006a3bb0(param_2,0x18);
  _Dst[2] = iVar3 + 1;
  iVar3 = FUN_006a3bb0(param_2,6);
  _Dst[3] = iVar3 + 1;
  uVar2 = FUN_006a3bb0(param_2,8);
  iVar3 = 0;
  _Dst[4] = uVar2;
  if (0 < (int)_Dst[3]) {
    param_1 = _Dst + 5;
    do {
      uVar4 = FUN_006a3bb0(param_2,3);
      iVar5 = FUN_006a3bb0(param_2,1);
      if (iVar5 != 0) {
        iVar5 = FUN_006a3bb0(param_2,5);
        uVar4 = uVar4 | iVar5 * 8;
      }
      *param_1 = uVar4;
      iVar5 = 0;
      for (; uVar4 != 0; uVar4 = uVar4 >> 1) {
        iVar5 = iVar5 + (uVar4 & 1);
      }
      local_8 = local_8 + iVar5;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)_Dst[3]);
  }
  if (0 < local_8) {
    puVar7 = _Dst + 0x45;
    iVar3 = local_8;
    do {
      uVar2 = FUN_006a3bb0(param_2,8);
      *puVar7 = uVar2;
      puVar7 = puVar7 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  iVar1 = *(int *)(iVar1 + 0x18);
  if ((int)_Dst[4] < iVar1) {
    iVar3 = 0;
    if (0 < local_8) {
      piVar6 = _Dst + 0x45;
      do {
        if (iVar1 <= *piVar6) goto LAB_006b3319;
        iVar3 = iVar3 + 1;
        piVar6 = piVar6 + 1;
      } while (iVar3 < local_8);
    }
    return _Dst;
  }
LAB_006b3319:
  _memset(_Dst,0,0x714);
  _free(_Dst);
  return (undefined4 *)0x0;
}

