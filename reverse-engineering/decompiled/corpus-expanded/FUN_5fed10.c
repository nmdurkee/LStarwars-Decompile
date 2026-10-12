/* Ghidra pseudocode, not original source.
 * ev_89ac6cdcf79c80fd66b36aa582044170c8ea90809525d25928dfed7b186ac36e
 * Entry: 0x5fed10; label: FUN_005fed10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fed10(undefined4 param_1)

{
  float *pfVar1;
  int iVar2;
  
  if (DAT_02854c84 != 0) {
    iVar2 = 0;
    if (0 < DAT_02854c84) {
      pfVar1 = (float *)&DAT_0280c74c;
      do {
        _DAT_0285715c = pfVar1[-2];
        _DAT_028571a8 = *pfVar1;
        _DAT_02857158 = pfVar1[-3] - _DAT_028571a8;
        _DAT_02857170 = (int)*(short *)(pfVar1 + 1) << 0x18;
        _DAT_02857160 = pfVar1[-1] - _DAT_028571a8;
        _DAT_02857174 = 0;
        _DAT_02857178 = 0;
        _DAT_0285717c = _DAT_028571a8 + pfVar1[-3];
        _DAT_02857198 = 0x3f800000;
        _DAT_0285719c = 0;
        _DAT_028571a8 = pfVar1[-1] + _DAT_028571a8;
        _DAT_028571bc = 0;
        _DAT_028571c0 = 0x3f800000;
        _DAT_028571e0 = 0x3f800000;
        _DAT_028571e4 = 0x3f800000;
        _DAT_02857180 = _DAT_0285715c;
        _DAT_02857184 = _DAT_02857160;
        _DAT_02857194 = _DAT_02857170;
        _DAT_028571a0 = _DAT_02857158;
        _DAT_028571a4 = _DAT_0285715c;
        _DAT_028571b8 = _DAT_02857170;
        _DAT_028571c4 = _DAT_0285717c;
        _DAT_028571c8 = _DAT_0285715c;
        _DAT_028571cc = _DAT_028571a8;
        _DAT_028571dc = _DAT_02857170;
        FUN_005dda30(&DAT_02857158,param_1,0,4);
        iVar2 = iVar2 + 1;
        pfVar1 = pfVar1 + 6;
      } while (iVar2 < DAT_02854c84);
    }
    DAT_02854c84 = 0;
  }
  return;
}

