/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55be20; label: FUN_0055be20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055be20(short *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (short *)0x0) {
    sVar2 = *param_1;
    while (sVar2 != -1) {
      iVar3 = FUN_00594960((int)sVar2);
      if (iVar3 != 0) {
        iVar3 = (int)*param_1;
        iVar4 = iVar3 * 0x120 + DAT_0093b284;
        if ((((((*(uint *)(iVar4 + 0x90) & param_3) == param_3) &&
              ((*(uint *)(iVar3 * 0x4c + 4 + DAT_0093b274) & param_2) == param_2)) &&
             ((param_5 == 0 || ((*(uint *)(iVar4 + 0x94) & 0x4000) == 0)))) &&
            (((param_2 & 8) == 0 || ((*(uint *)(iVar4 + 0x94) & 0x8000) == 0)))) &&
           ((param_4 == 0 || (iVar3 = FUN_0055f360(iVar3), iVar3 != 0)))) {
          return 1;
        }
      }
      psVar1 = param_1 + 2;
      param_1 = param_1 + 2;
      sVar2 = *psVar1;
    }
  }
  return 0;
}

