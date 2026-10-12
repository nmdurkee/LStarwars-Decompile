/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534740; label: FUN_00534740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00534740(void)

{
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (DAT_009242b8 == 0)) {
    FUN_00627bc0(1,&DAT_00801cb4,1,1,FUN_005346d0,"Reset Params");
    DAT_009242b8 = FUN_00618e10();
  }
  return;
}

