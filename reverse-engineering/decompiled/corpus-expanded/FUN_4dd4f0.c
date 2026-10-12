/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd4f0; label: FUN_004dd4f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd4f0(int param_1)

{
  int iVar1;
  
  FUN_004dd480();
  iVar1 = DAT_00882a70;
  if (DAT_00882a70 == 1) {
    DAT_00882410 = 3;
  }
  else if (DAT_00882a70 == 2) {
    DAT_00882410 = 6;
  }
  else if (DAT_00882a70 == 3) {
    DAT_00882410 = 9;
  }
  DAT_00882a68 = 0;
  FUN_004d8a90();
  if (((iVar1 == 3) && (DAT_00951b54 == 0)) && (DAT_00951b50 == 0)) {
    FUN_0057cd30(0,*(undefined4 *)(param_1 + 0x2ab0),"ep1_podrace_sebulba",1);
  }
  return;
}

