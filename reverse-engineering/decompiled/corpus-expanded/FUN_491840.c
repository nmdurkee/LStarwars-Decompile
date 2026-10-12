/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x491840; label: FUN_00491840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491840(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_2d0;
  char local_2cc [712];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2d0;
  if (DAT_0093d810 != 0) {
    iVar3 = 0;
    while (iVar1 = FUN_0043bb20((&DAT_0087b370)[iVar3],
                                (&DAT_0093d5a0)[*(char *)(DAT_0093d810 + 0x280) * 4],0), iVar1 == 0)
    {
      iVar3 = iVar3 + 1;
      if (9 < iVar3) {
        __security_check_cookie(local_4 ^ (uint)&local_2d0);
        return;
      }
    }
    if ((iVar3 != -1) && (iVar3 != DAT_0087b460)) {
      DAT_0087b460 = (short)iVar3;
      if (((&DAT_0087b398)[DAT_0087b460] != 0) &&
         (iVar3 = FUN_005171b0(*(undefined4 *)(param_1 + 0x2ae8),(&DAT_0087b398)[DAT_0087b460]),
         iVar3 != 0)) {
        piVar2 = &DAT_0093d7f0;
        do {
          iVar3 = *piVar2;
          if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x1fc) & 1) != 0)) {
            FUN_0051a7c0(iVar3 + 0x2c8,
                         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2ae8) + 0x10) + 8));
            FUN_0052f800(*(undefined4 *)(param_1 + 0x2ae8),iVar3,iVar3 + 0x2c8,0xff,
                         (int)*(char *)(iVar3 + 0x281));
          }
          piVar2 = piVar2 + 1;
        } while ((int)piVar2 < 0x93d810);
      }
      FUN_00491620();
      iVar1 = 0;
      iVar3 = DAT_0093d504;
      if (0 < DAT_0093d500) {
        do {
          if ((((*(byte *)(iVar3 + 0x1fc) & 1) != 0) && (*(char *)(iVar3 + 0x280) == -1)) &&
             (*(char *)(iVar3 + 0x400) == -1)) {
            *(undefined4 *)(iVar3 + 0xea8) = 0;
            FUN_004d22f0(iVar3 + 0xcc4);
            FUN_0055cad0(iVar3,1);
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar3 + 0x10d8;
        } while (iVar1 < DAT_0093d500);
      }
      _DAT_0087b462 = 0;
      _DAT_0087b46c = 0;
      _DAT_0087b470 = 0;
      FUN_005ab050(DAT_0095df4c,"ServingCustomer",0,DAT_0087b478);
      if (DAT_0087b474 != 0) {
        local_2d0 = (int)DAT_0087b460;
        *(float *)(DAT_0087b474 + 0x28) = (float)local_2d0;
      }
      _DAT_0087b464 = 0;
      iVar3 = 0;
      do {
        if (DAT_0087b460 == 0) {
          _sprintf(local_2cc,"Table_%d",iVar3);
        }
        else {
          _sprintf(local_2cc,"Table%d_%d",(int)DAT_0087b460);
        }
        iVar1 = FUN_0051ac10(*(undefined4 *)(param_1 + 0x2ae8),local_2cc);
        (&DAT_0087b49c)[iVar3] = iVar1;
        if (iVar1 == 0) break;
        _DAT_0087b464 = _DAT_0087b464 + 1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 8);
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_2d0);
  return;
}

