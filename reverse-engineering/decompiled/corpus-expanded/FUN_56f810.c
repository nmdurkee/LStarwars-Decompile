/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56f810; label: FUN_0056f810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056f810(undefined4 param_1,void *param_2)

{
  if (param_2 != (void *)0x0) {
    _memset((void *)((int)param_2 + 0x80),-1,0x40);
    _memset((void *)((int)param_2 + 0x40),-1,0x40);
    _memset(param_2,0,0x40);
    _memset((void *)((int)param_2 + 0xc0),0,0x40);
  }
  return;
}

