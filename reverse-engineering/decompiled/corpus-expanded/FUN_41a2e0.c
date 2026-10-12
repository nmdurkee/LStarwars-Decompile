/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x41a2e0; label: FUN_0041a2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0041a2e0(undefined4 param_1,float param_2,float *param_3)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  
  piVar2 = &DAT_0093d7f0;
  do {
    iVar1 = *piVar2;
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
      fVar3 = (float10)FUN_005b3c50(iVar1 + 0x80,param_1,0);
      if ((float)fVar3 < param_2) {
        if (param_3 == (float *)0x0) {
          return 1;
        }
        *param_3 = (float)fVar3;
        return 1;
      }
    }
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x93d810);
  return 0;
}

