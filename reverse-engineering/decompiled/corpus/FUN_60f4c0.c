/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60f4c0; label: FUN_0060f4c0
 */

void FUN_0060f4c0(int *param_1)

{
  int *in_ECX;
  
  *in_ECX = *in_ECX + *param_1;
  in_ECX[1] = in_ECX[1] + param_1[1];
  in_ECX[2] = in_ECX[2] + param_1[2];
  in_ECX[3] = in_ECX[3] + param_1[3];
  return;
}

