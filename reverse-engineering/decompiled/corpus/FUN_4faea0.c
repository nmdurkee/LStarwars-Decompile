/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4faea0; label: FUN_004faea0
 */

int FUN_004faea0(undefined4 param_1,void *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  size_t _Size;
  
  if (DAT_00800544 != 0) {
    DAT_0297dc50 = param_1;
    DAT_0297e020 = param_2;
    DAT_029838d4 = param_4;
    DAT_02982724 = param_3;
    DAT_0297e024 = 0;
    DAT_008cf394 = 0;
    DAT_0090f79c = 0;
    FUN_004f5d00(0x20);
    iVar1 = 0;
    DAT_00915fac = 0;
    DAT_0088ab3c = 0;
    if (param_4 != 0) {
      do {
        _Size = 0x2000;
        if (param_4 < 0x2001) {
          _Size = param_4;
        }
        FUN_004fa320(_Size);
        _memcpy(DAT_0297e020,&DAT_0091ce80,_Size);
        DAT_0297e020 = (void *)((int)DAT_0297e020 + _Size);
        param_4 = DAT_029838d4 - _Size;
        iVar1 = iVar1 + _Size;
        DAT_029838d4 = param_4;
      } while (param_4 != 0);
      DAT_029838d4 = 0;
    }
    return iVar1;
  }
  return 0;
}

