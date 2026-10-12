/* Ghidra pseudocode, not original source.
 * ev_2b5797dc97ed4bbab0de865ef61fef56a3505bfdb1fb7c8af1c17efd4ff63982
 * Entry: 0x488f60; label: FUN_00488f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00488f60(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_3f0;
  undefined2 local_3ec [500];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_3f0;
  iVar5 = 0;
  iVar6 = 0;
  local_3f0 = param_1;
  if (0 < DAT_0093b278) {
    iVar4 = 0;
    iVar3 = 0;
    do {
      if ((((((local_3f0 == 0) || (iVar2 = FUN_00630680(local_3f0,iVar5,0), iVar2 == 0)) &&
            ((DAT_00955870 == 0 ||
             ((iVar5 != *(short *)(DAT_00955870 + 0x6c) &&
              (iVar5 != *(short *)(DAT_00955870 + 0x6e))))))) &&
           ((*(code **)(iVar3 + 0x18 + DAT_0093b274) != FUN_004b3350 &&
            (iVar2 = FUN_00594960(iVar5), iVar2 != 0)))) &&
          (((((cVar1 = *(char *)(DAT_0093b284 + 0x116 + iVar4), cVar1 == '\x01' || (cVar1 == '\b'))
             || (iVar5 == DAT_007f199c)) || ((iVar5 == DAT_007f19a0 || (iVar5 == DAT_007f1a4c)))) ||
           ((iVar5 == DAT_007f1a48 || (iVar5 == DAT_007f1a44)))))) && (iVar6 < 500)) {
        local_3ec[iVar6] = (short)iVar5;
        iVar6 = iVar6 + 1;
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 0x4c;
      iVar4 = iVar4 + 0x120;
    } while (iVar5 < DAT_0093b278);
    if (0 < iVar6) {
      if (iVar6 < 2) {
        __security_check_cookie(local_4 ^ (uint)&local_3f0);
        return;
      }
      iVar5 = FUN_0054fa60();
      __security_check_cookie
                (local_4 ^ (uint)&local_3f0,iVar5 % ((int)(0xffff / (longlong)iVar6) + 1));
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_3f0);
  return;
}

