/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f7610; label: FUN_005f7610
 */

void FUN_005f7610(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  
  *in_ECX = *in_EAX;
  uVar1 = in_EAX[1];
  in_ECX[1] = in_EAX[4];
  in_ECX[4] = uVar1;
  uVar1 = in_EAX[2];
  in_ECX[2] = in_EAX[8];
  in_ECX[8] = uVar1;
  uVar1 = in_EAX[3];
  in_ECX[3] = in_EAX[0xc];
  in_ECX[0xc] = uVar1;
  in_ECX[5] = in_EAX[5];
  uVar1 = in_EAX[6];
  in_ECX[6] = in_EAX[9];
  in_ECX[9] = uVar1;
  uVar1 = in_EAX[7];
  in_ECX[7] = in_EAX[0xd];
  in_ECX[0xd] = uVar1;
  in_ECX[10] = in_EAX[10];
  uVar1 = in_EAX[0xb];
  in_ECX[0xb] = in_EAX[0xe];
  in_ECX[0xe] = uVar1;
  in_ECX[0xf] = in_EAX[0xf];
  return;
}

