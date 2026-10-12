/* Ghidra analysis pseudocode, not original source.
 * ev_7885ce39b81f670d8e3218fe7ff5fd78bd200dfae790f8ac5e62a68993a50c0e
 * Entry: 0x55bef0; label: FUN_0055bef0
 */

void FUN_0055bef0(uint param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_3f0;
  undefined2 local_3ec [500];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_3f0;
  iVar3 = 0;
  iVar4 = 0;
  local_3f0 = param_4;
  if (0 < DAT_0093b278) {
    piVar2 = (int *)(DAT_0093b274 + 0x18);
    do {
      if ((((((local_3f0 == 0) || (iVar1 = FUN_00630680(local_3f0,iVar3,0), iVar1 == 0)) &&
            ((DAT_00955870 == 0 ||
             ((iVar3 != *(short *)(DAT_00955870 + 0x6c) &&
              (iVar3 != *(short *)(DAT_00955870 + 0x6e))))))) &&
           (iVar1 = piVar2[3], (code *)*piVar2 != FUN_004b3350)) &&
          ((((*(uint *)(iVar1 + 0x90) & param_2) == param_2 && ((piVar2[-5] & param_1) == param_1))
           && ((param_5 == 0 || ((*(uint *)(iVar1 + 0x94) & 0x4000) == 0)))))) &&
         (((((param_1 & 8) == 0 || ((*(uint *)(iVar1 + 0x94) & 0x8000) == 0)) &&
           (iVar1 = FUN_00594960(iVar3), iVar1 != 0)) &&
          (((param_3 == 0 || (iVar1 = FUN_0055f360(iVar3), iVar1 != 0)) && (iVar4 < 500)))))) {
        local_3ec[iVar4] = (short)iVar3;
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x13;
    } while (iVar3 < DAT_0093b278);
    if (0 < iVar4) {
      if (iVar4 < 2) {
        __security_check_cookie(local_4 ^ (uint)&local_3f0);
        return;
      }
      iVar3 = FUN_0054fa60();
      __security_check_cookie
                (local_4 ^ (uint)&local_3f0,iVar3 % ((int)(0xffff / (longlong)iVar4) + 1));
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_3f0);
  return;
}

