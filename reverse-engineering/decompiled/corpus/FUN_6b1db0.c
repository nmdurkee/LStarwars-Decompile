/* Ghidra analysis pseudocode, not original source.
 * ev_648e39c5173022307384bd96b6b6d54b0109fbb7542fd197fe89208a1a87d4a6
 * Entry: 0x6b1db0; label: FUN_006b1db0
 */

int * FUN_006b1db0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *_Dst;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_8;
  
  _Dst = _calloc(1,0xc88);
  iVar1 = *(int *)(param_1 + 0x1c);
  _memset(_Dst,0,0xc88);
  iVar2 = FUN_006a3bb0(param_2,1);
  if (iVar2 == 0) {
    *_Dst = 1;
  }
  else {
    iVar2 = FUN_006a3bb0(param_2,4);
    *_Dst = iVar2 + 1;
  }
  iVar2 = FUN_006a3bb0(param_2,1);
  if (iVar2 != 0) {
    iVar2 = FUN_006a3bb0(param_2,8);
    _Dst[0x121] = iVar2 + 1;
    local_8 = 0;
    if (0 < iVar2 + 1) {
      piVar5 = _Dst + 0x222;
      do {
        iVar2 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar4 = *(int *)(param_1 + 4) - 1; uVar4 != 0; uVar4 = uVar4 >> 1) {
            iVar2 = iVar2 + 1;
          }
        }
        iVar3 = FUN_006a3bb0(param_2,iVar2);
        piVar5[-0x100] = iVar3;
        iVar2 = 0;
        if (*(int *)(param_1 + 4) != 0) {
          for (uVar4 = *(int *)(param_1 + 4) - 1; uVar4 != 0; uVar4 = uVar4 >> 1) {
            iVar2 = iVar2 + 1;
          }
        }
        iVar2 = FUN_006a3bb0(param_2,iVar2);
        *piVar5 = iVar2;
        if ((((iVar3 < 0) || (iVar2 < 0)) || (iVar3 == iVar2)) ||
           ((*(int *)(param_1 + 4) <= iVar3 || (*(int *)(param_1 + 4) <= iVar2))))
        goto LAB_006b1f96;
        local_8 = local_8 + 1;
        piVar5 = piVar5 + 1;
      } while (local_8 < _Dst[0x121]);
    }
  }
  iVar2 = FUN_006a3bb0(param_2,2);
  if (iVar2 < 1) {
    if ((1 < *_Dst) && (iVar2 = 0, piVar5 = _Dst, 0 < *(int *)(param_1 + 4))) {
      do {
        iVar3 = FUN_006a3bb0(param_2,4);
        piVar5[1] = iVar3;
        if (*_Dst <= iVar3) goto LAB_006b1f96;
        iVar2 = iVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar2 < *(int *)(param_1 + 4));
    }
    local_8 = 0;
    if (0 < *_Dst) {
      piVar5 = _Dst + 0x111;
      do {
        FUN_006a3bb0(param_2,8);
        iVar2 = FUN_006a3bb0(param_2,8);
        piVar5[-0x10] = iVar2;
        if (*(int *)(iVar1 + 0x10) <= iVar2) goto LAB_006b1f96;
        iVar2 = FUN_006a3bb0(param_2,8);
        *piVar5 = iVar2;
        if (*(int *)(iVar1 + 0x14) <= iVar2) goto LAB_006b1f96;
        local_8 = local_8 + 1;
        piVar5 = piVar5 + 1;
      } while (local_8 < *_Dst);
    }
    return _Dst;
  }
LAB_006b1f96:
  _memset(_Dst,0,0xc88);
  _free(_Dst);
  return (int *)0x0;
}

