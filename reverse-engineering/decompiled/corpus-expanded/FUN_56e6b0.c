/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56e6b0; label: FUN_0056e6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e6b0(void)

{
  int in_EAX;
  
  if ((*(byte *)(in_EAX + 0x24) & 0x40) != 0) {
    FUN_0054a910(0x3f000000,0x3dcccccd,0,0);
    FUN_00549f10();
    return;
  }
  if (*(int *)(in_EAX + 8) != 0) {
    FUN_0054a8a0(**(undefined4 **)(*(int *)(in_EAX + 8) + 0xca4),0x3dcccccd,0);
  }
  return;
}

