/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603aa0; label: FUN_00603aa0
 */

void FUN_00603aa0(int param_1)

{
  if (param_1 == 0) {
    PTR_PTR_0080e794 = (undefined *)&PTR_DAT_0080e6d0;
    return;
  }
  if (param_1 != 1) {
    FUN_005f7490();
    return;
  }
  PTR_PTR_0080e794 = (undefined *)&PTR_FUN_0080e798;
  return;
}

