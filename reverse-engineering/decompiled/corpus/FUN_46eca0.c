/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46eca0; label: FUN_0046eca0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046eca0(int param_1,undefined4 *param_2,uint param_3)

{
  short sVar1;
  
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) &&
     (sVar1 = FUN_00650dc0(param_1), sVar1 != -1)) {
    if (param_3 == 0) {
      FUN_00681e90((int)sVar1,param_2);
    }
    else {
      if ((param_3 & 1) != 0) {
        _DAT_02962b5c = *param_2;
        _DAT_02962b60 = param_2[1];
        _DAT_02962b64 = param_2[2];
        FUN_00681e90((int)sVar1,&DAT_02962b5c);
        _DAT_02962b5c = DAT_02962b50;
        _DAT_02962b60 = DAT_02962b54;
        _DAT_02962b64 = DAT_02962b58;
      }
      if ((param_3 & 2) != 0) {
        _DAT_02962b68 = *param_2;
        _DAT_02962b6c = param_2[1];
        _DAT_02962b70 = param_2[2];
        FUN_00681e90((int)sVar1,&DAT_02962b68);
        _DAT_02962b68 = DAT_02962b50;
        _DAT_02962b6c = DAT_02962b54;
        _DAT_02962b70 = DAT_02962b58;
        return;
      }
    }
  }
  return;
}

