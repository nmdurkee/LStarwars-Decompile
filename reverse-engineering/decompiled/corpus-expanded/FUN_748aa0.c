/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748aa0; label: FUN_00748aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748aa0(char *param_1)

{
  float *in_EAX;
  
  _sprintf(param_1,"float2(%f, %f)",(double)*in_EAX,(double)in_EAX[1]);
  return;
}

