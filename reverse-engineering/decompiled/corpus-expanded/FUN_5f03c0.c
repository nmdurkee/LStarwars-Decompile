/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f03c0; label: FUN_005f03c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f03c0(void)

{
  int iVar1;
  
  FUN_005dece0();
  if (DAT_00973ed0 == 0) {
    FUN_005efff0();
  }
  iVar1 = 0;
  if (0 < DAT_00973ed0) {
    do {
      FUN_005f02e0(iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00973ed0);
  }
  if (DAT_00973fc4 != 0) {
    FUN_005d7230("<table   width=100%c height=20 bgcolor=#FF0000><tr><td><font face=arial size=+2></font></table>"
                 ,0x25);
    FUN_004f0750(DAT_00973968,&DAT_009720b8);
    DAT_0096e574 = &DAT_009720b8;
    DAT_00971890 = &DAT_00972cb8;
    DAT_00973968 = 0;
    FUN_004f99e0(DAT_0096d938);
    DAT_00973fc4 = 0;
  }
  return;
}

