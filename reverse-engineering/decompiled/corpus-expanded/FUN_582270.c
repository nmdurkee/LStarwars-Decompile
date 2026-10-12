/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x582270; label: FUN_00582270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00582270(int param_1,undefined4 param_2,float *param_3,float *param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  local_4 = 0;
  iVar2 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((((((*(uint *)(iVar2 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar2 + 0x1fc) & 0x1000) != 0))
              && (*(char *)(iVar2 + 0x28b) == '\0')) &&
             ((iVar1 = *(int *)(param_1 + 4), iVar2 != iVar1 &&
              ((*(byte *)(iVar2 + 0xe20) & 0x20) == 0)))) &&
            ((iVar1 == 0 || ((*(int *)(iVar1 + 0xcd0) == 0 || (iVar2 != *(int *)(iVar1 + 0xcd0))))))
            ) && ((-1 < (char)*(uint *)(param_1 + 0xf0) ||
                  ((*(char *)(iVar2 + 0x280) != -1 ||
                   ((*(int *)(iVar2 + 0xcd0) != 0 &&
                    (*(char *)(*(int *)(iVar2 + 0xcd0) + 0x280) != -1)))))))) &&
          (((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(iVar2 + 0x7b5) * 0x10 + 8) & 0x8080) == 0 &&
           (((*(uint *)(iVar2 + 0xe24) & 0x8000) == 0 &&
            ((((DAT_00951288 == 0 || (DAT_00951154 != 0)) || (iVar1 == 0)) ||
             ((*(char *)(iVar1 + 0x280) == -1 || (*(char *)(iVar2 + 0x280) == -1)))))))))) &&
         (((((((*(uint *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x90) & 0x8000) == 0 &&
              ((*param_3 <= *(float *)(iVar2 + 0x184) && (*(float *)(iVar2 + 0x178) <= *param_4))))
             && (param_3[2] <= *(float *)(iVar2 + 0x18c))) &&
            (*(float *)(iVar2 + 0x180) <= param_4[2])) &&
           (((*(uint *)(param_1 + 0xf0) & 0x8000000) != 0 ||
            ((param_3[1] <= *(float *)(iVar2 + 0x188) && (*(float *)(iVar2 + 0x17c) <= param_4[1])))
            ))) && (iVar1 = FUN_00581fb0(param_1,iVar2,param_2,param_3,param_4,param_5,param_6),
                   iVar1 != 0)))) {
        return 1;
      }
      local_4 = local_4 + 1;
      iVar2 = iVar2 + 0x10d8;
    } while (local_4 < DAT_0093d500);
  }
  return 0;
}

