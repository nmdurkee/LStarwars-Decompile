/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748a80; label: FUN_00748a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748a80(float param_1)

{
  char *in_EAX;
  
  _sprintf(in_EAX,"%f",(double)param_1);
  return;
}

