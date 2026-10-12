/* Ghidra pseudocode, not original source.
 * ev_c772dacde58c2298bb9853679eadc775f76d2c3f9befd22496ec5bd64ba1d43a
 * Entry: 0x580a10; label: FUN_00580a10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00580a10(int *param_1,int param_2,float *param_3,float *param_4,undefined4 param_5,
                undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  local_4 = 0;
  iVar5 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if (((((*(byte *)(iVar5 + 0x144) & 1) != 0) &&
           (((((*(uint *)(iVar5 + 0x108) & 0x8000000) != 0 ||
              (((byte)*(uint *)(iVar5 + 0x108) & 10) == 10)) &&
             (*param_3 <= *(float *)(iVar5 + 0x98))) &&
            ((*(float *)(iVar5 + 0x8c) <= *param_4 && (param_3[2] <= *(float *)(iVar5 + 0xa0)))))))
          && (*(float *)(iVar5 + 0x94) <= param_4[2])) &&
         ((param_3[1] <= *(float *)(iVar5 + 0x9c) && (*(float *)(iVar5 + 0x90) <= param_4[1])))) {
        iVar4 = 2;
        iVar3 = param_2 + 0x18;
        do {
          if ((((param_1[0x3c] & 0x200U) == 0) || (iVar4 == 1)) &&
             (iVar2 = FUN_0054fce0(iVar5 + 0x30,*(undefined4 *)(iVar5 + 0xe4),
                                   *(undefined4 *)(iVar5 + 0xe4),iVar3,param_5,param_5), iVar2 != 0)
             ) {
            (**(code **)(PTR_PTR_008040bc + 0xc))(param_1,param_2,iVar4,iVar5 + 0x80,0);
            FUN_0057fe80(param_1);
            iVar3 = param_1[1];
            if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x1fc) & 1) != 0)) {
              FUN_0054a850(**(undefined4 **)(iVar3 + 0xca4),0x3f333333,0);
            }
            *(undefined1 *)(param_1 + 0x40) = 0;
            if ((*param_1 != 0) && (pcVar1 = *(code **)(*param_1 + 0x4c), pcVar1 != (code *)0x0)) {
              (*pcVar1)(param_1);
            }
            if ((*(int *)(PTR_PTR_008040bc + 0x18) == 0) ||
               (iVar3 = (**(code **)(PTR_PTR_008040bc + 0x18))(param_1,iVar5), iVar3 != 1)) {
              FUN_0064ac90(iVar5,param_6);
            }
            return iVar5;
          }
          iVar4 = iVar4 + -1;
          iVar3 = iVar3 + -0xc;
        } while (-1 < iVar4);
      }
      local_4 = local_4 + 1;
      iVar5 = iVar5 + 0x220;
    } while (local_4 < DAT_0081020c);
  }
  return 0;
}

