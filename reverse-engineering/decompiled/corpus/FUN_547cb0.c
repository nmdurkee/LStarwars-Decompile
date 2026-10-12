/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547cb0; label: FUN_00547cb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00547cb0(int param_1,int param_2,float param_3)

{
  int iVar1;
  
  if ((((_DAT_00924ddc <= 0.0) && (iVar1 = FUN_0062c350(0x40000000,_DAT_00925018), 0 < iVar1)) &&
      (*(char *)(param_1 + 0x28b) == '\0')) && (*(char *)(param_1 + 0x7b5) == -1)) {
    if ((param_2 == DAT_008020c0) && (0.0 < param_3)) {
      _DAT_00924ddc = param_3;
      DAT_008020c0 = 0xffffffff;
      return;
    }
    FUN_00681e90(param_2,param_1 + 0x80);
    iVar1 = FUN_0054fa60();
    DAT_008020c0 = param_2;
    _DAT_00924ddc = (float)iVar1 * 1.5259022e-05 + (float)iVar1 * 1.5259022e-05 + 3.0;
  }
  return;
}

