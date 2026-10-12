/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60f500; label: FUN_0060f500
 */

void FUN_0060f500(uint *param_1)

{
  uint *in_ECX;
  uint uVar1;
  
  uVar1 = *in_ECX;
  if (*in_ECX <= *param_1) {
    uVar1 = *param_1;
  }
  *in_ECX = uVar1;
  uVar1 = in_ECX[1];
  if (in_ECX[1] <= param_1[1]) {
    uVar1 = param_1[1];
  }
  in_ECX[1] = uVar1;
  uVar1 = in_ECX[2];
  if (in_ECX[2] <= param_1[2]) {
    uVar1 = param_1[2];
  }
  in_ECX[2] = uVar1;
  if (param_1[3] < in_ECX[3]) {
    in_ECX[3] = in_ECX[3];
    return;
  }
  in_ECX[3] = param_1[3];
  return;
}

