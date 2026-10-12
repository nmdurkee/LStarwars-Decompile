/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x5499b0; label: FUN_005499b0
 */

void FUN_005499b0(float *param_1,float *param_2)

{
  float *in_EAX;
  float *in_ECX;
  float *unaff_EDI;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  *param_1 = (*param_2 + *in_EAX + *unaff_EDI + *in_ECX) * 0.25;
  param_1[1] = (param_2[1] + in_EAX[1] + unaff_EDI[1] + in_ECX[1]) * 0.25;
  param_1[2] = (param_2[2] + in_EAX[2] + unaff_EDI[2] + in_ECX[2]) * 0.25;
  FUN_005b3800(local_c);
  FUN_005b3800(local_18);
  param_1 = param_1 + 3;
  FUN_005b3920(param_1,local_c,local_18);
  FUN_005b3b30(param_1,param_1);
  return;
}

