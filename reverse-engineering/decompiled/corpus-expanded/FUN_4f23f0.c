/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f23f0; label: FUN_004f23f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_004f23f0(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  
  if (*param_1 != 0) {
    iVar4 = (int)param_1 - (int)param_2;
    do {
      psVar3 = param_2;
      if (*param_2 != 0) {
        while (sVar2 = *(short *)(iVar4 + (int)psVar3), sVar2 != 0) {
          if (((ushort)(sVar2 - 0x61U) < 0x1a) || ((ushort)(sVar2 - 0xe0U) < 0x20)) {
            sVar2 = sVar2 + -0x20;
          }
          sVar1 = *psVar3;
          if (((ushort)(sVar1 - 0x61U) < 0x1a) || ((ushort)(sVar1 - 0xe0U) < 0x20)) {
            sVar1 = sVar1 + -0x20;
          }
          if (sVar2 != sVar1) break;
          psVar3 = psVar3 + 1;
          if (*psVar3 == 0) {
            return param_1;
          }
        }
      }
      if (*psVar3 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 2;
    } while (*param_1 != 0);
  }
  return (short *)0x0;
}

