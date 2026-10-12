/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e41a0; label: FUN_006e41a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e41a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))
                    (*(int **)(in_ECX + 4),param_1,param_2,param_3,param_4);
  *(int *)(in_ECX + 0x5fc) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 == -0x7789f798) {
      iVar1 = FUN_006e5850();
      if (iVar1 == -0x7789f797) {
        FUN_006e3940(1);
      }
    }
    else {
      SendMessageA(DAT_00924864,0x10,0,0);
    }
  }
  *(undefined4 *)(in_ECX + 0x6f0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6f4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6f8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6fc) = 0xffffffff;
  return;
}

