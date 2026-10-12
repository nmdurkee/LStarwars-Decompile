/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547ab0; label: FUN_00547ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

