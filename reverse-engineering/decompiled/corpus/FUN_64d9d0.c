/* Ghidra analysis pseudocode, not original source.
 * ev_b688fd0177351e281ce3a654852fc29d1d3855db670688278c9fb06d06ddbb68
 * Entry: 0x64d9d0; label: FUN_0064d9d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064d9d0(void)

{
  int *piVar1;
  
  DAT_02920aa0 = DAT_02920aa0 + 1;
  if (5 < DAT_02920aa0) {
    DAT_02920aa0 = 0;
    if ((((&DAT_02913ae8)[DAT_02920a9c * 0xbc] != -1) &&
        ((float)(&DAT_02913bc4)[DAT_02920a9c * 0x5e] + 5.0 < _DAT_02920a90)) &&
       ((float)(&DAT_02913bc8)[DAT_02920a9c * 0x5e] != 1.0)) {
      piVar1 = &DAT_0291f7b4;
      do {
        if ((*piVar1 == DAT_02920a9c) && (*piVar1 != -1)) {
          *piVar1 = -1;
          DAT_02920a98 = DAT_02920a98 + -1;
        }
        piVar1 = piVar1 + 0x1b;
      } while ((int)piVar1 < 0x2920894);
      DAT_02920a94 = DAT_02920a94 + -1;
      (&DAT_02913a58)[DAT_02920a9c * 0x178] = 0;
      (&DAT_02913ae8)[DAT_02920a9c * 0xbc] = 0xffff;
    }
    DAT_02920a9c = DAT_02920a9c + 1;
    if (0x7f < DAT_02920a9c) {
      DAT_02920a9c = 0;
    }
  }
  return;
}

