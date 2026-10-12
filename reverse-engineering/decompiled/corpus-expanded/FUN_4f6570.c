/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f6570; label: FUN_004f6570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f6570(int param_1,int param_2,int param_3,short *param_4)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = param_2;
  iVar7 = 0;
  iVar6 = 0;
  DAT_00915fa8 = param_1;
  DAT_00916fd8 = param_2;
  DAT_00916fd4 = param_3;
  param_2 = param_1;
  DAT_0090f798 = 0;
  DAT_0090f7a2 = 0;
  if (0 < param_1) {
    do {
      *(undefined1 *)(iVar6 + param_3) = 0;
      if (*(short *)(iVar5 + iVar6 * 2) != 0) {
        iVar7 = iVar7 + 1;
        (&DAT_0090f7a0)[iVar7] = (short)iVar6;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1);
    DAT_0090f798 = iVar7;
    if (1 < iVar7) {
      for (iVar6 = iVar7 / 2; 0 < iVar6; iVar6 = iVar6 + -1) {
        FUN_004f6430();
      }
      DAT_0090fba0 = param_4;
      DAT_0090f798 = iVar7;
      iVar6 = param_2;
      do {
        param_2 = iVar6;
        sVar2 = DAT_0090f7a2;
        iVar6 = (int)DAT_0090f7a2;
        if (iVar6 < param_1) {
          *DAT_0090fba0 = DAT_0090f7a2;
          DAT_0090fba0 = DAT_0090fba0 + 1;
        }
        psVar4 = DAT_0090fba0;
        DAT_0090f7a2 = (&DAT_0090f7a0)[DAT_0090f798];
        DAT_0090f798 = DAT_0090f798 + -1;
        FUN_004f6430();
        sVar3 = DAT_0090f7a2;
        if (DAT_0090f7a2 < param_1) {
          *psVar4 = DAT_0090f7a2;
          DAT_0090fba0 = psVar4 + 1;
        }
        iVar7 = param_2 * 2;
        *(short *)(iVar7 + iVar5) =
             *(short *)(iVar5 + DAT_0090f7a2 * 2) + *(short *)(iVar5 + iVar6 * 2);
        DAT_0090f7a2 = (short)param_2;
        FUN_004f6430();
        iVar1 = DAT_0090f798;
        *(short *)(&DAT_02982740 + iVar7) = sVar2;
        *(short *)(&DAT_02982f40 + iVar7) = sVar3;
        iVar6 = param_2 + 1;
      } while (1 < iVar1);
      DAT_0090fba0 = param_4;
      FUN_004f62f0();
      FUN_004f64b0(param_1);
      return param_2;
    }
  }
  param_4[DAT_0090f7a2] = 0;
  return (int)DAT_0090f7a2;
}

