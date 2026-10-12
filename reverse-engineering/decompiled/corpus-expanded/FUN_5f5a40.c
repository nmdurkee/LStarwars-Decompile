/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5a40; label: FUN_005f5a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f5a40(void)

{
  char *in_ECX;
  float local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  if (((*in_ECX != '\0') && (in_ECX[1] != '\0')) && (DAT_0097392c == 0)) {
    FUN_005d0880(2);
    if (DAT_009738c8 < 0x10) {
      *(undefined4 *)(&DAT_00963dc0 + DAT_009738c8 * 4) = DAT_009738c0;
      DAT_009738c8 = DAT_009738c8 + 1;
    }
    _DAT_0080b600 = 0x3d800000;
    _DAT_0080b604 = 0x3d800000;
    DAT_009738c0 = 1;
    _DAT_009738ac = 0;
    _DAT_009738b0 = 0;
    _DAT_0080b608 = 16.0;
    _DAT_0080b60c = 16.0;
    if (DAT_009738b8 != 0) {
      _DAT_009738b4 = *(undefined4 *)(DAT_009738b8 + 0x1c);
      *(undefined4 *)(DAT_009738b8 + 0x20) = 1;
    }
    FUN_005d0fe0(DAT_009738b8,0x3f333333,0x3f333333);
    FUN_005eaad0(DAT_009738b8,0x3f333333,0x3f333333);
    FUN_005eb710(DAT_009738b8,0x42e00000,0x42e00000,0);
    FUN_005d15c0(DAT_009738b8,0x80000000);
    _sprintf(local_104,"Occluders : %2d, Queries : %2d, Occluded : %2d, Visible : %2d",
             *(undefined4 *)(*(int *)(in_ECX + 0x154) + 0xc),*(int *)(in_ECX + 0x164),
             *(int *)(in_ECX + 0x160),*(int *)(in_ECX + 0x164) - *(int *)(in_ECX + 0x160));
    FUN_005f3790(DAT_009738b8,local_104);
    local_108 = 112.0 - _DAT_0080b608;
    FUN_005eb710(DAT_009738b8,local_108,112.0 - _DAT_0080b60c,0);
    FUN_005d15c0(DAT_009738b8,0xff00ffff);
    FUN_005f3790(DAT_009738b8,local_104);
    if (0 < DAT_009738c8) {
      DAT_009738c8 = DAT_009738c8 + -1;
      FUN_005d0940(*(undefined4 *)(&DAT_00963dc0 + DAT_009738c8 * 4));
    }
    if (0 < DAT_009738cc) {
      DAT_009738c4 = *(undefined4 *)(&DAT_0096d86c + DAT_009738cc * 4);
      DAT_009738cc = DAT_009738cc + -1;
    }
    if (DAT_00973838 != 0) {
      FUN_005c5c30(0);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

