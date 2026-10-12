/* Ghidra analysis pseudocode, not original source.
 * ev_d01615a5a43d674e3d5304a49d42c1316108bf7c3b83d91b26d188fd5d83afac
 * Entry: 0x4ab620; label: FUN_004ab620
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab620(int param_1)

{
  float fVar1;
  int iVar2;
  
  if (_DAT_00924fdc < 1.0) {
    return;
  }
  if ((((*(char *)(param_1 + 0x280) != -1) && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) &&
      (*(char *)(param_1 + 0x1078) != '\0')) &&
     ((*(float *)(param_1 + 0x6b8) <= 0.574 &&
      (fVar1 = *(float *)(param_1 + 0x6b8), !NAN(fVar1) && -0.574 < fVar1 != (fVar1 == -0.574))))) {
    if ((DAT_0087af5c == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af5c)) {
      _DAT_0087b920 = (1.0 / *(float *)(param_1 + 0xdf0)) * *(float *)(param_1 + 0xdf4);
      if (_DAT_0087b920 < 1.0) {
        if (_DAT_0087b920 < _DAT_007fc228) {
          FUN_00438230(0,param_1,1,0,0,1);
        }
        fVar1 = *(float *)(param_1 + 0xc44) * 0.5;
        *(float *)(param_1 + 0xc44) = fVar1;
        if (fVar1 < _DAT_007fc17c) {
          *(float *)(param_1 + 0xc44) = _DAT_007fc17c;
          return;
        }
      }
    }
    else {
      FUN_00684be0(*(undefined4 *)
                    (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + DAT_007fc1a4 * 0x14),
                   param_1 + 0x6a8,0x32,_DAT_00925018,0,0,0);
      iVar2 = FUN_0054fa60();
      if (iVar2 < 0x8000) {
        FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
        return;
      }
    }
  }
  return;
}

