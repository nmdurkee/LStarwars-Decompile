/* Ghidra pseudocode, not original source.
 * ev_8e73b717ff009f07746f1c65dd4e3482676ea3fff3015cb29c9ed201b1c71a72
 * Entry: 0x54a850; label: FUN_0054a850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054a850(int param_1)

{
  int iVar1;
  float10 extraout_ST0;
  
  if (param_1 != 0) {
    iVar1 = FUN_006e6b90();
    if (0xff < iVar1) {
      iVar1 = 0xff;
    }
    FUN_00698900(param_1,0,iVar1,0,(float)extraout_ST0);
  }
  return;
}

