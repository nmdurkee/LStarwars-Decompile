/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50e980; label: FUN_0050e980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050e980(undefined4 param_1,char *param_2,short *param_3)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = param_3;
  if (*param_2 == '\0') {
    *param_3 = 0;
    return;
  }
  do {
    param_2 = (char *)FUN_004f2fd0(&param_3,param_2);
    if ((short)param_3 == 0x7e) {
      if (*param_2 == '\0') break;
      param_2 = (char *)FUN_004f2fd0(&param_3,param_2);
    }
    else {
      sVar1 = FUN_005d0b40(param_1,param_3);
      *psVar2 = sVar1;
      if (sVar1 == -1) {
        FUN_004f2fd0(&param_3,&PTR_DAT_0075f71c);
        sVar1 = FUN_005d0b40(param_1,param_3);
        *psVar2 = sVar1;
        if (sVar1 == -1) {
          sVar1 = FUN_005d0b40(param_1,0x3f);
          *psVar2 = sVar1;
        }
      }
      psVar2 = psVar2 + 1;
    }
  } while (*param_2 != '\0');
  *psVar2 = 0;
  return;
}

