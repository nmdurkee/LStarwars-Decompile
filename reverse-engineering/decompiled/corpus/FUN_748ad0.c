/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748ad0; label: FUN_00748ad0
 */

void FUN_00748ad0(float param_1,float param_2,float param_3,float param_4)

{
  char *in_EAX;
  
  _sprintf(in_EAX,"float4(%f, %f, %f, %f)",(double)param_1,(double)param_2,(double)param_3,
           (double)param_4);
  return;
}

