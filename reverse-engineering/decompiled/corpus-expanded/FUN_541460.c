/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x541460; label: FUN_00541460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00541460(int *param_1,uint param_2)

{
  ushort *puVar1;
  
  if (((param_1 != (int *)0x0) && (param_2 < 0x40)) &&
     (puVar1 = (ushort *)(param_2 * 0x13c + 0x68 + *param_1),
     (*(ushort *)(param_2 * 0x13c + 0x68 + *param_1) & 0x100) == 0)) {
    *puVar1 = *puVar1 | 0x100;
  }
  return;
}

