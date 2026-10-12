/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50c050; label: FUN_0050c050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050c050(char *param_1,short *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  short sVar2;
  short *psVar3;
  
  uVar1 = param_3;
  psVar3 = param_2;
  if (*param_1 == '\0') {
    *param_2 = 0;
    return;
  }
  do {
    param_1 = (char *)FUN_004f2fd0(&param_2,param_1);
    if ((short)param_2 == 0x7e) {
      if (*param_1 == '\0') break;
      param_1 = (char *)FUN_004f2fd0(&param_2,param_1);
    }
    else {
      sVar2 = FUN_005d0b40(uVar1,param_2);
      *psVar3 = sVar2;
      if (sVar2 == -1) {
        FUN_004f2fd0(&param_2,&PTR_DAT_0075f71c);
        sVar2 = FUN_005d0b40(uVar1,param_2);
        *psVar3 = sVar2;
        if (sVar2 == -1) {
          sVar2 = FUN_005d0b40(uVar1,0x3f);
          *psVar3 = sVar2;
        }
      }
      psVar3 = psVar3 + 1;
    }
  } while (*param_1 != '\0');
  *psVar3 = 0;
  return;
}

