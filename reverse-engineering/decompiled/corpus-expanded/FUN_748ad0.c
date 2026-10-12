/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748ad0; label: FUN_00748ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748ad0(float param_1,float param_2,float param_3,float param_4)

{
  char *in_EAX;
  
  _sprintf(in_EAX,"float4(%f, %f, %f, %f)",(double)param_1,(double)param_2,(double)param_3,
           (double)param_4);
  return;
}

