/* Ghidra analysis pseudocode, not original source.
 * ev_0f83c18e3dd08d4f7d4ef8091875e15de78b7d8ec17e52e6723de9bddd8785d9
 * Entry: 0x621270; label: FUN_00621270
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00621270(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  if (DAT_0080f884 != -1) {
    return 0;
  }
  _memset(&DAT_029110b8,0,0x1000);
  DAT_02900a5c = 0;
  _DAT_02910ca0 = 0;
  _DAT_02910c9c = 0;
  DAT_0080f884 = 0xffffffff;
  DAT_02912f44 = 0;
  if ((DAT_02912f3c == 0) || (DAT_02912f3c != 1)) {
    DAT_0080f884 = 0xffffffff;
    return 0;
  }
  if (param_2 != 0) {
    if (param_2 != 1) {
      DAT_0080f884 = 0xffffffff;
      DAT_02900a5c = 0;
      _DAT_02910c9c = 0;
      _DAT_02910ca0 = 0;
      DAT_02912f44 = 0;
      return 0;
    }
    DAT_02912f44 = 1;
    DAT_0080f884 = FUN_004fa5f0(param_1,1);
    if (DAT_0080f884 < 1) {
      DAT_0080f884 = 0xffffffff;
      return 0;
    }
    return 1;
  }
  if ((DAT_02912f40 != 0) && (iVar1 = FUN_004f9de0(DAT_02912f40,param_1), iVar1 != 0)) {
    FUN_004f0f30(DAT_02912f40,iVar1,&local_4,&local_8);
    DAT_0080f884 = FUN_004f02d0(local_4,local_8,0);
    if (0 < DAT_0080f884) goto LAB_00621375;
    DAT_0080f884 = 0xffffffff;
  }
  DAT_0080f884 = FUN_004fa5f0(param_1,0);
  if (DAT_0080f884 < 1) {
    DAT_0080f884 = 0xffffffff;
    return 0;
  }
LAB_00621375:
  FUN_00621220();
  return 1;
}

