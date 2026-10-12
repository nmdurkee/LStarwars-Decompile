/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x748b10; label: FUN_00748b10
 */

void FUN_00748b10(char *param_1)

{
  uint in_EAX;
  
  _sprintf(param_1,"float4(%f, %f, %f, %f)",(double)(in_EAX & 0xff) / 255.0,
           (double)((int)in_EAX >> 8 & 0xff) / 255.0,(double)((int)in_EAX >> 0x10 & 0xff) / 255.0,
           (double)((int)in_EAX >> 0x18 & 0xff) / 255.0);
  return;
}

