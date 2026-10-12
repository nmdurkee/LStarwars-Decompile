/* Ghidra pseudocode, not original source.
 * ev_eea3a7cf55e62a15d31ae8423a3c3e3cacac13ee26e2c6e4adfc577ce8b80763
 * Entry: 0x744b40; label: FUN_00744b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00744b40(void)

{
  int *in_ECX;
  
  if (((in_ECX[3] == 0) && ((*(uint *)(*in_ECX + 0x1b8) >> 0x14 & 1) != 0)) &&
     (*(int *)(*in_ECX + 0x34) <= in_ECX[8])) {
    return 1;
  }
  return 0;
}

