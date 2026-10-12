/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x7452b0; label: FUN_007452b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007452b0(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + 1;
  return;
}

