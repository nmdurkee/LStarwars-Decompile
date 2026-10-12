/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x513990; label: FUN_00513990
 */

void FUN_00513990(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *_Dst;
  
  for (iVar3 = FUN_004f1440(param_1); iVar3 != 0; iVar3 = FUN_004f1460(param_1,iVar3)) {
    if (((param_3 == (int *)0x0) || (param_4 == (uint *)0x0)) || (*param_4 <= *param_3 + 0x2cU)) {
      FUN_00512850();
    }
    else {
      uVar4 = *param_3 + 0xf;
      _Dst = (undefined4 *)(uVar4 & 0xfffffff0);
      *param_3 = (uVar4 & 0xfffffff0) + 0x2c;
      _memset(_Dst,0,0x2c);
      if (_Dst != (undefined4 *)0x0) {
        _memset(_Dst,0,0x2c);
        FUN_004ef660(_Dst,iVar3,0x2c);
        *_Dst = 0;
        _Dst[1] = 0;
        iVar2 = *(int *)(iVar3 + 0x14);
        pvVar6 = (void *)0x0;
        if ((iVar2 != 0) && (iVar5 = FUN_004f1ff0(iVar2), iVar5 != 0)) {
          sVar1 = iVar5 + 1;
          pvVar6 = (void *)0x0;
          if (*param_3 + sVar1 < *param_4) {
            uVar4 = *param_3 + 0xf;
            pvVar6 = (void *)(uVar4 & 0xfffffff0);
            *param_3 = (uVar4 & 0xfffffff0) + sVar1;
            _memset(pvVar6,0,sVar1);
          }
          else {
            FUN_00512850();
          }
          FUN_004f1f10(pvVar6,iVar2);
        }
        _Dst[5] = pvVar6;
        iVar2 = *(int *)(iVar3 + 0x20);
        pvVar6 = (void *)0x0;
        if ((iVar2 != 0) && (iVar5 = FUN_004f1ff0(iVar2), iVar5 != 0)) {
          sVar1 = iVar5 + 1;
          pvVar6 = (void *)0x0;
          if (*param_3 + sVar1 < *param_4) {
            uVar4 = *param_3 + 0xf;
            pvVar6 = (void *)(uVar4 & 0xfffffff0);
            *param_3 = (uVar4 & 0xfffffff0) + sVar1;
            _memset(pvVar6,0,sVar1);
          }
          else {
            FUN_00512850();
          }
          FUN_004f1f10(pvVar6,iVar2);
        }
        _Dst[8] = pvVar6;
        FUN_004f1310(param_2,_Dst);
      }
    }
  }
  return;
}

