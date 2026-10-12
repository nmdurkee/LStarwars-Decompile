/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x553950; label: FUN_00553950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00553950(void)

{
  int in_EAX;
  int iVar1;
  
  FUN_005cf5b0(*(undefined4 *)(in_EAX + 0x13c));
  iVar1 = FUN_005cfac0();
  if (iVar1 != 0) {
    return true;
  }
  FUN_005cf5b0(DAT_00924880);
  iVar1 = FUN_005cfac0();
  return iVar1 != 0;
}

