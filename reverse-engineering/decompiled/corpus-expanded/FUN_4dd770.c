/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd770; label: FUN_004dd770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd770(int param_1)

{
  int iVar1;
  
  FUN_004dd480();
  if (DAT_00882a70 == 1) {
    DAT_00882410 = 2;
  }
  else if (DAT_00882a70 == 2) {
    DAT_00882410 = 5;
  }
  else if (DAT_00882a70 == 3) {
    DAT_00882410 = 8;
  }
  DAT_00882a68 = 0;
  FUN_004d8510();
  iVar1 = FUN_0057c970(*(undefined4 *)(param_1 + 0x2ab0),"ep1_podrace_avalanche");
  if (iVar1 != 0) {
    if (DAT_00882a70 == 2) {
      FUN_0057cd30(iVar1,*(undefined4 *)(param_1 + 0x2ab0),0,1);
    }
    else if (DAT_00882a70 == 3) {
      FUN_0057ce90();
      return;
    }
  }
  return;
}

