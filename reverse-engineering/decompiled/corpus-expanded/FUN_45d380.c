/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45d380; label: FUN_0045d380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045d380(int param_1,int param_2)

{
  if ((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) {
    **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
  }
  if ((*(int *)(param_1 + 0xc) == 0x17) && (*(char *)(param_2 + 0xa6) == '\x02')) {
    **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
  }
  FUN_004838f0(param_2);
  return;
}

