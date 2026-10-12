/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x652660; label: FUN_00652660
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652660(int param_1)

{
  short sVar1;
  
  if (((DAT_02962034 == 0) && (DAT_02962038 == 0)) && (-1 < param_1)) {
    sVar1 = (short)param_1;
    if (((param_1 <= DAT_0296202c + -1) && ((DAT_00810490 == 4 || (DAT_00810490 == 0)))) &&
       ((DAT_00810492 != param_1 || (DAT_008104a0 != '\0')))) {
      DAT_00810492 = sVar1;
      DAT_0081049a = sVar1;
      _DAT_008104ae = sVar1;
      (&DAT_008104a2)[DAT_00810494] = 0;
      if ((DAT_00810498 < 0x40) && (DAT_00810490 != 0)) {
        DAT_008104a0 = '\x01';
      }
      else {
        DAT_008104a0 = '\0';
        FUN_006524a0(param_1,0,_DAT_008104a4);
        _DAT_008104a4 = 0;
      }
    }
    if ((param_1 <= DAT_0296202c + -1) &&
       ((((DAT_00810490 == 0xb || (DAT_00810490 == 0xc)) || (DAT_00810490 == 0xd)) &&
        ((DAT_00810496 != param_1 || (DAT_008104a0 != '\0')))))) {
      DAT_00810490 = 0xb;
      DAT_00810492 = sVar1;
      DAT_00810496 = sVar1;
      DAT_0081049a = sVar1;
      (&DAT_008104a2)[DAT_00810494] = 0;
      if (0x3f < DAT_00810498) {
        DAT_008104a0 = 0;
        FUN_006524a0(param_1,0,_DAT_008104a4);
        _DAT_008104a4 = 0;
        DAT_00810498 = 0;
        return;
      }
      DAT_008104a0 = '\x01';
    }
  }
  return;
}

