/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748aa0; label: FUN_00748aa0
 */

void FUN_00748aa0(char *param_1)

{
  float *in_EAX;
  
  _sprintf(param_1,"float2(%f, %f)",(double)*in_EAX,(double)in_EAX[1]);
  return;
}

