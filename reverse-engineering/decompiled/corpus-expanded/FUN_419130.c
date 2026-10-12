/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x419130; label: FUN_00419130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00419130(void)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  
  if (*(char *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x116) == '\t') {
    pfVar2 = (float *)FUN_0062f150(in_EAX + 8,0x5e,1,0);
    if (((pfVar2 != (float *)0x0) &&
        (fVar1 = *pfVar2, !NAN(fVar1) && 18.0 < fVar1 != (fVar1 == 18.0))) && (*pfVar2 <= 65.0)) {
      if (*pfVar2 < 27.0 != (*pfVar2 == 27.0)) {
        return (float10)((*pfVar2 - 18.0) / 9.0);
      }
      if (*pfVar2 < 55.0) {
        return (float10)1;
      }
      return (float10)(1.0 - (*pfVar2 - 55.0) / 10.0);
    }
  }
  return (float10)0;
}

