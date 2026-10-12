/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b4cb0; label: FUN_006b4cb0
 */

int * FUN_006b4cb0(int *param_1,undefined4 param_2)

{
  int *_Dst;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *local_14;
  int local_10;
  
  iVar2 = *(int *)((int)param_1 + 0x1c);
  iVar6 = 0;
  local_10 = 0;
  iVar4 = -1;
  _Dst = _calloc(1,0x460);
  iVar1 = FUN_006a3bb0(param_2,5);
  *_Dst = iVar1;
  param_1 = _Dst;
  if (0 < iVar1) {
    do {
      param_1 = param_1 + 1;
      iVar1 = FUN_006a3bb0(param_2,4);
      *param_1 = iVar1;
      if (iVar4 < iVar1) {
        iVar4 = iVar1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *_Dst);
  }
  param_1 = (int *)0x0;
  if (0 < iVar4 + 1) {
    local_14 = _Dst + 0x50;
    piVar5 = _Dst + 0x40;
    do {
      iVar1 = FUN_006a3bb0(param_2,3);
      piVar5[-0x20] = iVar1 + 1;
      iVar1 = FUN_006a3bb0(param_2,2);
      piVar5[-0x10] = iVar1;
      if (iVar1 < 0) {
LAB_006b4ecd:
        _memset(_Dst,0,0x460);
        _free(_Dst);
        return (int *)0x0;
      }
      if (iVar1 != 0) {
        iVar1 = FUN_006a3bb0(param_2,8);
        *piVar5 = iVar1;
      }
      if ((*piVar5 < 0) || (*(int *)(iVar2 + 0x18) <= *piVar5)) goto LAB_006b4ecd;
      iVar1 = 0;
      piVar7 = local_14;
      if (0 < 1 << ((byte)piVar5[-0x10] & 0x1f)) {
        do {
          iVar6 = FUN_006a3bb0(param_2,8);
          iVar6 = iVar6 + -1;
          *piVar7 = iVar6;
          if ((iVar6 < -1) || (*(int *)(iVar2 + 0x18) <= iVar6)) goto LAB_006b4ecd;
          iVar1 = iVar1 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar1 < 1 << ((byte)piVar5[-0x10] & 0x1f));
      }
      local_14 = local_14 + 8;
      param_1 = (int *)((int)param_1 + 1);
      piVar5 = piVar5 + 1;
    } while ((int)param_1 < iVar4 + 1);
  }
  iVar2 = FUN_006a3bb0(param_2,2);
  _Dst[0xd0] = iVar2 + 1;
  uVar3 = FUN_006a3bb0(param_2,4);
  iVar2 = 0;
  param_1 = (int *)0x0;
  local_14 = _Dst;
  if (0 < *_Dst) {
    do {
      local_14 = local_14 + 1;
      local_10 = local_10 + _Dst[*local_14 + 0x20];
      if (iVar2 < local_10) {
        piVar5 = _Dst + iVar2 + 0xd3;
        do {
          iVar4 = FUN_006a3bb0(param_2,uVar3);
          *piVar5 = iVar4;
          if ((iVar4 < 0) || (1 << ((byte)uVar3 & 0x1f) <= iVar4)) goto LAB_006b4ecd;
          iVar2 = iVar2 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar2 < local_10);
      }
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < *_Dst);
  }
  _Dst[0xd1] = 0;
  _Dst[0xd2] = 1 << ((byte)uVar3 & 0x1f);
  return _Dst;
}

