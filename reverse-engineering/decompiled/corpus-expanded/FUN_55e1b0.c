/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55e1b0; label: FUN_0055e1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055e1b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_8 [2];
  
  if (((DAT_00951288 == 0) && (DAT_0093b338 == 0)) &&
     ((param_1 != 0 ||
      (((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 2) != 0 &&
       ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 100) & 0x4e0) == 0)))))) {
    local_8[0] = param_2;
    local_8[1] = param_3;
    iVar3 = 0;
    do {
      iVar1 = local_8[iVar3];
      if (((((iVar1 != -1) && ((*(uint *)(iVar1 * 0x4c + 4 + DAT_0093b274) & 0x2000) == 0)) &&
           (iVar1 != (&DAT_00802bd8)[iVar3])) &&
          ((iVar2 = FUN_00594960(iVar1), iVar2 != 0 && (iVar2 == 1)))) &&
         ((*(char *)(iVar1 * 0x120 + 0x116 + DAT_0093b284) != '\0' &&
          (iVar1 != (&DAT_00802bd8)[iVar3 - 1U & 1])))) {
        (&DAT_00802bd8)[iVar3] = iVar1;
      }
      iVar1 = DAT_00802bd8;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    if (((param_2 != param_3) && (param_2 == DAT_00802bdc)) && (param_3 == DAT_00802bd8)) {
      DAT_00802bd8 = DAT_00802bdc;
      DAT_00802bdc = iVar1;
    }
  }
  return;
}

