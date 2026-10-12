/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b420; label: FUN_0050b420
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050b420(void)

{
  int iVar1;
  
  iVar1 = FUN_0050b360();
  if (iVar1 == 0) {
    if (DAT_00921ed0 < 1) {
      return;
    }
    DAT_00921ed0 = DAT_00921ed0 + -5;
  }
  else if (DAT_00921ed0 < 0x80) {
    DAT_00921ed0 = DAT_00921ed0 + 8;
  }
  if (0 < DAT_00921ed0) {
    DAT_02854d1c = DAT_02854d1c + 1;
    FUN_00600b20(2);
    FUN_00607d70(0x10,5,DAT_00921d8c);
    FUN_00508f70();
    FUN_006009e0(0,0,0);
    FUN_00508f70();
    FUN_006009e0(0x3f800000,0x3f800000,0);
    FUN_006009a0();
    iVar1 = DAT_02854d1c * 4;
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar1));
  }
  return;
}

