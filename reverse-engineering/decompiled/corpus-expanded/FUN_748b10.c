/* Ghidra pseudocode, not original source.
 * ev_80517fb4f192ecd2851e0fd4e2a7dbbf5e68bec5ed1b7e7e17e8e9bcd800f2e9
 * Entry: 0x748b10; label: FUN_00748b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748b10(char *param_1)

{
  uint in_EAX;
  
  _sprintf(param_1,"float4(%f, %f, %f, %f)",(double)(in_EAX & 0xff) / 255.0,
           (double)((int)in_EAX >> 8 & 0xff) / 255.0,(double)((int)in_EAX >> 0x10 & 0xff) / 255.0,
           (double)((int)in_EAX >> 0x18 & 0xff) / 255.0);
  return;
}

