/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x631360; label: FUN_00631360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00631360(int param_1)

{
  int iVar1;
  undefined8 uVar2;
  LARGE_INTEGER local_10;
  LARGE_INTEGER local_8;
  
  if (DAT_02913228 == 0) {
    DAT_02913228 = 1;
    QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_0080fcd0);
  }
  param_1 = DAT_02913224 + param_1;
  DAT_02913224 = param_1 - _DAT_02913220;
  if (1000 < DAT_02913224) {
    QueryPerformanceCounter(&local_8);
    Sleep(DAT_02913224 / 1000);
    QueryPerformanceCounter(&local_10);
    uVar2 = __allmul(local_10.s.LowPart - local_8._0_4_,
                     (local_10.s.HighPart - local_8._4_4_) -
                     (uint)(local_10.s.LowPart < local_8.s.LowPart),1000000,0);
    _DAT_02913220 = __aulldiv(uVar2,DAT_0080fcd0,DAT_0080fcd4);
    _DAT_02913220 = _DAT_02913220 - DAT_02913224;
    iVar1 = (int)((ulonglong)((longlong)DAT_02913224 * -0x10624dd3) >> 0x20);
    param_1 = DAT_02913224 + ((iVar1 >> 6) - (iVar1 >> 0x1f)) * 1000;
  }
  DAT_02913224 = param_1;
  return;
}

