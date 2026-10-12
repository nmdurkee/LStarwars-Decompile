/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x50a450; label: FUN_0050a450
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050a450(int param_1)

{
  _DAT_00921d30 = 0;
  DAT_00921e5c = 0;
  DAT_00921d7c = 0;
  DAT_00921d48 = 1;
  _DAT_00921d58 = 2;
  if (DAT_00801598 < 7) {
    *(short *)(param_1 + 0x10) = (short)DAT_00801598 + -1;
  }
  else {
    *(undefined2 *)(param_1 + 0x10) = (undefined2)DAT_00921e84;
    if ((DAT_00921e84 == DAT_00801598) || (DAT_0080200c < DAT_008015a4)) {
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + -1;
    }
  }
  *(undefined4 *)(param_1 + 0xdc) = 2;
  DAT_00921d80 = 0;
  DAT_00921d84 = 0;
  DAT_00921d88 = 0;
  FUN_004f1f10(&DAT_009213f8,PTR_s_Save_Game_008009f4);
  _DAT_0092143c = (uint)DAT_00921daa;
  _DAT_009213e8 = (uint)DAT_0080099c;
  _DAT_009213f4 = (uint)DAT_0080099d;
  *(undefined2 *)(param_1 + 0x12) = 1;
  if (DAT_00802008 != 2) {
    FUN_00509830(0x3ea,0xffffffff,0xffffffff);
    return;
  }
  if (DAT_00924824 != 0) {
    FUN_00509830(0x3fc,0xffffffff,0xffffffff);
    return;
  }
  if (DAT_00802010 == 0) {
    FUN_00509830(0x3ee,1,0xffffffff);
    return;
  }
  if ((DAT_00924810 == 0) && (DAT_0080200c < DAT_008015a0)) {
    FUN_00509830(0x3eb,0xffffffff,0xffffffff);
    return;
  }
  if (DAT_00921d54 != 0) {
    DAT_00921dc0 = 0xffffffff;
    FUN_00509830(0x3f0,1,0xffffffff);
  }
  return;
}

