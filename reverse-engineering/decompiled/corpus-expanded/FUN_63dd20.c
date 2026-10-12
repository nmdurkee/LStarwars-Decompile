/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63dd20; label: FUN_0063dd20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0063dd20(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076bd20;
  in_ECX[6] = param_1;
  in_ECX[7] = param_2;
  return;
}

