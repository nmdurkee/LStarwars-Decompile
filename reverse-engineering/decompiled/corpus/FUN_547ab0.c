/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547ab0; label: FUN_00547ab0
 */

float10 FUN_00547ab0(float param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)((int)param_1 + 6);
  param_1 = ((float)*(byte *)((int)param_1 + 4) / 10.0) *
            ((float)*(byte *)((int)param_1 + 5) / 10.0);
  if ((*pcVar1 == '\0') && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88)) {
    param_1 = 0.0;
  }
  FUN_00694db0(0x23,param_1);
  return (float10)param_1;
}

